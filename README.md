# BinaryResearchTrees

This repository contains C functions for working with Binary Search Trees (BRT), specifically:
- Create a BRT
- Destroy it
- Print it
- Search an element
- Add an element
- Remove an element
- Remove a subtree

## Table of Contents

- [Structures](#structures)
- [Functions](#functions)
  - [BRT_create](#brt_create)
  - [BRT_insert](#brt_insert)
  - [BRT_delete](#brt_delete)
  - [BRT_destroy](#brt_destroy)
  - [BRT_search](#brt_search)
  - [Printing Functions](#printing-functions)
    - [inorder](#inorder)
    - [preOrder](#preorder)
    - [postOrder](#postorder)
- [Main Function](#main-function)

## Structures

```c
typedef struct tree* tree_pointer;

struct tree {
    int key;                // content of the node
    tree_pointer dx;        // pointer to the right child
    tree_pointer sx;        // pointer to the left child
};
```

## Functions

### BRT_create

```c
tree_pointer BRT_create();
```

Creates an empty Binary Search Tree.

**Input:**
- None

**Output:**
- `tree_pointer`: Pointer to the root of the newly created tree.

### BRT_insert

```c
tree_pointer BRT_insert(tree_pointer T, int key);
```

Inserts a node with the given key into the Binary Search Tree.

**Input:**
- `tree_pointer T`: Pointer to the tree to which the node is to be added.
- `int key`: Content of the node to be added.

**Output:**
- `tree_pointer`: Pointer to the modified tree.

### BRT_delete

```c
tree_pointer BRT_delete(tree_pointer T, int key);
```

Deletes the node with the given key from the Binary Search Tree.

**Input:**
- `tree_pointer T`: Pointer to the root of the tree from which an element is to be deleted.
- `int key`: Key of the element to be deleted.

**Output:**
- `tree_pointer`: Pointer to the modified tree.

### BRT_destroy

```c
void BRT_destroy(tree_pointer T);
```

Destroys the entire Binary Search Tree.

**Input:**
- `tree_pointer T`: Pointer to the tree to deallocate.

**Output:**
- None

### BRT_search

```c
int BRT_search(tree_pointer T, int k);
```

Searches for an element with the given key in the Binary Search Tree.

**Input:**
- `tree_pointer T`: Pointer to the root of the tree to search in.
- `int k`: Key to search for.

**Output:**
- `int`: 
  - `0`: The tree does not contain the searched key.
  - `1`: The tree contains the searched key.

### Printing Functions

#### inorder

```c
void inorder(tree_pointer T);
```

Prints the Binary Search Tree in symmetric order.

**Input:**
- `tree_pointer T`: Tree to print.

**Output:**
- None

#### preOrder

```c
void preOrder(tree_pointer T);
```

Prints the Binary Search Tree in preorder.

**Input:**
- `tree_pointer T`: Tree to print.

**Output:**
- None

#### postOrder

```c
void postOrder(tree_pointer T);
```

Prints the Binary Search Tree in postorder.

**Input:**
- `tree_pointer T`: Tree to print.

**Output:**
- None

### Example:

Inserted keys: 5, 7, -3, 1

Tree structure:

<img src="https://github.com/lezippo/BinaryResearchTrees/assets/148436988/6f308886-2159-49dd-b4ae-66e095ed6aae" style="width:30%; height:auto;">

Print the tree in Symmetric order:
```
-3| 1| 5| 7|
```

Print the tree in Post order:
```
1| -3| 7| 5| 
```

Print the tree in Pre order:
```
5| -3| 1| 7|
```

### Main Function

The main function provides a command-line interface for interacting with the Binary Search Tree. It allows users to perform operations such as insertion, deletion, searching, and printing of the tree.

For a more detailed understanding of the functions, you can refer to the comments within the code.



## Authors
Luigi Emanuele Zippo and Pietro Peluso
