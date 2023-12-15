# Advent Of Code 2023 Solutions

These are my solutions for the [Advent of Code 2023](https://adventofcode.com/) puzzles. 

## Compilation

```bash
mkdir build
cd build
cmake ..
make -j $(nproc)
```

## Run Puzzles

Before running the puzzles, you should decide how you want to put in your puzlle input. You can acquire your own puzzle input by logging into one of your accounts(e.g. Github) on the [Advent of Code](https://adventofcode.com/) website and then following the instructions at the individual puzzles.

### Puzzle Input as File

You can provide your own puzzle input for the puzzles in the subfolder `puzzle_input`.
The input files should be named `input<puzzle_id>.txt` with puzzle_id being the respective day.

The program will automatically assume, that you want to run the puzzle with the file input if it finds e.g. a file named `input4.txt` for the puzzle of day 4.

### Puzzle Input as Command Line input

This is more of a testing function. The program will ask you to put in a puzzle input as command line input if you don't provide a respective input file in the `puzzle_input` folder.
First, the program will ask you, how many lines your input will have. Then put in your input line for line.

### Run the Main Program
Just run this from the `build` directory after compilation:
```bash
./AoC2023
```

## Run Tests

This repository also contains unit tests. They test utility function as well as the puzzle solutions.
The 'ground truth' to verify the solutions are the test input and output that is provided for each puzzle description on Advent of Code.
Run the tests with the following command from the `build` directory:
```bash
ctest
```


