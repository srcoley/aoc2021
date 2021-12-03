# Advent of Code 2021, Solved in C

https://adventofcode.com/

> Advent of Code is an Advent calendar of small programming puzzles for a variety of skill sets and skill levels that can be solved in any programming language you like. People use them as a speed contest, interview prep, company training, university coursework, practice problems, or to challenge each other.

This repository contains my solutions for this year's Advent of Code puzzles, written in C. I have been learning C, and think Advent of Code will provide a lot of useful exercizes to put all I've learned to practice. Don't expect the most elegant, efficient, or resiliant code.

## Building

Build all solutions at once
```bash
make
```
Or build a specific solution
```bash
make aoc1.1 # builds solution for day 1, problem 1
```

## Running - Manual

So far each problem comes with input that needs to be piped into each program. This means to run a solution properly you must cat the input file and pipe it into the solution program.
```bash
cat input/1.txt | ./aoc1.1
```

## Running - Auto

 I've added a small program called `run` that accepts a version(1.1 = day 1, problem 1) and runs the given program while piping in the appropriate input.
```bash
./run 1.1
# is the same as
cat input/1.txt | ./aoc1.1
```
If you'd like to run all of the programs pass `all` to run.
```
./run all

# cat input/1.txt | ./aoc1.1
# result: ####

# cat input/1.txt | ./aoc1.2
# result: ####

# cat input/2.txt | ./aoc2.1
# result: #######

# cat input/2.txt | ./aoc2.2
# result: ##########

# ...

# down to aoc31.2
```

You can build the `run` program with `make`, `make all`, or `make run`.
