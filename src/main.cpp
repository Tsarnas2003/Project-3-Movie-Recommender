#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>
#include <chrono>

#include "Movie.h"
#include "BTree.h"
#include "MaxHeap.h"

#include "Database/DatabaseParser.cpp"

using namespace std;

int main() 
{
    cout << "\n";
    cout << "Ultimate Movie Recommender" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "COP3530 Project 3" << endl;
    cout << "Authors: Jaxon Kundrat, Tyler Tsarnas, Robert Iuhasz" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n";

    bool again = true;
    vector<Movie> movies = csvParser();
    while (again)
    {
        again = false;
        string structure;
        cout << "Would you like the use the Heap or the B Tree" << endl;
        cout << "Enter Heap or Tree" << endl;
        cin >> structure;



        string answer1, answer2, answer3, answer4, answer5;
        set<string> genres;

        /*
            QUESTION #1
            - ask for list of genres
            - search for movies with the most of the inputted genres
        */
        cout << "1) What genre are you interested in?" << endl;
        cout << "OPTIONS: Animation, Drama, Adventure, Comedy, Horror, Romance, Action, Family" << endl;
        cout << "(Enter multiple genres seperated by comma, i.e Action,Comedy)" << endl;
        cin >> answer1;
        
        stringstream ss(answer1);
        string choice;
        while(getline(ss, choice, ',')) {
            genres.insert(choice);
        }

        /*
            QUESTION #2
            - ask for runtime
            - short = <90 minute, medium = 90-120 minutes, long = >120 minutes
        */ 
        cout << "2) How long should the movie be?" << endl;
        cout << "OPTIONS: short, medium, long" << endl;
        cin >> answer2;

        /*
            QUESTION #3
            - ask for release year
            - movies released within last 5 years, last 10 years, or any
        */
        cout << "3) What release range do you prefer?" << endl;
        cout << "OPTIONS: Released in last 5 years, Released in last 10 years, Release any time" << endl;
        cout << "(Enter 5, 10, or any)" << endl;
        cin >> answer3;

        /*
            QUESTION #4
            - ask whether the movie is for adult audiences
            - Y = PG-13/R movies, N = G/PG movies
        */
        cout << "4) Would you like your movie to be for an adult audience?" << endl;
        cout << "OPTIONS: Y, N" << endl;
        cout << "(Adult = PG-13/R, Not Adult = G/PG)" << endl;
        cin >> answer4;

        /*
            QUESTION #5
            - ask for the type of the movie
            - only search for movie, short, or tvSeries (ignore other types)
        */
        cout << "5) What format should your movie be?" << endl;
        cout << "OPTIONS: movie, short, tvSeries" << endl;
        cin >> answer5;                                            

 
        cout << "\n------------------------------------------------------------\n" << endl;
        cout << "Results:" << endl;
        cout << "\n";

        if(structure == "Tree") {
            auto start = chrono::high_resolution_clock::now();
            BTree t(50);
            for (Movie& m : movies) {
                m.updateRank(genres, answer3, answer4, answer2, answer5);
                t.insert(new Movie(m));
            }
            t.traverse();
            vector<Movie*> bTreeRecs = t.getLast();
            auto end = chrono::high_resolution_clock::now();
            string another;

            // if there are other movies with the same maxRank, ask another question
            chrono::duration<double,milli> duration = end - start;
            cout << "Tree build and access time is: " << duration.count() << "ms." << endl;
            for (int i = 0; i < bTreeRecs.size(); i++) {
                cout << "Your movie is: " << bTreeRecs[i]->getTitle() << endl;
                cout << "With rank: " << bTreeRecs[i]->getRank() << endl;
                cout << "\n";

                if (i != bTreeRecs.size() - 1) {
                    cout << "Would you like another movie based on your inputs? (Y/N): ";
                    cin >> another;
                    if (another == "N" || another == "n") {
                        break;
                    }
                }
            }

            // ask if user would like another run
            cout << "Would you like run the Movie Recommender again? (Y/N): ";
            cin >> another;
            if (another == "Y" || another == "y") {
                again = true;
            }

            cout << "\n------------------------------------------------------------\n" << endl;
            for(Movie& m : movies) {
                m.clearRank();
            }
        }else if (structure == "Heap"){
            auto start = chrono::high_resolution_clock::now();
            MaxHeap maxHeap(movies.size());
            for (Movie& m : movies) {
                m.updateRank(genres, answer3, answer4, answer2, answer5);
            }
            maxHeap.buildMaxHeap(movies);
            vector<Movie> heapRecs = maxHeap.getBestRanks();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double,milli> duration = end - start;

            cout << "\n";
            cout << "Heap build and access time is: " << duration.count() << "ms." << endl;

            string another;

            // if there are other movies with the same maxRank, ask another question
            for (int i = 0; i < heapRecs.size(); i++) {
                cout << "Your movie is: " << heapRecs[i].getTitle() << endl;
                cout << "With rank: " << heapRecs[i].getRank() << endl;
                cout << "\n";

                if (i != heapRecs.size() - 1) {
                    cout << "Would you like another movie based on your inputs? (Y/N): ";
                    cin >> another;
                    if (another == "N" || another == "n") {
                        break;
                    }
                }
            }

            // ask if user would like another run
            cout << "Would you like run the Movie Recommender again? (Y/N): ";
            cin >> another;
            if (another == "Y" || another == "y") {
                again = true;
            }

            cout << "\n------------------------------------------------------------\n" << endl;
            for(Movie& m : movies) {
                m.clearRank();
            }
        }
    }

    return 0;
}