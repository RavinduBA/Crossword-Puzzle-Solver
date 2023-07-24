

# Welcome to the Crossword-Puzzle-Solver Wiki!

## Table of Contents

- [Introduction](#Introduction)
- [Specification](#Specification)
- [Output](#Output)
- [Phase ](#Phase)


## Introduction

This is a C program to solve a crossword puzzle. This program should read, fromstandard input, a puzzle grid and a set of words and should print the solved puzzle to standard output. 

## Specification

A partially filled puzzle grid will be given in the input with stars, hashes and letters. Stars indicateblocked cells (cannot be filled). Hashes indicate vacant cells needed to be filled with letters. The inputswill also include the words to be used, one per line, in random order. If  program finds out thatfilling the crossword puzzle is impossible with the given words, it prints IMPOSSIBLE.
Input:
The grid is followed by an empty line and a list of words, one per line. To finish giving words, an empty
line is provided.
Output:
The completed puzzle, the message “IMPOSSIBLE” or “INVALID INPUT”. 

## Output

The completed puzzle, the message “IMPOSSIBLE” or “INVALID INPUT”.
For example,
./puzzle
*#**
####
*#**
****
FLY
GLUE
*F**
GLUE
*Y**
**** 

 Most testing will be on legal input;however,this  program may be tested on invalid input. When it determine its invalid input, it prints“INVALID INPUT”. 

## Phase
Phase I - Static memory allocation of arrays
Static Memory allocation in C allocates size and location to a variable 
that is fixed. The memory is allocated at the compile time (before the program is executed), it is known as compile time allocation. It uses a stack data structure. So, it will remain from the beginning to end of the program. The execution time is efficiently controlled. This memory 
allocation is easy to use but it is less efficient than dynamic memory allocation.

Phase II - Dynamic memory allocation
Dynamic memory allocation is preferred in the linked list. The memory 
is allocated in the execution or run time. In dynamic memory allocation, 
it performs memory allocation manually by programmer. Memory is 
allocated on heap, non-static and local variables get memory allocated 
on Stack. Also it is very flexible. Programmers are free to allocate and 
deallocate memory whenever they need. If programmer doesn’t 
deallocate memory, it causes memory leak. This memory allocation is a 
bit complicated but it is more efficient than static memory allocation
