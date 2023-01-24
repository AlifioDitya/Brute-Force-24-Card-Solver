# IF2211 Algorithm Strategies Course Project
## 24 Game Solver with Brute Force Algorithm
This project is a program that solves the 24 Game, a mathematical puzzle in which the objective is to find a way to manipulate four integers representing card numbers with mathematical operations such that the end result is 24. The program uses a brute force approach, starting by taking four integers as inputs, then generating all possible permutations of the integers, and finally evaluating combinations of all possible sets of mathematical operations to find a solution for each permutation. The program also includes functionality for saving solutions to a text file and for outputting solutions in a human-readable format.

## Getting Started
### Prerequisites
- A C++ compiler (such as G++ or Clang)
- The C++ Standard Template Library (STL)

### Installing
*Alternative 1*
1. Clone the repository to your local machine
``` bash
$ git clone https://github.com/AlifioDitya/Tucil1_13521142.git
```
2. Change directory to `src` folder
``` bash
$ cd src
```
3. Compile the program
``` bash
$ g++ main.cpp func.cpp -o main.exe
```
4. Run the program
``` bash
$ ./main.exe
```
*Alternative 2*
1. Clone the repository to your local machine
``` bash
$ git clone https://github.com/AlifioDitya/Tucil1_13521142.git
```
2. Change directory to `bin` folder
``` bash
$ cd bin
```
3. Run executable file
``` bash
$ ./main.exe
```

### Usage
When the program is run, it will prompt the user to enter four integers. The program will then generate all possible permutations of these integers and use a set of mathematical operations to find a solution for each permutation. The program will output all solutions and execution time in a human-readable format and also offers an option to save the solutions to a text file.

## Repository Structure
```
│ .gitignore
│ README.md
├─── bin
│       │ main.exe
│
├─── doc
│       │ Tucil1_K2_13521142_Enrique Alifio Ditya_Revisi2.pdf
│
├─── src
│       │ func.h
│       │ func.cpp
│       │ main.cpp
│
├─── test
        │ test1.txt
        │ test2.txt
        │ test3.txt
        │ test4.txt
        │ test5.txt
        │ test6.txt
        │ test7.txt
```

## Author
[Enrique Alifio Ditya / 13521142](https://github.com/AlifioDitya)

## Made with
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)