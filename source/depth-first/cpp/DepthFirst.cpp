/* https://github.com/hNrChVz */

#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"

using namespace std;

class DepthFirst {
public:
    vector<int> getPreOrder(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> nodeStack;

        if (root != NULL) {
            nodeStack.push(root);
        }

        while (!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();

            ret.push_back(node->value); //visit the node

            //stack is last-in last-out, LILO, push right first then left
            if (node->right != NULL) {
                nodeStack.push(node->right);
            }

            if (node->left != NULL) {
                nodeStack.push(node->left);
            }
        }

        return ret;
    }

    vector<int> getInOrder(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> nodeStack;
        TreeNode* node = root;

        while (!nodeStack.empty() || node != NULL) {
            if (node != NULL) {
                nodeStack.push(node);
                node = node->left; //traverse left
            }
            else {
                node = nodeStack.top();
                nodeStack.pop();
                ret.push_back(node->value); //visit the node
                node = node->right; //traverse right;
            }
        }

        return ret;
    }

    /* for iterative, we do some kind of reverse post-order, we visit root-right-left
       then reverse it for the final output */
    vector<int> getPostOrder(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> nodeStack;

        if (root != NULL) {
            nodeStack.push(root);
        }

        while (!nodeStack.empty()) {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();

            ret.push_back(node->value);

            if (node->left != NULL) {
                nodeStack.push(node->left);
            }

             if (node->right != NULL) {
                nodeStack.push(node->right);
            }
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }

    /* iterative solution if the TreeNode are not reference 
       this assumes that root is not NULL */
    vector<int> getPostOrder(TreeNode root) {
        vector<int> ret;
        stack<TreeNode> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {
            TreeNode node = nodeStack.top();
            nodeStack.pop();

            if (node.left == NULL && node.right == NULL) {
                ret.push_back(node.value);
                continue;
            }

            stack<TreeNode> tempStack;
            //to create a copy of a node
            if (node.left != NULL) {
                tempStack.push(*node.left);
            }

            if (node.right != NULL) {
                tempStack.push(*node.right);
            }

            //we have visited this node so set left and right to NULL, before putting it back to the stack, to avoid infinite loop
            node.left = NULL;
            node.right = NULL;
            nodeStack.push(node);

            //now we push our nodes from our tempStack
            while (!tempStack.empty()) {
                TreeNode childNode = tempStack.top();
                tempStack.pop();
                nodeStack.push(childNode);
            }
        }

        return ret;
    }    
};

// Now test it!!!
void TEST_TREE_01() {
    DepthFirst depthFirst;
    TreeNode* root = getTree01Root();

    checkTree01PreOrder(depthFirst.getPreOrder(root));
    checkTree01InOrder(depthFirst.getInOrder(root));
    checkTree01PostOrder(depthFirst.getPostOrder(root));
    if (root != NULL) {
        checkTree01PostOrder(depthFirst.getPostOrder(*root));
    }
}

void TEST_TREE_02() {
    DepthFirst depthFirst;
    TreeNode* root = getTree02Root();

    checkTree02PreOrder(depthFirst.getPreOrder(root));
    checkTree02InOrder(depthFirst.getInOrder(root));
    checkTree02PostOrder(depthFirst.getPostOrder(root));
    if (root != NULL) {
        checkTree02PostOrder(depthFirst.getPostOrder(*root));
    }
}

void TEST_TREE_03() {
    DepthFirst depthFirst;
    TreeNode* root = getTree03Root();

    checkTree03PreOrder(depthFirst.getPreOrder(root));
    checkTree03InOrder(depthFirst.getInOrder(root));
    checkTree03PostOrder(depthFirst.getPostOrder(root));
    if (root != NULL) {
        checkTree03PostOrder(depthFirst.getPostOrder(*root));
    }
}

void TEST_NULL_ROOT() {
    DepthFirst depthFirst;
    TreeNode* root = NULL;

    checkNullRoot(depthFirst.getPreOrder(root));
    checkNullRoot(depthFirst.getInOrder(root));
    checkNullRoot(depthFirst.getPostOrder(root));
    if (root != NULL) {
        checkNullRoot(depthFirst.getPostOrder(*root));
    }
}

int main() {
    TEST_TREE_01();
    TEST_TREE_02();
    TEST_TREE_03();
    TEST_NULL_ROOT();
    return 0;
}

