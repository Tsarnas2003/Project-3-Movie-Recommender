#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>

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
/*
    vector<Movie> movies = {
        Movie("The Lion King", "1994", { "Animation", "Drama", "Adventure" }, 88, false, "movie"),
        Movie("Inception", "2010", { "Action", "Sci-Fi", "Thriller" }, 148, true, "movie"),
        Movie("Finding Nemo", "2003", { "Animation", "Comedy", "Family" }, 100, false, "movie"),
        Movie("The Dark Knight", "2008", { "Action", "Crime", "Drama" }, 152, true, "movie"),
        Movie("Frozen", "2013", { "Animation", "Family", "Fantasy" }, 102, false, "movie"),
        Movie("The Matrix", "1999", { "Action", "Sci-Fi" }, 136, true, "movie"),
        Movie("Up", "2009", { "Animation", "Adventure", "Comedy" }, 96, false, "movie"),
        Movie("Titanic", "1997", { "Drama", "Romance" }, 195, true, "movie"),
        Movie("Shrek", "2001", { "Animation", "Comedy", "Fantasy" }, 90, false, "movie"),
        Movie("Avengers: Endgame", "2019", { "Action", "Adventure", "Sci-Fi" }, 181, true, "movie"),
        Movie("Monsters, Inc.", "2001", { "Animation", "Adventure", "Comedy" }, 92, false, "movie"),
        Movie("The Godfather", "1972", { "Crime", "Drama" }, 175, true, "movie"),
        Movie("Inside Out", "2015", { "Animation", "Adventure", "Drama" }, 95, false, "movie"),
        Movie("Jurassic Park", "1993", { "Action", "Adventure", "Sci-Fi" }, 127, true, "movie"),
        Movie("The Incredibles", "2004", { "Animation", "Action", "Family" }, 115, false, "movie"),
        Movie("Gladiator", "2000", { "Action", "Adventure", "Drama" }, 155, true, "movie"),
        Movie("Coco", "2017", { "Animation", "Adventure", "Family" }, 105, false, "movie"),
        Movie("The Shawshank Redemption", "1994", { "Drama" }, 142, true, "movie"),
        Movie("Moana", "2016", { "Animation", "Adventure", "Comedy" }, 107, false, "movie"),
        Movie("The Prestige", "2006", { "Drama", "Mystery", "Sci-Fi" }, 130, true, "movie"),
        Movie("Zootopia", "2016", { "Animation", "Adventure", "Comedy" }, 108, false, "movie"),
        Movie("Interstellar", "2014", { "Adventure", "Drama", "Sci-Fi" }, 169, true, "movie"),
        Movie("Tangled", "2010", { "Animation", "Adventure", "Comedy" }, 100, false, "movie"),
        Movie("Forrest Gump", "1994", { "Drama", "Romance" }, 142, true, "movie"),
        Movie("Ratatouille", "2007", { "Animation", "Comedy", "Family" }, 111, false, "movie"),
        Movie("Pulp Fiction", "1994", { "Crime", "Drama" }, 154, true, "movie"),
        Movie("Big Hero 6", "2014", { "Animation", "Action", "Adventure" }, 102, false, "movie"),
        Movie("The Social Network", "2010", { "Biography", "Drama" }, 120, true, "movie"),
        Movie("WALL-E", "2008", { "Animation", "Adventure", "Family" }, 98, false, "movie"),
        Movie("The Avengers", "2012", { "Action", "Adventure", "Sci-Fi" }, 143, true, "movie")
    };
*/
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
        
        BTree t(50);// TODO: switch to 50 once you get bigger data set
        MaxHeap maxHeap(movies.size());
        
        for (Movie& m : movies) {
            m.updateRank(genres, answer3, answer4, answer2, answer5);
            if(structure == "tree") {
                t.insert(new Movie(m));
            }
        }

        if(structure == "tree") {
            t.traverse();
            vector<Movie*> bTreeRecs = t.getLast();
            string another;

            // if there are other movies with the same maxRank, ask another question
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
        }else if (structure == "heap"){
            maxHeap.buildMaxHeap(movies);
            //MaxHeap test = maxHeap;
            //test.print();
            vector<Movie> heapRecs = maxHeap.getBestRanks();



            cout << "\n";

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