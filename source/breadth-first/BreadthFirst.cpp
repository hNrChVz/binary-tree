/* https://github.com/hNrChVz */

#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

//binary tree node
struct TreeNode {
    int value;
    TreeNode* left = NULL;
    TreeNode* right = NULL;

    TreeNode(int v) : value(v) {
    }
};

/*
* Push each node into the queue base on its order
*/
class BreadthFirst {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> nodeQ;

        if (root != NULL) {
            nodeQ.push(root);
        }

        while (!nodeQ.empty()) {
            int numOfNodes = nodeQ.size(); //number of nodes for the current level

            //now visit each node, then put each node's children into the queue
            for (int i = 0; i < numOfNodes; i++) {
                TreeNode* node = nodeQ.front();
                nodeQ.pop();

                ret.push_back(node->value);

                if (node->left != NULL) {
                    nodeQ.push(node->left);
                }

                if (node->right != NULL) {
                    nodeQ.push(node->right);
                }
            }
        }

        return ret;
    }
};

/*
          12
         /  \
       /      \
      10      30
     /  \       \
    6   57      40
       /  \    /
      13  89  93
               \
                1
*/
static void TEST_CASE_01() {
    TreeNode node12(12);
    TreeNode node10(10);
    TreeNode node30(30);
    TreeNode node6(6);
    TreeNode node57(57);
    TreeNode node40(40);
    TreeNode node13(13);
    TreeNode node89(89);
    TreeNode node93(93);
    TreeNode node1(1);

    node12.left = &node10;
    node12.right = &node30;
    node10.left = &node6;
    node10.right = &node57;
    node30.right = &node40;
    node57.left = &node13;
    node57.right = &node89;
    node40.left = &node93;
    node93.right = &node1;

    int expected[10] = { 12, 10, 30, 6, 57, 40, 13, 89, 93, 1 };

    BreadthFirst breadthFirst;
    vector<int> result = breadthFirst.levelOrder(&node12);
    assert(result.size() == 10);
    for (int i = 0; i < 10; i++) {
        cout << expected[i] << " " << result[i] << endl;
        assert(expected[i] == result[i]);
    }
    cout << "***** TEST_CASE_01 END *****" << endl;
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
static void TEST_CASE_02() {
    TreeNode node45(45);
    TreeNode node1(1);
    TreeNode node5(5);
    TreeNode node63(63);
    TreeNode node7(7);
    TreeNode node20(20);
    TreeNode node6(6);
    TreeNode node87(87);

    node45.left = &node1;
    node45.right = &node5;
    node1.left = &node63;
    node1.right = &node7;
    node5.right = &node20;
    node63.left = &node6;
    node7.left = &node87;

    int expected[8] = { 45, 1, 5, 63, 7, 20, 6, 87 };

    BreadthFirst breadthFirst;
    vector<int> result = breadthFirst.levelOrder(&node45);
    assert(result.size() == 8);
    for (int i = 0; i < 8; i++) {
        cout << expected[i] << " " << result[i] << endl;
        assert(result[i] == expected[i]);
    }
    cout << "***** TEST_CASE_02 END *****" << endl;
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
static void TEST_CASE_03() {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);

    node4.left = &node3;
    node4.right = &node5;
    node3.left = &node2;
    node5.right = &node6;
    node2.left = &node1;
    node6.right = &node7;

    int expected[7] = { 4, 3, 5, 2, 6, 1, 7 };

    BreadthFirst breadthFirst;
    vector<int> result = breadthFirst.levelOrder(&node4);
    assert(result.size() == 7);
    for (int i = 0; i < 7; i++) {
        cout << expected[i] << " " << result[i] << endl;
        assert(expected[i] == result[i]);
    }
    cout << "***** TEST_CASE_03 END *****" << endl;
}

static void TEST_CASE_NULL_ROOT() {
    BreadthFirst breadthFirst;
    vector<int> result = breadthFirst.levelOrder(NULL);
    assert(result.size() == 0);
    cout << "***** TEST_CASE_NULL_ROOT END *****" << endl;
}

int main()
{
    TEST_CASE_01();
    TEST_CASE_02();
    TEST_CASE_03();
    TEST_CASE_NULL_ROOT();

    cout << endl << "********** THE END **********" << endl;
}

