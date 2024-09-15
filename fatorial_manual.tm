0: IN 0, 0, 0      # t1 = input()
1: LDC 1, 1 (0)    # t2 = 1 (resposta)
2: LDC 2, 8 (0)    # t3 = 8
3: JEQ 0, 0 (2)    # if (t1 == 0) : pulo pro print
4: MUL 1, 1, 0     # t2 = t2 * t1
5: LDC 2, 1 (0)    # t3 = 1
6: SUB 0, 0, 2     # t1 = t1 - t3 (subtraio um da entrada)
7: LDC 7, 2 (0)    # pc = 2
8: OUT 1, 0, 0     # print(t2)
9: HALT 0, 0, 0    # return 0