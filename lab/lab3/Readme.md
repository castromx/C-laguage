# Report on Completed Tasks

## Laboratory Work No. 3

## Objective
The goal of this project is to create a C program that takes a positive number `x` (less than or equal to 1.5) as input from the keyboard and computes the sum of a descending series `R` with a precision of `ε = 10^-4`. The program considers only the initial terms of the series that are greater than `ε`.

## Steps Undertaken

1. **Input Validation**
   - The program prompts the user to enter a positive number `x` that does not exceed 1.5.
   - It checks if the input value is within the acceptable range. If the value is invalid, an error message is displayed, and the program exits.

2. **Algorithm Development**
   - An algorithm was designed to calculate the sum `R` of the descending series.
   - The series is defined as follows:
     \[
     R = x - \frac{x^2}{2} + \frac{x^3}{3} - \frac{x^4}{4} + \cdots
     \]
   - The algorithm continues to add terms to `R` until the absolute value of the next term is less than `ε`.
