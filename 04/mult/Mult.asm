// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

@sum
M=0 // sum=0
@i
M=1 // i=1
(LOOP)
@i
D=M // D=i
@R0
D=D-M // D=i-R0
@END
D;JGT // if(D>0) goto END
@R1
D=M // D=R1
@sum
M=D+M // sum+=D
@i
M=M+1 // i+=1
@LOOP
0;JMP // goto LOOP
(END)
@sum
D=M // D=sum
@R2
M=D // R2=sum
