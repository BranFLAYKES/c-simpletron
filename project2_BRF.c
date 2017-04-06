//
//  main.c
//  project2_BRF.c
//
//  Created by Brandon Figueredo on 3/23/17.
//  Copyright © 2017 Brandon Figueredo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define MULTIPLY 32
#define DIVIDE 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43



int main(int argc, const char * argv[]) {
    
    int size;
    int programCounter = 0;
    int instructionRegister = 0;
    int accumulator = 0;
    int opCode = 0;
    int address = 0;
    int *n;
    
    puts("\t\t\tWelcome to Simpletron Simulator!");
    puts("The computer will ask for a memory amount. Then the computer will present a memory location followed by a question mark. You will enter the instruction for that memory location.\n");
    
    
    puts("Firstly, enter amount of memory space for array:");
    scanf("%d", &size);
    
    n = (int*)malloc(size * sizeof(int));
    
    puts("\n\nEnter instructions.");
    puts("A list of instruction that can be used are:");
    puts("      READ: 10");
    puts("     WRITE: 11");
    puts("      LOAD: 20");
    puts("     STORE: 21");
    puts("       ADD: 30");
    puts("  SUBTRACT: 31");
    puts("  MULTIPLY: 32");
    puts("    DIVIDE: 33");
    puts("    BRANCH: 40");
    puts(" BRANCHNEG: 41");
    puts("BRANCHZERO: 42");
    puts("      HALT: 43");
    
    
    //write loop that stores instructions (instructionRegister) to array
    scanf("%d", &n[);
    
    
    
    
    return 0;
}

//dump function
void dumpAll(int PC, int IR, int A, int Mem[])
{
    printf("Program Counter: %d", PC);
    printf("Instruction Register: %d", IR);
    printf("Accumulator: %d", A);
    printf("Memory: %d", Mem[]);
    
}

//function that determines operation
{
    
}
