#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <vector>

#include "Movie.h"

using namespace std;

// B-Tree implementation from: https://www.programiz.com/dsa/b-tree

class TreeNode {
    Movie** keys;
    int t;
    TreeNode** C;
    int n;
    bool leaf;
  
    public:
        TreeNode(int temp, bool bool_leaf);
    
        void insertNonFull(Movie* k);
        void splitChild(int i, TreeNode* y);
        void traverse();
        vector<Movie*> getMovieRecs();
        TreeNode* search(Movie* k);
    
        friend class BTree;
};
  
class BTree {
    TreeNode* root;
    int t;
  
    public:
        BTree(int temp);

        void insert(Movie* k);
        void traverse();
        vector<Movie*> getLast();
        TreeNode* search(Movie* k);
};

#endif // BTREE_H