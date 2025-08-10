# Data Structures Implementation in C

This project contains implementations of fundamental data structures from scratch in C. Each data structure is carefully implemented with its core operations and memory management.

## Data Structures Included

### 1. Linked List ([`list.h`](include/list.h))
A singly linked list implementation with the following operations:
- Initialize list
- Insert node
- Remove node
- Destroy list

Usage example:
```c
List list;
list_init(&list, free);
list_ins_next(&list, NULL, data);  // Insert at head
list_destroy(&list);
```

### 2. Double Linked List ([`dlist.h`](include/dlist.h))
A doubly linked list with bidirectional traversal capabilities:
- Insert node (before/after)
- Remove node
- Bidirectional navigation

### 3. Circular Linked List ([`clist.h`](include/clist.h))
A circular linked list where the last node points back to the first:
- Insert node
- Remove node
- Circular traversal

### 4. Stack ([`stack.h`](include/stack.h))
A LIFO (Last-In-First-Out) data structure with:
- Push operation
- Pop operation
- Peek at top element

### 5. Queue ([`queue.h`](include/queue.h))
A FIFO (First-In-First-Out) data structure supporting:
- Enqueue operation
- Dequeue operation
- Peek at front element

### 6. Binary Tree ([`bitree.h`](include/bitree.h))
A binary tree implementation with:
- Insert left/right child
- Remove left/right subtree
- Tree traversal operations

### 7. AVL Tree ([`bistree.h`](include/bistree.h))
A self-balancing binary search tree implementation:
- Auto-balancing on insert/delete
- Left/Right rotations
- Balance factor maintenance

## Implementation Details

All data structures are implemented with:
- Dynamic memory allocation
- Proper memory cleanup
- Error handling
- Generic data storage (void pointers)
- Clean and consistent API

## Usage Example

Here's how to use the stack data structure:

```c
Stack stack;
void *data;

// Initialize
stack_init(&stack, free);

// Push data
stack_push(&stack, data);

// Pop data
stack_pop(&stack, (void **)&data);

// Get size
int size = stack_size(&stack);

// Cleanup
stack_destroy(&stack);
```

## Memory Management

Each data structure includes a destroy function pointer that can be set to handle cleanup of the stored data. This allows for proper memory management of complex data types.

## Build and Use

1. Include the needed header files from the `include` directory
2. Compile the corresponding source files from the `source` directory
3. Link with your application

## Notes

- All implementations are from scratch without using standard library containers
- Focus is on clean, efficient, and reusable code
- Error checking is implemented throughout