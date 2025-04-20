# CMSC-313-HW-8

AUTHORING: Author of the code - Samantha Shedwick UMBC/CMSC 313 Class Time - 14:30 Class dates - Monday & Wednesday

PURPOSE OF SOFTWARE: The purpose of this software is to calculate the linear algebra matrix math of matrix D, where D = A + (3 * B) * C^T. It includes both a version using the C++ and C languages, with C using the C99 standard.

FILES: 
Matrix_Functions.cpp - This file makes a Matrix class that can use Matrix addition, Scalar multiplication, Matrix multiplication, and Matrix Transposing. It makes 3 matricies, A, B, and C, and prints out A, B, C, 3 * Matrix B, C^T, (3 * Matrix B) * C^T, and A + ((3 * Matrix B) * C^T). It then tests each function to verify they work. Includes no extra files or libraries to run.
Matrix_Functions.c - This file makes makes 3 matricies, A, B, and C. It then performs scalar multiplication on matrix B, performs matrix transposing to make matrix C transpose or C^T, performs matrix multiplication between matrix B and matrix C^T, and performs matrix addition between matrix A and matrix B. It prints out each matrix, printing matricies A, B, C, 3 * Matrix B, C^T,(3 * Matrix B) * C^T, and A + ((3 * Matrix B) * C^T).Includes no extra files or libraries to run.

BUILD INSTRUCTIONS: Download and compile each file using gcc.

TESTING METHODOLOGY: Matrix_Functions.cpp runs its own tests on each functions, and each file prints out the matrix after each operation. This should help test whether or not the matrix is correct.
