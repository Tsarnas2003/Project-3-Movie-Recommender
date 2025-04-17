//
// Created by tbone on 4/17/2025.
//

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>

#include "Movie.h"

class MaxHeap {
private:
    vector<Movie> movies;
    int size;
    int capacity;

public:
    MaxHeap(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->movies.resize(capacity);


    }

    void buildMaxHeap(vector<Movie> inputMovies);


};



#endif //MAXHEAP_H
