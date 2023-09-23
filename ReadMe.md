#README

## Problem 
The goal of this algorithm is to solve the "Towers of Hanoi" problem given a graph, G(V, E), with edges, E = {(Start, Dest), (Dest, A1), (A1, Dest), (A1, A2), (A2, A1), (A2, A3), (A3, A2)},
and Vertices, V = {Start, A1, A2, A3, Dest}.

* Design an algorithm and determine the time and space complexities of moving n disks from Start to Dest.
* Implement this algorithm whereby your program prints out each of the moves of every disk. Show the output for n = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10. (If the output is too long, print out only the first 100 and last 100 moves)

## Solution

#### Input
We will take an input of an integer which will represent how many disks will be on the starting peg. 

#### Assumptions 
n is a number greater than or equal to 1. Disks can only move across pegs according to the edges array. For example, a disk can not jump from A1 to A3 without moving through A2 as there is no (A1, A3) edge. Disks are also not allowed to be placed on top of a smaller disk. For example, disk 2 can not be placed on top of disk 1. 

#### Time Complexity
The main function has 2 recursive calls, moving n - 1 disks from Start to A3, then moving the disks from A3 to Dest. Each of these functions have 3 recursive calls and the decrement amount is 1, r = 3, d = 1. Thus, using Masters Theorem for decreasing recursive functions, [Masters Theorem](https://www.scaler.com/topics/data-structures/masters-theorem/), the time complexity will be of the order r<sup>n/d</sup>. 
The time complexity is O(3<sup>n</sup>).

#### Space Complexity
Since we are calling the recursive functions for each disk, the space complexity will be of the order n. 
Space Complexity is O(n).

#### Output
The output for the first 10 disks (n := 1 to 10) can be found in the output file.

## References
The format for this page was based off this [github page](https://github.com/hectorrami/Tower-of-Hanoi/blob/master/README.md), it is also question of simular format. Masters Theorem: [Masters Theorem](https://www.scaler.com/topics/data-structures/masters-theorem/). 
