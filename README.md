## Description

This project includes a C++ program designed to analyze text files. The program reads from an input text file, processes the content to count word frequencies, identify lines where words occur, and extract URLs. The results are saved in separate output files.

## Files

### `main.cpp`
This is the main source code file for the project. It contains the following functionalities:

- **cleanWord**: Cleans a word by removing punctuation and digits.
- **parser**: Parses the text, counts word occurrences, and tracks the lines in which each word appears.
- **findURLs**: Identifies URLs in the text using regular expressions.
- **writeWordsNumbers**: Writes words with their counts to a file.
- **writeWordsLocationTable**: Writes words and their line numbers to a file.
- **writeUrlToFile**: Writes extracted URLs to a file.
- **fileExistanceValidator**: Validates the existence of a specified file.
- **main**: Main function that orchestrates the reading of the input file, parsing, and writing results to output files.

### `Makefile`
This file contains the instructions for compiling the project. It simplifies the build process and includes rules for compiling and linking the source files.

## Usage

### Compilation

To compile the project, run the following command in the terminal:

    make

This command uses the `Makefile` to compile `main.cpp` and generate the executable.

### Execution

To execute the program, run the following command:

    ./main

Ensure that the input file named `input.txt` is present in the same directory as the executable. The program reads from `input.txt`, processes the content, and generates the following output files:

- `rez1.txt`: Contains words and their frequencies (only words that appear more than once).
- `rez2.txt`: Contains words and the line numbers where they appear (only words that appear in more than one line).
- `rez3.txt`: Contains the extracted URLs.

### Input File

The input file should be named `input.txt` and placed in the same directory as the executable. The program will read this file, process its content, and generate the results.

### Output Files

- **rez1.txt**: Lists words and their counts.
- **rez2.txt**: Lists words and the line numbers they appear on.
- **rez3.txt**: Lists extracted URLs.

## Error Handling

If the input file `input.txt` does not exist, the program will throw a runtime error with a message indicating the file does not exist.

## Dependencies

- A C++ compiler (such as g++)
- Standard C++ library
