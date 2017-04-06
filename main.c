//
//  main.c
//  project2_BRF.c
//
//  Created by Brandon Figueredo on 4/1/17.
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

void dumpAll(int size, int PC, int IR, int A, int* nPtr);
void testInstruction(int arr);
void testAddress(int arr, int i, int size);
int executeInstruction(int size, int instructionRegister, int opCode, int address, int* n, int i, int accumulator, int programCounter);



int main() {
    
    
    //initialize all variables
    int size;
    int programCounter = 0;
    int instructionRegister = 0;
    int accumulator = 0;
    int opCode = 0;
    int address = 0;
    int *n;
    //int *accPtr;
    
    puts("\t\t\tWelcome to Simpletron Simulator!");
    puts("The computer will ask for a memory amount. Then the computer will present a memory location followed by a question mark. You will enter the instruction for that memory location.\n");
    
    puts("Firstly, enter amount of memory space for array:");
    scanf("%d", &size);
    
    //dynamically set array size at runtime
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
    
    for (int i = 0; i < size; i++) {
        
        programCounter = i;

        
        printf(">%.3d? ", i);
        scanf("%d", (n + i) );
        
        if ( *(n + i) >= 999999) {
            puts("\nError: Instruction to large!\n");
            instructionRegister = *(n + i);
            dumpAll(size, programCounter, instructionRegister, accumulator, n);
            break;
        }
        
        if (i < size) {
            testInstruction( *(n + i) );
            testAddress( *(n + i), i , size);
        }
        
        
        //after testing take execute the
        accumulator = executeInstruction(size, instructionRegister, opCode, address, n, i, accumulator, programCounter);
    
    }
    
    //free memory
    free(n);
    
    return 0;
}

//test whether the instruction is valid
void testInstruction(int arr)
{
    
    if ( ( (arr / 1000) == READ) || ( (arr / 1000) == WRITE) || ( (arr / 1000) == LOAD) || ( (arr / 1000) == STORE) || ( (arr / 1000) == ADD) || ( (arr / 1000) == SUBTRACT) || ( (arr / 1000) == MULTIPLY) || ( (arr / 1000) == DIVIDE) || ( (arr / 1000) == BRANCH) || ( (arr / 1000) == BRANCHNEG) || ( (arr / 1000) == BRANCHZERO) || ( (arr / 1000) == HALT) )  {
        
        //do nothing
        
        } else {
        puts("\nError: Invalid instruction or improper address!");
        exit(0);
    }
}

void testAddress(int arr, int i, int size)
{
    if ( ( (arr % 1000) > (size % 1000) ) ) {
        puts("\nError: Invalid instruction or improper address!");
        exit(0);
    } else {
        //do nothing
    }
}


int executeInstruction(int size, int instructionRegister, int opCode, int address, int* n, int i, int accumulator, int programCounter)
{
    //set instructionRegister to each element in array
    instructionRegister = *(n + i);
    
    //create opCode and memory address
    opCode = (instructionRegister / 1000);
    address = (instructionRegister % 1000);
    
    //DELETE PRINTS STATEMENTS IN EACH CASE (THEY JUST TEST THE ACCUMULATOR!)
    switch (opCode) {
        case READ:
            puts("Enter a number to store in memory location:");
            scanf("%d", (n + address) );
            break;
        case WRITE:
            printf("%d\n", *(n + address) );
            break;
        case LOAD:
            accumulator = *(n + address);
            printf("%d", accumulator);
            break;
        case STORE:
            *(n + address) = accumulator;
            printf("%d", *(n + address) );
            break;
        case ADD:
            accumulator += *(n + address);
            printf("%d", accumulator);
            break;
        case SUBTRACT:
            accumulator -= *(n + address);
            printf("%d", accumulator);
            break;
        case MULTIPLY:
            accumulator *= *(n + address);
            printf("%d", accumulator);
            break;
        case DIVIDE:
            accumulator /= *(n + address);
            printf("%d", accumulator);
            break;
        case BRANCH:
            *(n + address) = (programCounter % 100000);
            break;
        case BRANCHNEG:
            if (accumulator < 0) {
                *(n + address) = (programCounter % 100000);
            }
            break;
        case BRANCHZERO:
            if (accumulator == 0) {
                *(n + address) = (programCounter % 100000);
            }
            break;
        case HALT:
            puts("Stopping program!\n");
            dumpAll(size, programCounter, instructionRegister, accumulator, n);
            break;
        default:
            break;
    }
    return accumulator;
}


//dump function
void dumpAll(int size, int PC, int IR, int A, int* nPtr)
{
    
    puts("Dumping memory:");
    printf("Program Counter: %d\n", PC);
    printf("Instruction Register: %d\n", IR);
    printf("Accumulator: %d\n", A);
    puts("*****************\n\n");
    
    for (int i = 0; i < size; i++)
    {
        printf("%.3d: ", i);
        
        if ( *(nPtr + i) < 44000 && *(nPtr + i) > 0) {
            printf("%d\n", *(nPtr + i) );
        } else {
            puts("00000");
        }
    }
    
    puts("\n");
    exit(0);
}


