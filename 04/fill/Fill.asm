// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
// R0 tracks the index for white pixels
@R0
M=0         // R0 = 0

// R1 tracks the index for black pixels
@R1
M=0         // R1 = 0

// Store end of screen address
@KBD
D=A-1
@SCREEN
D=D-A
@end_screen 
M=D

(LOOP)
  @KBD
  D=M       // D = KBD
  @BLACKEN
  D;JGT     // if D > 0 goto BLACKEN (key is pressed)
  
(WHITEN)
  @R1
  M=0       // clear black index counter
  @R0
  D=M       // retrieve current white pixel position
  @end_screen
  D=D-M     // check if end of screen reached
  @LOOP
  D;JGE
  @R0
  D=M
  @SCREEN
  A=A+D     // @SCREEN + 1 = 0 (render white pixel)
  M=0
  @R0
  M=M+1
  
  @LOOP
  0;JMP

(BLACKEN)
  @R0
  M=0       // clear white index counter
  @R1
  D=M
  @end_screen
  D=D-M
  @LOOP
  D;JGE
  @R1
  D=M
  @SCREEN
  A=A+D     // @SCREEN + 1 = 1 (render black pixel
  M=1
  @R1
  M=M+1

  @LOOP
  0;JMP

(END)
  @END
  0;JMP

