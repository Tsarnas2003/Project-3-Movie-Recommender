#include <iostream>

using namespace std;

// B-Tree implementation from: https://www.programiz.com/dsa/b-tree

class TreeNode {
    int *keys;
    int t;
    TreeNode **C;
    int n;
    bool leaf;
  
    public:
        TreeNode(int temp, bool bool_leaf);
    
        void insertNonFull(int k);
        void splitChild(int i, TreeNode *y);
        void traverse();
    
        TreeNode *search(int k);
    
        friend class BTree;
};
  
class BTree {
    TreeNode *root;
    int t;
  
    public:
        BTree(int temp) {
            root = NULL;
            t = temp;
        }
    
        void traverse() {
            if (root != NULL)
                root->traverse();
        }
    
        TreeNode *search(int k) {
            return (root == NULL) ? NULL : root->search(k);
        }
    
        void insert(int k);
};