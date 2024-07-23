# sig_guard

**Automatic Stack Trace and Debugging for Segmentation Faults (and other signal) in C Programs**

## Overview

The `sig_guard` library provides a simple way to automatically capture and print stack traces when a error signal (e.g. `SIGSEGV`) occurs in your C programs.
This can helps in debugging by showing you the exact location in your code where the fault happened.

## Features

- Captures `SIGSEGV` signals
- Prints a detailed stack trace
- Filters out unnecessary information for clarity
- Easy to integrate into any C project

## Getting Started

### Prerequisites

- GCC or any other C compiler
- Linux or Unix-based operating system (requires `execinfo.h` and `addr2line`)

### Installation

1. Clone the repository:
    ```
    git clone https://github.com/yourusername/sigsegv_guard.git
    ```

2. Include the `sig_guard.h` and `sig_guard.c` files in your project.

### Usage

1. Include the header file in your main C file:

    ```
    #include "sig_guard.h"
    ```

2. Call the `sig_guard()` function at the beginning of your `main` function:

    ```
    int main(int ac, char **av)
    {
        sig_guard(av[0]); //or sig_guard("NAME-OF-THE-EXECUTABLE")

        // Your code here that might cause a segmentation fault
        int *p = NULL;
        *p = 42; // This will generate a SIGSEGV

        return 0;
    }
    ```

3. Compile your program with debug information enabled:

    ```
    cc -g -o your_program your_program.c sigsegv_guard.c
    ```

## How It Works
The sigsegv_guard library sets up a signal handler for SIGSEGV that captures the current stack trace using the backtrace and backtrace_symbols functions.
It then uses the addr2line utility to translate the addresses into readable file names and line numbers, which are printed to the standard output.

## Sometimes it can be inaccurate, indicating the line after the function that is called within which the SIGSEGV occurs. I don't know why.

# Contributions
Contributions are welcome! Please open an issue or submit a pull request if you have any improvements or bug fixes.

# NOTE
Everything that the sig_guard function does can be better achieved using a debugger.
I approached this function as a practice exercise.
