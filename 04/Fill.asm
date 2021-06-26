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

@SCREEN   // 16384
D=A       // D=16384
@Position
M=D       // Memory[Position] = 16384

(CHECK)
@KBD      // 24576
D=M       // d = keyboard input
@BLACKEN
D;JGT     // goto blacken if input > 0
@WHITEN
0;JMP     // go to whiten

(BLACKEN)
@KBD
D=M
@Position
D=D-M
@CHECK
D;JEQ     // goto CHECK if position is at max of the screen
@Position
A=M
M=-1      // blacken

@Position
D=M+1     // go to next position
@Position
M=D

@CHECK
0;JMP

(WHITEN)
@SCREEN
D=A
@Position
D=D-M
@CHECK
D;JEQ

@Position
M=0

@Position
D=M-1
@Position
M=D
@CHECK
0;JMP
