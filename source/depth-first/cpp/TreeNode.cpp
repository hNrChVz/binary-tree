/* https://github.com/hNrChVz */

#include <iostream>
#include <vector>
#include "TreeNode.h"
#include <cassert>

using namespace std;

static void checkOrder(vector<int> expected, vector<int> result) {
    assert(expected.size() == result.size());

    if (result.size() == 0) {
        cout << "[]" << endl;
        return;
    }

    for (int i = 0; i < (int)result.size(); ++i) {
        if (i == 0) {
            cout << "[";
        }

        assert(expected[i] == result[i]);

        if (i == result.size() - 1) {
            cout << result[i] << "]" << endl;
        }
        else {
            cout << result[i] << ", ";
        }
    }
}

/*
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
*/
static vector<int> TREE_01_PRE_ORDER =  { 12, 10, 6, 57, 13, 89, 30, 40, 93, 1 };
static vector<int> TREE_01_IN_ORDER =   { 6, 10, 13, 57, 89, 12, 30, 93, 1, 40 };
static vector<int> TREE_01_POST_ORDER = { 6, 13, 89, 57, 10, 1, 93, 40, 30, 12 };

TreeNode* getTree01Root() {
    static TreeNode node12(12);
    static TreeNode node10(10); 
    static TreeNode node30(30);
    static TreeNode node6(6);
    static TreeNode node57(57);
    static TreeNode node40(40);
    static TreeNode node13(13);
    static TreeNode node89(89);
    static TreeNode node93(93);
    static TreeNode node1(1);

    node12.left = &node10;
    node12.right = &node30;
    node10.left = &node6;
    node10.right = &node57;
    node30.right = &node40;
    node57.left = &node13;
    node57.right = &node89;
    node40.left = &node93;
    node93.right = &node1;

    return &node12;
}

void checkTree01PreOrder(vector<int> p) {
    checkOrder(TREE_01_PRE_ORDER, p);
}

void checkTree01InOrder(vector<int> p) {
    checkOrder(TREE_01_IN_ORDER, p);
}

void checkTree01PostOrder(vector<int> p) {
    checkOrder(TREE_01_POST_ORDER, p);
}

/*
         45         
        /  \
       1    5       
      / \    \
    63   7   20     
    /   /
   6   87           
*/
static vector<int> TREE_02_PRE_ORDER = { 45, 1, 63, 6, 7, 87, 5, 20 };
static vector<int> TREE_02_IN_ORDER = { 6, 63, 1, 87, 7, 45, 5, 20 };
static vector<int> TREE_02_POST_ORDER = { 6, 63, 87, 7, 1, 20, 5, 45 };

TreeNode* getTree02Root() {
    static TreeNode node45(45);
    static TreeNode node1(1);
    static TreeNode node5(5);
    static TreeNode node63(63);
    static TreeNode node7(7);
    static TreeNode node20(20);
    static TreeNode node6(6);
    static TreeNode node87(87);

    node45.left = &node1;
    node45.right = &node5;
    node1.left = &node63;
    node1.right = &node7;
    node5.right = &node20;
    node63.left = &node6;
    node7.left = &node87;

    return &node45;
}

void checkTree02PreOrder(vector<int> p) {
    checkOrder(TREE_02_PRE_ORDER, p);
}

void checkTree02InOrder(vector<int> p) {
    checkOrder(TREE_02_IN_ORDER, p);
}

void checkTree02PostOrder(vector<int> p) {
    checkOrder(TREE_02_POST_ORDER, p);
}

/*
          4
         / \
        3   5
       /     \
      2       6
     /         \
    1           7
*/
static vector<int> TREE_03_PRE_ORDER = { 4, 3, 2, 1, 5, 6, 7 };
static vector<int> TREE_03_IN_ORDER = { 1, 2, 3, 4, 5, 6, 7 };
static vector<int> TREE_03_POST_ORDER = { 1, 2, 3, 7, 6, 5, 4 };

TreeNode* getTree03Root() {
    static TreeNode node1(1);
    static TreeNode node2(2);
    static TreeNode node3(3);
    static TreeNode node4(4);
    static TreeNode node5(5);
    static TreeNode node6(6);
    static TreeNode node7(7);

    node4.left = &node3;
    node4.right = &node5;
    node3.left = &node2;
    node5.right = &node6;
    node2.left = &node1;
    node6.right = &node7;

    return &node4;
}

void checkTree03PreOrder(vector<int> p) {
    checkOrder(TREE_03_PRE_ORDER, p);
}

void checkTree03InOrder(vector<int> p) {
    checkOrder(TREE_03_IN_ORDER, p);
}

void checkTree03PostOrder(vector<int> p) {
    checkOrder(TREE_03_POST_ORDER, p);
}

void checkNullRoot(vector<int> p) {
    vector<int> e;
    checkOrder(e, p);
}