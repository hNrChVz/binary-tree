## Binary Tree
A **[binary tree](https://en.wikipedia.org/wiki/Binary_tree)** is a tree-like data structure composed of a node (usually refer to as a *root*) with a left and/or right nodes (refer to as *children* or *child nodes*).

## About
In here, you can find basic explanations and code samples on how to do a search or traverse thru a binary tree. Every now and then, I'll update this repository to include some *binary tree* related problems and solutions.  

In this context, search and traverse are interchangeable. So as *root* and *node*.

### Note
Do not confuse [binary search](https://en.wikipedia.org/wiki/Binary_search_algorithm) with [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree), those are two different things.

## Traversal
In general, there are two ways you can traverse thru a *binary tree*:
* **Depth-first**
* **Breadth-first**

For more information about tree traversal, refer to [this](https://en.wikipedia.org/wiki/Tree_traversal).

### Depth-first
Commonly known as [depth-first search](https://en.wikipedia.org/wiki/Tree_traversal#Depth-first_search_of_binary_tree) or DFS. From the *root*, this method goes deep-down first into the *left node* and then into the *right node*. 

Depth-first can be done iteratively and in most cases, if not all, [recursively](https://en.wikipedia.org/wiki/Recursion_(computer_science)).

#### Pre-order (root-left-right)
This method visit the *root* first, then it's *left node* then the *right node*.

#### In-order (left-root-right)
This method traverse to the *left node* first, then visit the *root*, and then traverse to the *right node*.

#### Post-order (left-right-root)
This method traverse to the *left node* first, then traverse to the *right node*, and then visit the *root*.

### Breadth-first
Also known as [breadth-first search](https://en.wikipedia.org/wiki/Tree_traversal#Breadth-first_search) or BFS. This method visits each node level by level, thus called **level-order** traversal. 

Breadth-first can be done iteratively.

### Tips and Techniques
In coding a binary tree traversals, one way is using iteration or loop. With this technique, it is recommended (or best) to use a [queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) or [stack](https://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29). With my iteration solutions, I'll be using *C++*.

Another way is using *recursion*. *Binary tree* is a good data structure to practice *recursion*. With recursion solution, sample codes are in *Java*.

With level-order traversal (breadth-first), I do not think you can do it recursively. I haven't thought of a way to do it recursively nor seen one. In all recursion solution I've seen, the output might be in level-order, but still, it traverse thru the binary tree depth-first. If you seen an actual level-order traversal using recursion, or have one, please let me know.

All of my sample codes will be using these for its test cases: 

Test Case 01:
```
          12           Pre-order:   [12, 10, 6, 57, 13, 89, 30, 40, 93, 1]
         /  \          
       /      \        In-order:    [6, 10, 13, 57, 89, 12, 30, 93, 1, 40]
      10      30       
     /  \       \      Post-order:  [6, 13, 89, 57, 10, 1, 93, 40, 30, 12]
    6   57      40     
       /  \    /       Level-order: [12, 10, 30, 6, 57, 40, 13, 89, 93, 1]
      13  89  93       
               \      
                1
```

Test Case 02:
```
            45         Pre-order:   [45, 1, 63, 6, 7, 87, 5, 20]
           /  \
          1    5       In-order:    [6, 63, 1, 87, 7, 45, 5, 20]
         / \    \
       63   7   20     Post-order:  [6, 63, 87, 7, 1, 20, 5, 45]
       /   / 
      6   87           Level-order: [45, 1, 5, 63, 7, 20, 6, 87]
```

Test Case 03:
```
          4           Pre-order:   [4, 3, 2, 1, 5, 6, 7]
         / \
        3   5         In-order:    [1, 2, 3, 4, 5, 6, 7]
       /     \
      2       6       Post-order:  [1, 2, 3, 7, 6, 5, 4]
     /         \
    1           7     Level-order: [4, 3, 5, 2, 6, 1, 7]
```