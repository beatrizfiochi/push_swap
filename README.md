# 🧮 push_swap

This project aims to sort data on a stack in the most **efficient** way possible, using a **minimal number of operations**.  
To achieve this, it requires manipulating and implementing **sorting algorithms** adapted to a restricted set of stack operations.

---

## 📚 About

The `push_swap` program receives a list of integers and sorts them using **two stacks** (`a` and `b`) and a limited set of operations.  
The goal is to find the **shortest sequence of instructions** that results in a sorted stack.

This project focuses on:
- **Algorithmic thinking**
- **Optimization**
- **Handling edge cases**
- Writing clean and efficient C code under strict constraints

---

## 🛠️ Technologies Used

- **C Language** – Core logic and implementation  
- **Makefile** – Automating compilation  
- **Algorithm Design** – Sorting under constraints  
- **Stack Data Structure** – Using linked lists or arrays  
- **Unix I/O** – Basic output for instructions

---

## 🔁 Allowed Stack Operations

You can only use the following operations:

- `sa` / `sb` / `ss` — Swap top elements of stack A and/or B  
- `pa` / `pb` — Push top element from one stack to another  
- `ra` / `rb` / `rr` — Rotate (top element becomes last)  
- `rra` / `rrb` / `rrr` — Reverse rotate (last becomes top)
