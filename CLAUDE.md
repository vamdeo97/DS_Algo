# CLAUDE.md — DS_Algo Repository Guide

This file provides context for AI assistants (and developers) working in this repository.

---

## Repository Overview

**DS_Algo** is a collection of Data Structures and Algorithm implementations written in C and C++. Each file is self-contained and demonstrates a single algorithm or data structure concept. There is no shared library, build output, or test harness — each file compiles and runs independently.

---

## Directory Structure

```
DS_Algo/
├── CLAUDE.md                        # This file
├── README.md                        # Minimal project description
├── .github/
│   └── workflows/
│       └── c-cpp.yml               # GitHub Actions CI (autotools-based)
├── BST/                            # Binary/B-Tree algorithms (17 files)
├── LinkedList/                     # Linked list algorithms (21 files)
├── Queue/                          # Queue implementations (3 files)
└── Stack/                          # Stack implementations (5 files)
```

### Category Breakdown

| Directory  | Files | Language Mix | Focus |
|------------|-------|--------------|-------|
| `BST/`     | 17    | C + C++      | Binary search trees, B-trees, traversals, LCA |
| `LinkedList/` | 21 | C + C++   | Insertion, deletion, reversal, cycle detection, merging |
| `Stack/`   | 5     | C + C++      | Array-based and linked-list-based stacks, applications |
| `Queue/`   | 3     | C++          | Array-based, circular, and linked-list-based queues |

---

## Language and File Conventions

- **C files (`.c`)**: Procedural style, typically simpler implementations
- **C++ files (`.cpp`)**: May use classes or remain C-style with `#include <stdio.h>`
- **File naming**: CamelCase or UPPER_CASE descriptive names (e.g., `CheckPallindromeLinklist.cpp`, `STACK_ARRAY.c`)
- **No shared headers**: Each file is fully self-contained with its own `struct` definitions and `#include` statements
- **No Makefile or CMake**: Files are compiled individually; no project-level build system exists

---

## Code Patterns and Conventions

### Typical Node Structure

**Linked List node (C):**
```c
struct node {
    int num;
    struct node *n;   // 'n' is the conventional next-pointer name
};
```

**BST node (C/C++):**
```c
struct node {
    int num;
    struct node *left;
    struct node *right;
};
```

### Common Function Signatures

```c
void insert(struct node **head, int num);   // prepend to list
void print(struct node *head);              // traverse and print
struct node* Insert(struct node *root, int num); // BST insert (returns root)
void Inorder(struct node *root);            // in-order traversal
```

### Standard Includes

```c
#include <stdio.h>    // printf, scanf
#include <stdlib.h>   // malloc, free
#include <limits.h>   // INT_MAX, INT_MIN (used in BST bounds checking)
#include <string.h>   // string operations (some files)
// C++ files may also use:
#include <iostream>
#include <stack>
#include <queue>
```

> **Note**: Some files include `<conio.h>` (Windows-only, for `getch()`). This will not compile on Linux/macOS without substitution.

### Memory Management

- Dynamic allocation uses `malloc(sizeof(struct node))` — no `new`/`delete` in most files
- Memory is rarely freed explicitly (educational focus, not production)
- Always cast `malloc` return: `(struct node*)malloc(...)`

### Testing Style

All test cases live inside `main()` with hard-coded values. There is no test framework. Example pattern:

```c
int main() {
    struct node *head = NULL;
    insert(&head, 5);
    insert(&head, 3);
    print(head);
    return 0;
}
```

### Naming Conventions

| Identifier type | Convention | Examples |
|----------------|------------|---------|
| Function names | CamelCase or lowercase | `Insert`, `insert`, `printList` |
| Variable names | Lowercase, abbreviated | `head`, `temp`, `curr`, `prev`, `next` |
| Struct fields  | Short, abbreviated | `num` (data), `n` (next), `left`, `right` |
| Constants/macros | UPPER_CASE | `#define size 100` |

---

## File-by-File Inventory

### BST/
| File | Description |
|------|-------------|
| `BFS_Q.c` | Breadth-first search using an explicit queue |
| `BST_ARRAY.c` | Array-based BST representation |
| `BT_Level_order_Traversal_recursive.c` | Level-order traversal (recursive approach) |
| `B_TREE.cpp` | B-tree implementation with insertion |
| `B_TREE_DELETION.cpp` | B-tree deletion operations |
| `CountLeafNodes_iterative.c` | Iterative leaf-node counting |
| `DIAMETER__CHILD_SUM_ROOT__LEAF_PATH.c` | Tree diameter, child-sum property, root-to-leaf path printing |
| `HasPathSum.c` | Check if a root-to-leaf path sums to a target |
| `Kth_Smallest_Element_in_BST.c` | Find k-th smallest element via in-order traversal |
| `LCA_iterative.cpp` | Lowest Common Ancestor (iterative) |
| `LeastCommonAncestor.c` | Lowest Common Ancestor (recursive) |
| `Levelorder_iterative.c` | Level-order traversal (iterative, using queue) |
| `Outeredges_print.cpp` | Boundary/outer-edge traversal of a binary tree |
| `Range in BST.cpp` | Print all nodes within a given key range |
| `Size_Iterative.c` | Iterative tree size (node count) |
| `Size_of_BST.cpp` | Tree size (C++ version) |
| `isBST.cpp` | Validate whether a binary tree satisfies BST property |

