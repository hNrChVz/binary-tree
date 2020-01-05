/* https://github.com/hNrChVz */

#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__

#include <cstddef>
#include <vector>

using namespace std;

//binary tree node
struct TreeNode {
    int value;
    TreeNode* left = NULL;
    TreeNode* right = NULL;

    TreeNode(int v) : value(v) {
    }
};

TreeNode* getTree01Root();
void checkTree01PreOrder(vector<int> p);
void checkTree01InOrder(vector<int> p);
void checkTree01PostOrder(vector<int> p);

TreeNode* getTree02Root();
void checkTree02PreOrder(vector<int> p);
void checkTree02InOrder(vector<int> p);
void checkTree02PostOrder(vector<int> p);

TreeNode* getTree03Root();
void checkTree03PreOrder(vector<int> p);
void checkTree03InOrder(vector<int> p);
void checkTree03PostOrder(vector<int> p);

void checkNullRoot(vector<int> p);

#endif
