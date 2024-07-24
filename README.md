# sig_guard

**Automatic Stack Trace and Debugging for Segmentation Faults (and other signal) in C Programs**

![fdfseg1](https://github.com/user-attachments/assets/dfcf3c5a-7fe1-4977-baf5-1e9d4e3bfc11)

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
    cc -g -no-pie -rdynamic -o your_program your_program.c sigsegv_guard.c
    ```

## How It Works
The sigsegv_guard library sets up a signal handler for SIGSEGV that captures the current stack trace using the backtrace and backtrace_symbols functions.
It then uses the addr2line utility to translate the addresses into readable file names and line numbers, which are printed to the standard output.

## Using -no-pie, -rdynamic, and -O0 Flags in Compilation

### -no-pie Flag

#### Why Use It:

##### Debugging:
- Disables Address Space Layout Randomization (ASLR), ensuring memory addresses remain consistent across runs.
- This simplifies debugging and stack trace analysis.

##### Compatibility:
- Required on some legacy systems that do not support Position Independent Executable (PIE) binaries.

#### Functionality:
- The `-no-pie` flag instructs the compiler not to generate a PIE executable.
- This ensures the executable is loaded at a fixed memory address each time it is run, making memory addresses predictable during debugging.

### -rdynamic Flag

#### Why Use It:

##### Detailed Stack Traces:
- Makes program symbols available to the dynamic linker and debugger, enabling more informative stack traces with function names and line numbers.

#### Functionality:
- The `-rdynamic` flag ensures that the symbol table of the executable is included in the binary.
- This allows functions like `backtrace_symbols()` to retrieve human-readable function names instead of just memory addresses in stack traces.

### -O0 Flag

#### Why Use It:

##### Debugging:
- Disables all optimizations, ensuring the code is as close to the source code as possible.
- This makes debugging easier and stack traces more accurate.

#### Functionality:
- The `-O0` flag tells the compiler to not optimize the code.
- This ensures that the code remains straightforward and predictable, which is beneficial during debugging.

### Example Usage
To compile with these flags, use the following command:

```sh
gcc -g -O0 -no-pie -rdynamic main.c sig_guard.c -o a.out
```

## Sometimes it can be inaccurate, indicating the line after the function that is called within which the SIGSEGV occurs. I don't know why.

# Contributions
Contributions are welcome! Please open an issue or submit a pull request if you have any improvements or bug fixes.

# NOTE
Everything that the sig_guard function does can be better achieved using a debugger.
I approached this function as a practice exercise.
