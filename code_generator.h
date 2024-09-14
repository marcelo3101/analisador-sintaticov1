#include <stdio.h>

enum code_ops
{
  HALT,
  IN, // TODO
  OUT,
  ADD,
  SUB,
  MUL,
  DIV,
  LD,
  LDA,
  LDC,
  ST,
  JLT,
  JLE,
  JGE,
  JGT,
  JEQ,
  JNE,
};

/* OPERATIONS: External Representation */
char *op_name[] = {
    "HALT",
    "IN",
    "OUT",
    "ADD",
    "SUB",
    "MUL",
    "DIV",
    "LD",
    "LDA",
    "LDC",
    "ST",
    "JLT",
    "JLE",
    "JGE",
    "JGT",
    "JEQ",
    "JNE",
};

struct instruction
{
  enum code_ops op;
  int arg[3];
};

// Array for the code
struct instruction code[999]; // each ele is an instruction("line")

// Registers

enum Regs
{
  t1,
  t2,
  t3,
  r1,
  r2,
  sp,
  mp,
  pc,
};

int data_offset = 0;
int code_offset = 0;

int data_location()
{
  return data_offset++;
}

int get_code_offset()
{
  return code_offset;
}

int add_code_offset()
{
  return code_offset++;
}

void gen_code(enum code_ops operation, int arg0, int arg1, int arg2)
{
  code[code_offset].op = operation;
  code[code_offset].arg[0] = arg0;
  code[code_offset].arg[1] = arg1;
  code[code_offset].arg[2] = arg2;
  code_offset++; // proximo codigo
}

// nossa estrutura de instrução
void make_code(int addr, enum code_ops operation, int arg0, int arg1, int arg2)
{
  code[addr].op = operation;
  code[addr].arg[0] = arg0;
  code[addr].arg[1] = arg1;
  code[addr].arg[2] = arg2;
}

// pop stack and put value in t1
void pop() {
  gen_code(LD, t1, 0, sp); 
  gen_code(LDA, sp, 1, sp); 
}

// push t1 to stack
void push() {
  gen_code(LDA, sp, -1, sp); // sp aponta pra ultima posicao que tem alguem
  gen_code(ST, t1, 0, sp); 
}

// copy register operation
void copy(enum Regs from, enum Regs to)
{
  gen_code(LDA, to, 0, from);
}

// zerar a pilha
void initializeProgram() {

  // sp = dMem[0] (t1 comeca com 0)
  gen_code(LD, sp, t1, 0);
  gen_code(LDC, t1, data_offset, 0);
  gen_code(SUB, sp, sp, t1);

  // gen_code(LDC, sp, data_offset, 0);
}

// arithmetic operation
void ari_op(enum code_ops op)
{
  pop();
  copy(t1, t2);
  pop();
  gen_code(op, t1, t1, t2);
  push();
}

void print_code()
{
  int i = 0;
  while (i < code_offset)
  {
    if ((int)code[i].op <= DIV) // após DIV, é RM, ou seja, 2 argumentos
    {
      // RO - opcode r,s,t
      printf("%3d: %-5s %d, %d, %d\n", i, op_name[(int)code[i].op], code[i].arg[0], code[i].arg[1], code[i].arg[2]);
    }
    else
    {
      // RM - opcode r,d(s)
      printf("%3d: %-5s %d, %d (%d)\n", i, op_name[(int)code[i].op], code[i].arg[0], code[i].arg[1], code[i].arg[2]);
    }
    i++;
  }
}