### LinkedList/
| File | Description |
|------|-------------|
| `ADD.c` | Add two numbers represented as linked lists |
| `CheckPallindromeLinklist.cpp` | Check if linked list is a palindrome |
| `Consecutive_triplets.cpp` | Find consecutive node triplets |
| `Delete_M_node_after_N_nodes.cpp` | Delete M nodes after every N nodes |
| `Delete_Node.c` | Basic node deletion (includes lesser-node deletion) |
| `Flatten link list.cpp` | Flatten a multi-level linked list |
| `Intersection.c` | Find intersection point of two lists |
| `Loop_detection_removal.c` | Detect and remove cycles (Floyd's algorithm) |
| `Merge_two_sorted_linklist.cpp` | Merge two sorted linked lists |
| `Multilevellinklist_flatten.c` | Flatten multi-level list (C version) |
| `Recursive_Reverse.cpp` | Reverse a linked list recursively |
| `Rev_chunk_k_alternate_node.c` | Reverse K alternate nodes |
| `Reverse_chunk.c` | Reverse chunks of K nodes |
| `Reverse_chunk_with_ones.cpp` | Chunk reversal with special-case handling |
| `Reverse_chunks.cpp` | General chunk reversal (C++ version) |
| `Revprint_Recu.c` | Print list in reverse using recursion |
| `Segregate_even_odd_linklist.c` | Segregate even/odd nodes |
| `Sort 0s and 1s.cpp` | Sort list containing only 0s and 1s |
| `String_reversal_stack_arraybased.cpp` | String reversal using a stack |
| `Sub_linklist.cpp` | Sublist/sub-sequence operations |
| `Swap_nodes.c` | Swap two nodes in a linked list |

### Stack/
| File | Description |
|------|-------------|
| `Balanced_Parenthesis_check.cpp` | Validate balanced brackets/parentheses using stack |
| `NextGreaterElement.cpp` | Find next greater element for each array element |
| `STACK.cpp` | Array-based stack (C++ style) |
| `STACK_ARRAY.c` | Array-based stack (C style) |
| `stack_linklist.c` | Stack implemented with a linked list |

### Queue/
| File | Description |
|------|-------------|
| `Circular_Array.cpp` | Circular queue using a fixed-size array |
| `QUEUE_ARRAY_BASED.cpp` | Basic queue with array backing |
| `QUEUE_linklist.cpp` | Queue implemented with a linked list |

---

## How to Compile and Run a File

Since there is no Makefile, compile individual files directly:

**C file:**
```bash
gcc -o output BST/isBST.cpp        # or: gcc -o output LinkedList/Delete_Node.c
./output
```

**C++ file:**
```bash
g++ -o output BST/B_TREE.cpp
./output
```

**Common flags to add:**
```bash
-Wall -Wextra    # enable warnings
-g               # debug symbols
-std=c99         # enforce C99 for .c files
-std=c++11       # enforce C++11 for .cpp files
```

> Files with `<conio.h>` will fail on Linux. Remove or stub out `getch()` calls.

---

## CI/CD Pipeline

The GitHub Actions workflow (`.github/workflows/c-cpp.yml`) triggers on pushes and PRs to `master`. It uses the autotools pipeline:

```
./configure → make → make check → make distcheck
```

**Important**: The repository does not currently contain a `configure` script or `Makefile`. The CI pipeline will fail until these are added. This is a known gap.

---

## Development Guidelines for AI Assistants

### When adding a new algorithm file

1. Place it in the appropriate category directory (`BST/`, `LinkedList/`, `Stack/`, `Queue/`)
2. Make the file fully self-contained — include all necessary headers and define any structs used
3. Put test cases in `main()`
4. Use the same node naming conventions as existing files in that directory (`num` for data, `n` for next, `left`/`right` for trees)
5. Update this `CLAUDE.md` inventory table with the new file

### When modifying an existing file

- Preserve the existing coding style (indentation, naming, patterns) within the file
- Do not introduce external dependencies or shared headers
- Keep `main()` as the entry point with embedded test cases

### What NOT to do

- Do not create shared header files — this repo intentionally keeps files self-contained
- Do not add a build system without explicit instruction
- Do not rename files to fix style inconsistencies — existing names are referenced in git history
- Do not remove `main()` or test code from files

### Code style to follow

- Keep variable names short and consistent with what already exists in the file
- Prefer `struct node*` with the asterisk on the type side (matches existing style in most files)
- Use `printf`/`scanf` (not `cout`/`cin`) even in `.cpp` files, unless the file already uses streams
- Avoid adding comments unless the logic is non-obvious — these are already concise educational files

---

## Known Issues and Limitations

| Issue | Detail |
|-------|--------|
| `<conio.h>` usage | Some files include this Windows-only header; they won't compile on Linux/macOS |
| No Makefile/configure | CI pipeline references autotools build but no build files exist |
| Global variables | Some simpler files use global state rather than passing by pointer |
| Incomplete `free()` calls | Memory is allocated but rarely freed; not a concern for educational code |
| Inconsistent line endings | Mixed CRLF/LF across files |
| Filenames with spaces | `Sort 0s and 1s.cpp` and `Flatten link list.cpp` have spaces — quote them when using shell commands |

---

## Git Workflow

- Default branch: `master`
- No enforced branching model beyond the CI trigger on `master`
- Commit messages are informal (no conventional commit format enforced)

When working on this repo as an AI assistant, use the branch specified in the task instructions (typically a `claude/` prefixed branch).
