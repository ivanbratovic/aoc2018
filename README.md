# Advent of Code 2018
### *by Ivan Bratović*
***
Advent of Code 2018 repository for all puzzles.

Will use any programming language I feel like, so beware.
Each puzzle description will start with the programming language used, at least that's the plan.
Writing this before AoC starts, I predict I'll use C++, Python, Java and R most often.

***
# Puzzle 1
*Programming language used:* **C++**

*Puzzle description:* This first one is rather simple, and boils down into a parsing problem.
You are given a list of numbers, prefixed by a unary operator, either a `+` or a `-`. The puzzle was split into two parts:

1. The first part was to find the sum of all the numbers (or the 'frequency') in the input list.
2. The second part was a little bit more complicated, as it involved looping the input list, and adding and
and subtracting the numbers (just like in the 1st part) but keep doing so until a given partial sum was reached
twice.

***
# Puzzle 2
*Programming language used:* **R**

*Puzzle description:* The second puzzle involves handling a list of 250 16-character IDs and analyzing the frequency of the lettes in it, as well as checking for common letters. I chose R for this one because I was really feeling it while reading the 1st part. Not so much for the second, but eh! The details of the two parts:

1. The first part involved counting the frequency of given letters in each ID and calculating a checksum based on the number of IDs that have letters appearing exactly 2 or 3 times. The checksum involves multiplying the number of IDs that have any letter appearing exactly 2 times by the number of IDs that have any letter appearing exactly 3 times.
2. The second part of the puzzle was to find two IDs that have the most common characters in the same position.

***
# Puzzle 3
*Programming language used:* **C**

*Puzzle description:* The third puzzle involves reading a list of *claims* (rectangular pieces of fabric) and arranging them in a 1000x1000 field, given their coordinates and dimensions. I represented the field as an array of integers, with cell values being IDs of claims, with special values: `0` meaning the cell is not claimed, and `9999` meaning the cell is claimed more than once.

1. The first part was to count all the cells in the field that are claimed more than once. This was easy enough, simply counting the number of cells in the array with `9999` as their value.
2. The second part was to find the only claim in the field that is intact in its entirety. I optimised this procedure by checking only claims that when added (as in the 1st part) did not intersect any other claims.

***
# Puzzle 4
*Programming language used:*

*Puzzle description:*

***
# Puzzle 5
*Programming language used:*

*Puzzle description:*

***
# Puzzle 6
*Programming language used:*

*Puzzle description:*

***
# Puzzle 7
*Programming language used:*

*Puzzle description:*

***
# Puzzle 8
*Programming language used:*

*Puzzle description:*

***
# Puzzle 9
*Programming language used:*

*Puzzle description:*

***
# Puzzle 10
*Programming language used:*

*Puzzle description:*

***
# Puzzle 11
*Programming language used:*

*Puzzle description:*

***
# Puzzle 12
*Programming language used:*

*Puzzle description:*

***
# Puzzle 13
*Programming language used:*

*Puzzle description:*

***
# Puzzle 14
*Programming language used:*

*Puzzle description:*

***
# Puzzle 15
*Programming language used:*

*Puzzle description:*

***
# Puzzle 16
*Programming language used:*

*Puzzle description:*

***
# Puzzle 17
*Programming language used:*

*Puzzle description:*

***
# Puzzle 18
*Programming language used:*

*Puzzle description:*

***
# Puzzle 19
*Programming language used:*

*Puzzle description:*

***
# Puzzle 20
*Programming language used:*
*Puzzle description:*

***
# Puzzle 21
*Programming language used:*

*Puzzle description:*

***
# Puzzle 22
*Programming language used:*

*Puzzle description:*

***
# Puzzle 23
*Programming language used:*

*Puzzle description:*

***
# Puzzle 24
*Programming language used:*

*Puzzle description:*

***
# Puzzle 25
*Programming language used:*

*Puzzle description:*
