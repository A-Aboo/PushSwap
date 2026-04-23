
# push_swap

*This project has been created as part of the 42 curriculum by anasimi.*

## Overview

`push_swap` is a sorting project from the 42 curriculum.

The goal is to sort a list of **unique integers** in **ascending order** using only:

- **two stacks**: `a` and `b`
- a limited set of **allowed operations**

The challenge is not only to sort correctly, but also to do it with **as few operations as possible**.

This project focuses on:

- parsing and validating input
- stack manipulation
- algorithmic thinking
- optimization of move count
- writing clean and reliable C code

---

## Project Rules

The program must:

- take a list of integers as arguments
- reject invalid input
- reject duplicate numbers
- sort the numbers using only the allowed operations
- print the operations to standard output, one per line

If the arguments are invalid, the program must print:

```bash
Error
```

---

## Allowed Operations

The following operations are allowed:

### Swap

* `sa` : swap the first 2 elements at the top of stack `a`
* `sb` : swap the first 2 elements at the top of stack `b`
* `ss` : `sa` and `sb` at the same time

### Push

* `pa` : take the first element of `b` and put it at the top of `a`
* `pb` : take the first element of `a` and put it at the top of `b`

### Rotate

* `ra` : shift up all elements of `a` by 1
* `rb` : shift up all elements of `b` by 1
* `rr` : `ra` and `rb` at the same time

### Reverse rotate

* `rra` : shift down all elements of `a` by 1
* `rrb` : shift down all elements of `b` by 1
* `rrr` : `rra` and `rrb` at the same time

---

## Approach Used

This implementation uses three main parts:

### 1. Parsing and validation

The program first checks the input carefully:

* valid integer format
* no overflow / underflow
* no duplicate values
* support for multiple arguments
* support for quoted arguments if parsing is implemented that way

If anything is wrong, the program exits with `Error`.

### 2. Small sort

For small inputs, special optimized strategies are used:

* **2 numbers**
* **3 numbers**
* **4 numbers**
* **5 numbers**

These cases are handled separately because they can be solved with very few moves and do not need a general large-input algorithm.

### 3. Chunk sort

For larger inputs, the program uses a **chunk-based strategy**.

General idea:

* the values are indexed / normalized
* the input is divided into chunks
* elements are pushed from stack `a` to stack `b` chunk by chunk
* elements are then moved back from `b` to `a` in the correct order

This method gives much better results for big inputs than using only naive rotations or brute force logic.

---

## Features

* strict input validation
* duplicate detection
* optimized small sort for tiny cases
* chunk sort for larger cases
* clean stack-based logic
* manual review and testing

---

## Compilation

Use:

```bash
make
```

This will generate the executable:

```bash
./push_swap
```

To remove object files:

```bash
make clean
```

To remove object files and executable:

```bash
make fclean
```

To rebuild everything:

```bash
make re
```

---

## Usage

Example:

```bash
./push_swap 2 1 3 6 5 8
```

The program outputs a list of operations, for example:

```bash
sa
ra
pb
...
```

You can also test with quoted arguments if your parser supports it:

```bash
./push_swap "2 1 3 6 5 8"
```

---

## Example Workflow

Input:

```bash
./push_swap 3 2 1
```

Possible output:

```bash
sa
rra
```

This means the program sorted the stack using only allowed instructions.

---

## Checking Correctness

You can verify the result with the 42 checker if available:

```bash
ARG="2 1 3 6 5 8"; ./push_swap $ARG | ./checker $ARG
```

Expected result:

```bash
OK
```

If the sequence is not sorted correctly:

```bash
KO
```

---

## Error Handling

Examples of invalid input:

```bash
./push_swap 1 2 2
./push_swap 1 a 3
./push_swap 999999999999
./push_swap ""
```

Expected output:

```bash
Error
```

---

## Algorithm Notes

### Why small sort?

Very small cases can be solved faster with dedicated logic than with a general algorithm.

### Why chunk sort?

For large inputs, chunk sort reduces unnecessary movements by grouping values into ranges and pushing them in a more organized way.

### Why normalize / index values?

Working with indexes instead of raw values makes comparisons easier and helps the algorithm behave more consistently.

---


## Learning Goals

This project helped practice:

* linked lists or array-based stacks
* algorithm design
* input parsing
* memory management
* edge case handling
* optimization under constraints

---

## Resources

* 42 subject: **push_swap**
* chunk sort strategy
* stack / array fundamentals
* algorithm planning and move optimization

AI was used only for **planning and checking ideas**.
The code itself was **reviewed and tested manually**.

---

## Notes

This project is part of the 42 curriculum and was built to respect the project constraints:

* no forbidden shortcuts
* sorting through allowed stack operations only
* focus on correctness first, then optimization

---

