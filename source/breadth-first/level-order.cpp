/* https://github.com/hNrChVz */

#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

//binary tree node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : value(v), left(NULL), right(NULL) {
    }
};

/*
* Push each node into the queue base on its order
*/
class LevelOrder {
public:
    vector<int> iteration(TreeNode* root) {
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
          12                                45
         /  \                              /  \
       /      \                           1    5
      10      30                         / \    \
     /  \       \                      63   7   20
    6   57      40                     /     \
       /  \    /  \                   6      87
      13  89  93   8
     /          \
    19           1

*/

int main()
{
    LevelOrder levelOrder;

    {
        TreeNode node12(12);
        TreeNode node10(10);
        TreeNode node30(30);
        node12.left = &node10;
        node12.right = &node30;
        TreeNode node6(6);
        TreeNode node57(57);
        node10.left = &node6;
        node10.right = &node57;
        TreeNode node40(40);
        node30.right = &node40;
        TreeNode node13(13);
        TreeNode node89(89);
        node57.left = &node13;
        node57.right = &node89;
        TreeNode node93(93);
        TreeNode node8(8);
        node40.left = &node93;
        node40.right = &node8;
        TreeNode node19(19);
        node13.left = &node19;
        TreeNode node1(1);
        node93.right = &node1;

        int firstTree[12] = { 12, 10, 30, 6, 57, 40, 13, 89, 93, 8, 19, 1 };
        vector<int> result = levelOrder.iteration(&node12);
        assert(result.size() == 12);
        for (int i = 0; i < 12; i++) {
            cout << firstTree[i] << " " << result[i] << endl;
            assert(firstTree[i] == result[i]);
        }

        cout << "FIRST TREE OK" << endl;
    }

    cout << endl;

    {
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
        node7.right = &node87;

        int secondTree[8] = { 45, 1, 5, 63, 7, 20, 6, 87 };
        vector<int> result = levelOrder.iteration(&node45);
        assert(result.size() == 8);
        for (int i = 0; i < 8; i++) {
            cout << secondTree[i] << " " << result[i] << endl;
            assert(secondTree[i] == result[i]);
        }

        cout << "SECOND TREE OK" << endl;
    }    
}

