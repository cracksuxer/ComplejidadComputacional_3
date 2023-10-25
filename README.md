# PRF Potence(x,y)

This project aims to implement a simple program that calculates the potence(x, y) using Primitive Recursive Functions (PRF).
As an extra, the program also calculates the factorial, division and multiplication using PRF.

## Prerequisites

- C++ compiler up to C++20 (preferably GCC 13.2 or later)
- CMake 3.21 or later

## Getting Started

- [Clone the repository](#clone-the-repository)
- [Compiling](#compiling)
- [Executing](#executing)
- [Usage](#usage)

### Clone the Repository

```bash
git clone https://github.com/cracksuxer/ComplejidadComputacional_3
cd [repository_directory]
```

### Compiling

- Create a new build directory

```bash
mkdir build
cd build
```
- Run CMake

```bash
cmake ..
```

- Compile

```bash
make
```

### Executing

To execute the program, run the following command:

```bash
./PRFProject [x (optional), y (optional)]
```

If no arguments are provided, the program asks for the values of x and y during runtime.

### Usage

A few examples:

```bash
./PRFProject 1 2
```

```bash
./PRFProject 3 4
```
