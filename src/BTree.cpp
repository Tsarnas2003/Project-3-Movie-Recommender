#include "BTree.h"

// TreeNode functions

TreeNode::TreeNode(int t1, bool leaf1) {
    t = t1;
    leaf = leaf1;
  
    keys = new Movie* [2 * t - 1];
    C = new TreeNode* [2 * t];
  
    n = 0;
}
  
vector<Movie*> movies; // stupid global variable (have to find a solution to this)

void TreeNode::traverse() {
    int i;

    for (i = 0; i < n; i++) {
        if (leaf == false) {
            C[i]->traverse();
        }
        cout << keys[i]->getTitle() << " " << keys[i]->getRank() << endl;
        movies.push_back(keys[i]);
    }
  
    if (leaf == false) {
        C[i]->traverse();
    }
}

vector<Movie*> TreeNode::getMovieRecs() {
    int i;
    int maxRank;
    vector<Movie*> movieRecs;

    maxRank = movies.back()->getRank();

    while (!movies.empty() && movies.back()->getRank() == maxRank) {
        // now the best movie is at the front of the movieRecs vector
        movieRecs.push_back(movies.back());
        movies.pop_back();
    }

    return movieRecs;
}

void TreeNode::insertNonFull(Movie* k) {
    int i = n - 1;
  
    if (leaf == true) {
        while (i >= 0 && keys[i]->getRank() > k->getRank()) {
            keys[i + 1] = keys[i];
            i--;
        }
  
        keys[i + 1] = k;
        n = n + 1;
    } 
    else {
        while (i >= 0 && keys[i]->getRank() > k->getRank()) {
            i--;
        }
  
        if (C[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, C[i + 1]);
  
            if (keys[i + 1]->getRank() < k->getRank()) {
                i++;
            }
        }
        C[i + 1]->insertNonFull(k);
    }
}
  
void TreeNode::splitChild(int i, TreeNode *y) {
    TreeNode *z = new TreeNode(y->t, y->leaf);
    z->n = t - 1;
  
    for (int j = 0; j < t - 1; j++) {
        z->keys[j] = y->keys[j + t];
    }
  
    if (y->leaf == false) {
        for (int j = 0; j < t; j++) {
            z->C[j] = y->C[j + t];
        }
    }
  
    y->n = t - 1;
    for (int j = n; j >= i + 1; j--) {
        C[j + 1] = C[j];
    }
  
    C[i + 1] = z;
  
    for (int j = n - 1; j >= i; j--) {
        keys[j + 1] = keys[j];
    }
  
    keys[i] = y->keys[t - 1];
    n = n + 1;
}

// BTree functions

BTree::BTree(int temp) {
    root = NULL;
    t = temp;
}

void BTree::traverse() {
    if (root != NULL) {
        root->traverse();
    }
}

void BTree::insert(Movie* k) {
    if (root == NULL) {
        root = new TreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } 
    else {
        if (root->n == 2 * t - 1) {
            TreeNode *s = new TreeNode(t, false);
  
            s->C[0] = root;
    
            s->splitChild(0, root);
    
            int i = 0;
            if (s->keys[0]->getRank() < k->getRank()) {
                i++;
            }
            s->C[i]->insertNonFull(k);
    
            root = s;
        } 
        else {
            root->insertNonFull(k);
        }
    }
}

vector<Movie*> BTree::getLast() {
    if (root != NULL) {
        return root->getMovieRecs();
    }

    vector<Movie*> noMovies;
    return noMovies;
}