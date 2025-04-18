//
//
//

#include "MaxHeap.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>
#include "Movie.h"

using namespace std;

void MaxHeap::buildMaxHeap(vector<::Movie>& inputMovies) {
    capacity = inputMovies.size();
    size = capacity;
    movieList = inputMovies;

    for(int i = (size -1)/2; i >= 0; i--) {
        heapifyDown(i);
    }

}




void MaxHeap::insert(Movie& movie) {
    if(size == capacity) {
        capacity *= 2;
        movieList.resize(capacity);
    }
    size++;

    int index = size -1;
    movieList[index] = movie;

    while(index != 0 && movieList[(index-1)/2].getRank() <movieList[index].getRank()) {
        swap(movieList[index], movieList[(index-1)/2]);
        index = (index-1)/2;
    }

}

void MaxHeap :: heapifyDown(int index) { // when removing a node you need to fix heap
    int left = 2 * index + 1; // left child
    int right = 2 * index + 2; // right child
    int largest = index;



    if(left < size && movieList[left].getRank() > movieList[largest].getRank()) {
        largest = left;
    }

    if(right < size && movieList[right].getRank() > movieList[largest].getRank()) {
        largest = right;
    }

    if(largest != index) {
        swap(movieList[index], movieList[largest]);
        heapifyDown(largest);
    }

}

// Cite edugator lesson on heaps
void MaxHeap::heapifyUp(int index) {
    int parent = (index - 1) / 2;

    while(index > 0 && movieList[parent].getRank() < movieList[index].getRank()) {
        swap(movieList[index], movieList[parent]);
        index = parent;
        parent = (index - 1) / 2;

    }
}


Movie MaxHeap :: top() {
    if(size <= 0) {
        throw runtime_error("Empty MaxHeap");
    }
    return movieList[0];
}


Movie MaxHeap :: pop() {
    if(size <= 0) {
        throw runtime_error("Empty MaxHeap");
    }


    Movie root = movieList[0];
    movieList[0] = movieList[size - 1];
    size--;
    heapifyDown(0);
    return root;

}

void MaxHeap::print() {
    while(size > 0) {
        Movie m = pop();
        cout << m.getTitle()<< " " << m.getRank() << endl;
    }
}



vector<Movie> MaxHeap :: getBestRanks() {
    vector<Movie> bestRanks;
    int highestRank = movieList[0].getRank();

    while(movieList[0].getRank() == highestRank) {
        bestRanks.push_back(pop());
    }

    return bestRanks;
}




