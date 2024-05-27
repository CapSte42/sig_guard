# sigsegv_guard

**Automatic Stack Trace and Debugging for Segmentation Faults in C Programs**

## Overview

The `sigsegv_guard` library provides a simple way to automatically capture and print stack traces when a segmentation fault (`SIGSEGV`) occurs in your C programs. This helps in debugging by showing you the exact location in your code where the fault happened.

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

2. Include the `sigsegv_guard.h` and `sigsegv_guard.c` files in your project.

### Usage

1. Include the header file in your main C file:

    ```
    #include "sigsegv_guard.h"
    ```

2. Call the `sigsegv_guard()` function at the beginning of your `main` function:

    ```
    int main() {
        sigsegv_guard();

        // Your code here that might cause a segmentation fault
        int *p = NULL;
        *p = 42; // This will generate a SIGSEGV

        return 0;
    }
    ```

3. Compile your program with debug information enabled:

    ```
    gcc -g -o your_program your_program.c sigsegv_guard.c
    ```

### Example

Here's a full example of how to integrate `sigsegv_guard` into your project:

```
#include <stdio.h>
#include "sigsegv_guard.h"

int main() {
    sigsegv_guard();

    // Cause a segfault to test the handler
    int *p = NULL;
    *p = 42; // This will generate a SIGSEGV

    return 0;
}
```

## How It Works
The sigsegv_guard library sets up a signal handler for SIGSEGV that captures the current stack trace using the backtrace and backtrace_symbols functions. It then uses the addr2line utility to translate the addresses into readable file names and line numbers, which are printed to the standard output.

# Contributions
Contributions are welcome! Please open an issue or submit a pull request if you have any improvements or bug fixes.
