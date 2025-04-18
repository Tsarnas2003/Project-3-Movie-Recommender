// This should be in the issue1 branch
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>

#include "Movie.h"
#include "BTree.h"
#include "Maxheap.h"

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

    vector<Movie> movies = {
        Movie("The Lion King", "1994", { "Animation", "Drama", "Adventure" }, 88, false),
        Movie("Inception", "2010", { "Action", "Sci-Fi", "Thriller" }, 148, true),
        Movie("Finding Nemo", "2003", { "Animation", "Comedy", "Family" }, 100, false),
        Movie("The Dark Knight", "2008", { "Action", "Crime", "Drama" }, 152, true),
        Movie("Frozen", "2013", { "Animation", "Family", "Fantasy" }, 102, false),
        Movie("The Matrix", "1999", { "Action", "Sci-Fi" }, 136, true),
        Movie("Up", "2009", { "Animation", "Adventure", "Comedy" }, 96, false),
        Movie("Titanic", "1997", { "Drama", "Romance" }, 195, true),
        Movie("Shrek", "2001", { "Animation", "Comedy", "Fantasy" }, 90, false),
        Movie("Avengers: Endgame", "2019", { "Action", "Adventure", "Sci-Fi" }, 181, true),
        Movie("Monsters, Inc.", "2001", { "Animation", "Adventure", "Comedy" }, 92, false),
        Movie("The Godfather", "1972", { "Crime", "Drama" }, 175, true),
        Movie("Inside Out", "2015", { "Animation", "Adventure", "Drama" }, 95, false),
        Movie("Jurassic Park", "1993", { "Action", "Adventure", "Sci-Fi" }, 127, true),
        Movie("The Incredibles", "2004", { "Animation", "Action", "Family" }, 115, false),
        Movie("Gladiator", "2000", { "Action", "Adventure", "Drama" }, 155, true),
        Movie("Coco", "2017", { "Animation", "Adventure", "Family" }, 105, false),
        Movie("The Shawshank Redemption", "1994", { "Drama" }, 142, true),
        Movie("Moana", "2016", { "Animation", "Adventure", "Comedy" }, 107, false),
        Movie("The Prestige", "2006", { "Drama", "Mystery", "Sci-Fi" }, 130, true),
        Movie("Zootopia", "2016", { "Animation", "Adventure", "Comedy" }, 108, false),
        Movie("Interstellar", "2014", { "Adventure", "Drama", "Sci-Fi" }, 169, true),
        Movie("Tangled", "2010", { "Animation", "Adventure", "Comedy" }, 100, false),
        Movie("Forrest Gump", "1994", { "Drama", "Romance" }, 142, true),
        Movie("Ratatouille", "2007", { "Animation", "Comedy", "Family" }, 111, false),
        Movie("Pulp Fiction", "1994", { "Crime", "Drama" }, 154, true),
        Movie("Big Hero 6", "2014", { "Animation", "Action", "Adventure" }, 102, false),
        Movie("The Social Network", "2010", { "Biography", "Drama" }, 120, true),
        Movie("WALL-E", "2008", { "Animation", "Adventure", "Family" }, 98, false),
        Movie("The Avengers", "2012", { "Action", "Adventure", "Sci-Fi" }, 143, true),
        Movie("The Lion King 2: Simba's Pride", "1998", { "Animation", "Drama", "Adventure" }, 81, false),
        Movie("The Dark Knight Rises", "2012", { "Action", "Crime", "Drama" }, 164, true),
        Movie("The Hobbit: An Unexpected Journey", "2012", { "Adventure", "Fantasy" }, 169, true),
        Movie("Spider-Man: Into the Spider-Verse", "2018", { "Animation", "Action", "Sci-Fi" }, 117, false),
        Movie("The Chronicles of Narnia: The Lion, the Witch and the Wardrobe", "2005", { "Adventure", "Family", "Fantasy" }, 143, true),
        Movie("Avatar", "2009", { "Action", "Adventure", "Sci-Fi" }, 162, true),
        Movie("Frozen II", "2019", { "Animation", "Adventure", "Fantasy" }, 103, false),
        Movie("The Incredibles 2", "2018", { "Animation", "Action", "Adventure" }, 118, false),
        Movie("The Silence of the Lambs", "1991", { "Crime", "Drama", "Thriller" }, 118, true),
        Movie("Toy Story 4", "2019", { "Animation", "Adventure", "Comedy" }, 100, false),
        Movie("Jurassic World", "2015", { "Action", "Adventure", "Sci-Fi" }, 124, true),
        Movie("Harry Potter and the Sorcerer's Stone", "2001", { "Adventure", "Fantasy" }, 152, true),
        Movie("The Grand Budapest Hotel", "2014", { "Comedy", "Drama", "Crime" }, 99, false),
        Movie("Mad Max: Fury Road", "2015", { "Action", "Adventure", "Sci-Fi" }, 120, true),
        Movie("The Princess Bride", "1987", { "Adventure", "Comedy", "Fantasy" }, 98, false),
        Movie("Guardians of the Galaxy", "2014", { "Action", "Adventure", "Comedy" }, 121, true),
        Movie("Star Wars: The Empire Strikes Back", "1980", { "Action", "Adventure", "Sci-Fi" }, 124, true),
        Movie("Back to the Future", "1985", { "Adventure", "Comedy", "Sci-Fi" }, 116, true),
        Movie("A Beautiful Mind", "2001", { "Biography", "Drama" }, 135, true),
        Movie("The Revenant", "2015", { "Adventure", "Drama", "Thriller" }, 156, true),
        Movie("The Pursuit of Happyness", "2006", { "Biography", "Drama" }, 117, true),
        Movie("Django Unchained", "2012", { "Drama", "Western" }, 165, true),
        Movie("Shutter Island", "2010", { "Drama", "Mystery", "Thriller" }, 138, true)
    };
    
    string answer1, answer2, answer3, answer4, answer5;
    set<string> genres;

    // QUESTION #1
    cout << "1) What genre (Choose from Animation, Drama, Adventure, Comedy, Horror, Romance, Action, Family)?\n "; // maybe give a list of options for this one and let user do multiple
    cout << "Enter multiple genres seperated by comas (e.g, Action,Comedy)\n";
    getline(cin, answer1);
    stringstream ss(answer1);
    string choice;
    while(getline(ss, choice, ',')) {
        choice.erase(remove_if(choice.begin(), choice.end(), ::isspace),choice.end());
        genres.insert(choice);
    }

    // QUESTION #2
    cout << "2) What runtime (long or short or medium)\n";  // <90 min = short, 90-120 = medium, >120 = long
    cin >> answer2;

    // QUESTION #3
    cout << "3) What release range do you prefer?\n";
    cout << "Options: Last 5 years, Last 10 years, any\n";
    cout << "Enter 5, 10, or any\n";
    cin >> answer3;

    // QUESTION #4
    cout << "4) What rating (is the movie adult)?\n"; // boolean
    cin >> answer4;

    // QUESTION #5
    cout << "5) Do you want a Movie, a short Movie, or a Tv episode?\n";
    cout << "Enter Moive, Tv, or short\n";
    // lighthearted = comedy,animation, romance, family
    // serious = drama, thriller, War, Crime, Horror
    cin >> answer5;                                            
    
    // EXTRA QUESTIONS:
    // cout << "Animated or live-action"; // "animation is listed as a genre"
    // cout << "What type? (movie, episode, short)";

    cout << "\n";
    cout << "------------------------------------------------------------" << endl;
    cout << "\n";
    
    //BTree t(3); // switch to 50 once you get bigger data set
    //Movie finalMovie = *t.getLast();
    MaxHeap testHeap(movies.size());


    // pick random movie from final list
    //srand(time(0));
    //int randIndex = rand() % finalMovies.size();


    for(Movie &m : movies) {
        m.updateRank(genres, answer3, answer4, answer2, answer5);
        //t.insert(m);


        //cout << m.getTitle() << " " << m.getRank() << endl;
    }

    testHeap.buildMaxHeap(movies);
    testHeap.print();
    //cout << "Your movie is: " + finalMovie.getTitle() + " " + to_string(finalMovie.getRank()) << endl;

    return 0;
}