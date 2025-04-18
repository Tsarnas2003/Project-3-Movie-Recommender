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
    vector<Movie> movieList;
    int size;
    int capacity;

public:
    MaxHeap(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        this->movieList.resize(capacity);

    }

    void buildMaxHeap(vector<Movie>& inputMovies);
    void insert(Movie& movie);
    Movie top();
    Movie pop();
    void heapifyDown(int index);
    void heapifyUp(int index);
    void print();
    vector<Movie> getBestRanks();








};



#endif //MAXHEAP_H
