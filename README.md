# Magic Cube Problem

Magic cube is a cube(M*M*M) which contains an integer number(0 <= number < P) in each cell(So you know there are M ^ 3 numbers). 

Alice has one big cube and N smaller cubes (each small cube is uniqe).

The cube is magic since when you put a small cube in bigger one, the number in the same location add up and mod P.

Your job is to determine the location of each small cube, so that we can make every number in big cube equal 0 after putting all the small cubes.

Notice:

We guarantee there is only one solution.

You cannot rotate the cube.

We give the numbers in cubes in order of position [0,0,0],[0,0,01],...,[0.1,0],...,[1,0,0],...

Limits

Memory limit per test: 256 MB

C++/Java

Input

The first line is three integers M ( 2<= M<=7), N ( 1<= N<=12), P (3 <= P <=5) Second line is M*M*M integers, showing the numbers in big cube. Then is N lines, in which first is an integer L[i](1 <= L[i] < M) shows the length of the small cube, then follows L[i] ^ 3 numbers(0 <= number < P).

Output

Output N lines of triad of integers that shows the location of this small cube.

Sample Test

Input:

2 1 3

1 0 0 0 0 0 0 0 

1 2

Output

0 0 0
