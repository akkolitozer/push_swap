*This project has been created as part of the 42 curriculum by
hulescur.*

# push_swap

## Description

`push_swap` is a sorting algorithm project from the 42 curriculum.

The goal is to sort a list of integers using two stacks (A and B) and a
restricted set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`,
`rr`, `rra`, `rrb`, `rrr`) while generating the smallest possible number
of instructions.

This implementation:

-   Parses arguments as multiple parameters or a single quoted string.
-   Validates input (numeric check, overflow, duplicates).
-   Assigns an index (rank) to each value.
-   Uses:
    -   Specific logic for 2, 3 and 5 numbers.
    -   A binary radix sort for larger inputs.

The program prints only the required operations to standard output.

------------------------------------------------------------------------

## Instructions

### Compilation

    make

This generates:

    ./push_swap

Optional rules (if implemented):

    make clean
    make fclean
    make re

### Execution

Multiple arguments:

    ./push_swap 4 2 3 1

Single string:

    ./push_swap "4 2 3 1"

If an error occurs, the program prints:

    Error

------------------------------------------------------------------------

## Resources

### References

-   https://fr.wikipedia.org/wiki/Liste_cha%C3%AEn%C3%A9e
-   https://en.wikipedia.org/wiki/Radix_sort
-   https://en.cppreference.com/w/c/language/operator_arithmetic

### AI Usage

All parsing, stack management, indexing logic, sorting logic, and memory
handling were implemented manually.
