#### These are solutions written in c for the Advent of Code - 2017. 
See https://adventofcode.com/2017

Each problem generally has two parts. Examples of filenames for day 5 are:
- d05a.c - solution for first part
- d05b.c - solution for second part
- d05.txt - problem data set; the same for both parts.

Very often the files of the sort d02b.c may not exist if the two parts of
the problem were similar enough to do both in d02a.c.

There may be a file like d03notes.txt if I felt more explanation was needed,
or just felt like making general comments. Sometimes it is just additional
compilation notes.

Sometimes the problem data set files (eg. d03.txt) do not exist because the
problem data was simple enough to be provided on the web page. Other times
it is there, but I have not attempted to read it. In either case the notes
file will give the input and my reasoning. There may also be a file like
d21x.txt which is example data which may be used for debugging.

Sometimes there may also be a php version of the program for reasons
described in the notes.

Compilation is generally something like
gcc/clang -O3 -Wall -o d01a d01a.c
with exceptions listed in the notes. 

These are not examples of good coding style nor necessarily of good code
as they are one-offs where getting them to work quickly and correctly was the
main objective. (Though I have cleaned them up a bit to remove debugging
printfs() and such.) (Also, unlike most people, I find code with a minimum of
extraneous spaces easier to read. YMMV) Most of them are short enough and
straightforward enough to not require any comments.

## Synopsis of each days problem

1. - Prove you are a bot by solving numeric captcha.
2. - Calculate spreadsheet checksum.
3. - Accessing spiral memory slowly.
4. - Check pass phrases for validity.
5. - Trampolining through a large region of self-modifying jump intructions.
6. - Finding repetitions in memory bank reallocations.
7. - Balance a tower of programs.
8. - Find largest values in registers after many odd operations.
9. - Removing garbage from a stream.
10. - Hash based on knot-tying.
11. - Moving on a hexagonal grid.
12. - Finding groups of interconnected programs.
13. - Traversing a firewall.
14. - More knot hashes and defragmenting a disk.
15. - Rndom number generators.
16. - Dancing program permutations.
17. - Out of control spinlock.
18. - Musical (?) assembly code.
19. - Routing alost network packet.
20. - GPU overloaded by too many particles.
21. - Generating 2D fractal art.
22. - Sneaky virus infecting CPU's.
23. - Fixing experimental coprocessor.
24. - Building a strong bridge from odd components.
25. - A broken Turing machine.
