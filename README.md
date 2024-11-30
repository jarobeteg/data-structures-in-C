# data-structures-in-C
It's a hobby project to gain better understanding in data structures and C.

## Planned data structures with operations
- Array (insert, remove, search, update, sort, etc.)
- Linked List (insert, remove, search, reverse, etc.)
- Stack (pop, push, remove, check if empty or full, etc.)
- Queue (insert, remove, check if empty or full, etc.)
- Deque (insert, remove, check if empty or full, etc.)
- Binary Tree (insert, remove, traverse, search, find height, find the number of nodes or leaves, etc.)
- Binary Search Tree (insert, remove, search, find min/max element, check if tree is balanced, etc.)
- Hash Table (insert key-value pair, remove key, search for key, etc.)

## Requirements
- **Compiler**: `gcc` (or any compatible C compiler supporting C11)
- **Build Tool**: `Make`

## Commands
1. Build the `main` executable:

   This will compile all the source files and generates the `main` executable.
   ```
   make
   ```
2. After building the `main` executable:

   This executes the `main` program.
   ```
   make run
   ```
4. Build the `test` executable:

   This will compile all the source files (except for `main.c`) along with the test files and generates the `test` executable.
   ```
   make test
   ```
5. After building the `test` executable:

   This executes all the `test` programs.
   ```
   make test-run
   ```
6. Clean the build files:

   This removes the `build` directory, `main` and `test` executables.
   ```
   make clean
   ```
