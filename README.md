
# Welcome to the Crossword-Puzzle-Solver Wiki!

## Table of Contents

- [Introduction](#Introduction)
- [Specification](#Specification)
- [Output](#Output)
- [Phase ](#Phase)


## <a name="Introduction"></a> Introduction

This is a C program to solve a crossword puzzle. This program should read, from standard input, a puzzle grid and a set of words and should print the solved puzzle to standard output. 

## <a name="Specification"></a> Specification

A partially filled puzzle grid will be given in the input with stars, hashes, and letters. Stars indicate blocked cells (cannot be filled). Hashes indicate vacant cells needed to be filled with letters. The inputs will also include the words to be used, one per line, in random order. If  the program finds out that filling the crossword puzzle is impossible with the given words, it prints IMPOSSIBLE.
Input:
The grid is followed by an empty line and a list of words, one per line. To finish giving words, an empty
the line is provided.
Output:
The completed puzzle, the message “IMPOSSIBLE” or “INVALID INPUT”. 

## <a name="Output"></a> Output

The completed puzzle, the message “IMPOSSIBLE” or “INVALID INPUT” for invalid inputs
 Most testing will be on legal input; however, this  program may be tested on invalid input. When it determines its invalid input, it prints“INVALID INPUT”. 

## <a name="Phase"></a> Phase

**Phase I - Static memory allocation of array** <br>
Static Memory allocation in C allocates size and location to a variable 
that is fixed. The memory is allocated at the compile time (before the program is executed), it is known as compile time allocation. It uses a stack data structure. So, it will remain from the beginning to the end of the program. The execution time is efficiently controlled. This memory 
allocation is easy to use but it is less efficient than dynamic memory allocation.

**Phase II - Dynamic memory allocation** <br>
Dynamic memory allocation is preferred in the linked list. The memory 
is allocated in the execution or run time. In dynamic memory allocation, 
it performs memory allocation manually by the programmer. Memory is 
allocated on the heap, and non-static and local variables get memory allocated 
on Stack. Also, it is very flexible. Programmers are free to allocate and 
deallocate memory whenever they need it. If the programmer doesn’t 
deallocate memory, it causes a memory leak. This memory allocation is a 
bit complicated but it is more efficient than static memory allocation
