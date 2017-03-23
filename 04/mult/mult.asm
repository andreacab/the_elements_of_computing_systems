// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
// R0 - Operand 1
// R1 - Operand 2
// R2 - Reslult of multiplication of R0 by R1 (R2 = R0 x R1)
// Put your code here.

// Nullify R2
@R2
M=0     // R2 = 0

// R0 null check
@R0
D=M     // D = R0
@END
D;JEQ   // if D == 0 goto END

// Main loop
(LOOP)
  @R1
  D=M   // D = R1
  @END
  D;JEQ // if D == 0 goto END

  @R0
  D=M   // D = R0
  @R2
  M=M+D // R2 = R2 + D 

  @R1
  M=M-1 // R1 = R1 - 1
  
  @LOOP
  0;JMP
  
(END)
  @END
  0;JMP  
