# Push Swap Project

The goal of this project is to sort a stack with the minimal number of actions, highlighting proficiency in algorithm optimization and complexity management.

## Introduction

The **Push Swap** project is an algorithmic challenge where the goal is to sort a set of unique integers using two stacks and a predefined set of operations. The program, `push_swap`, must output the smallest possible sequence of operations needed to sort the integers.

## Rules

- You have 2 stacks: **a** and **b**.
- Initially, stack **a** contains a random set of unique integers, and stack **b** is empty.
- The goal is to sort the integers in stack **a** in ascending order using the following operations:

| Operation | Description |
| --------- | ----------- |
| `sa` | Swap the first two elements at the top of stack **a**. |
| `sb` | Swap the first two elements at the top of stack **b**. |
| `ss` | Perform `sa` and `sb` simultaneously. |
| `pa` | Move the top element of stack **b** to the top of stack **a**. |
| `pb` | Move the top element of stack **a** to the top of stack **b**. |
| `ra` | Rotate stack **a** upwards. The first element becomes the last. |
| `rb` | Rotate stack **b** upwards. The first element becomes the last. |
| `rr` | Perform `ra` and `rb` simultaneously. |
| `rra` | Reverse rotate stack **a**. The last element becomes the first. |
| `rrb` | Reverse rotate stack **b**. The last element becomes the first. |
| `rrr` | Perform `rra` and `rrb` simultaneously. |

## Algorithm Details

### Radix Sort

In computer science, radix sort is a non-comparative sorting algorithm. It avoids comparison by creating and distributing elements into buckets according to their radix. For elements with more than one significant digit, this bucketing process is repeated for each digit, while preserving the ordering of the prior step, until all digits have been considered. For this reason, radix sort has also been called bucket sort and digital sort.

Radix sort can be applied to data that can be sorted lexicographically, such as integers, words, punch cards, playing cards, or mail. Radix sorts can be implemented to start at either the most significant digit (MSD) or least significant digit (LSD).

#### Least Significant Digit (LSD) Radix Sort

LSD radix sorts typically use the following sorting order: short keys come before longer keys, and then keys of the same length are sorted lexicographically.


![image](https://github.com/valentinefleith/push_swap/assets/125041345/96a70bf8-63f2-49d0-ab06-0521c644a701)



### Implementation in Push Swap

The implementation of the sorting algorithm in this project is based on the **Binary LSD (Least Significant Digit) Radix Sort**. This algorithm  sorts integers by processing individual bits from the least significant to the most significant. Here's the approach:

1. **Get Maximum Bits**:
   Determine the number of bits required to represent the maximum number in the stack. This helps in deciding the number of iterations needed for sorting.

2. **Radix Sort**:
   - **Bitwise Processing**: Sort integers by examining each bit from the least significant to the most significant.
   - **Stack Operations**: Use stack operations (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`) to manipulate and sort the elements based on their binary representation.
   - **Iteration**: For each bit position, partition the elements into two groups (those with the bit set to 0 and those with the bit set to 1) and rearrange them using the stacks.

