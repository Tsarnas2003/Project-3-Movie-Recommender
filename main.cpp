// This should be in the issue1 branch
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Movie {
    private:
        string title;
        string year;
        vector<string> genres;
        int runtime;
        bool isAdult;

    public:
        Movie(string title, string year, vector<string> genres, int runtime, bool isAdult) {
            this->title = title;
            this->year = year;
            this->genres = genres;
            this->runtime = runtime;
            this->isAdult = isAdult;
        }
};

int main() 
{
    cout << "\n";
    cout << "Ultimate Movie Recommender" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "COP3530 Project 3" << endl;
    cout << "Authors: Jaxon Kundrat, Tyler Tsarnas, Robert Iuhasz" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n";

    vector<Movie> movies = 
    {
        Movie("The Lion King", "1994", { "Animation", "Drama", "Adventure" }, 88, true),
        Movie("Inception", "2010", { "Action", "Sci-Fi", "Thriller" }, 148, false),
        Movie("Finding Nemo", "2003", { "Animation", "Comedy", "Family" }, 100, true),
        Movie("The Dark Knight", "2008", { "Action", "Crime", "Drama" }, 152, false),
        Movie("Frozen", "2013", { "Animation", "Family", "Fantasy" }, 102, true),
        Movie("The Matrix", "1999", { "Action", "Sci-Fi" }, 136, false),
        Movie("Up", "2009", { "Animation", "Adventure", "Comedy" }, 96, true),
        Movie("Titanic", "1997", { "Drama", "Romance" }, 195, false),
        Movie("Shrek", "2001", { "Animation", "Comedy", "Fantasy" }, 90, true),
        Movie("Avengers: Endgame", "2019", { "Action", "Adventure", "Sci-Fi" }, 181, false),
        Movie("Monsters, Inc.", "2001", { "Animation", "Adventure", "Comedy" }, 92, true),
        Movie("The Godfather", "1972", { "Crime", "Drama" }, 175, false),
        Movie("Inside Out", "2015", { "Animation", "Adventure", "Drama" }, 95, true),
        Movie("Jurassic Park", "1993", { "Action", "Adventure", "Sci-Fi" }, 127, false),
        Movie("The Incredibles", "2004", { "Animation", "Action", "Family" }, 115, true),
        Movie("Gladiator", "2000", { "Action", "Adventure", "Drama" }, 155, false),
        Movie("Coco", "2017", { "Animation", "Adventure", "Family" }, 105, true),
        Movie("The Shawshank Redemption", "1994", { "Drama" }, 142, false),
        Movie("Moana", "2016", { "Animation", "Adventure", "Comedy" }, 107, true),
        Movie("The Prestige", "2006", { "Drama", "Mystery", "Sci-Fi" }, 130, false),
        Movie("Zootopia", "2016", { "Animation", "Adventure", "Comedy" }, 108, true),
        Movie("Interstellar", "2014", { "Adventure", "Drama", "Sci-Fi" }, 169, false),
        Movie("Tangled", "2010", { "Animation", "Adventure", "Comedy" }, 100, true),
        Movie("Forrest Gump", "1994", { "Drama", "Romance" }, 142, false),
        Movie("Ratatouille", "2007", { "Animation", "Comedy", "Family" }, 111, true),
        Movie("Pulp Fiction", "1994", { "Crime", "Drama" }, 154, false),
        Movie("Big Hero 6", "2014", { "Animation", "Action", "Adventure" }, 102, true),
        Movie("The Social Network", "2010", { "Biography", "Drama" }, 120, false),
        Movie("WALL-E", "2008", { "Animation", "Adventure", "Family" }, 98, true),
        Movie("The Avengers", "2012", { "Action", "Adventure", "Sci-Fi" }, 143, false)
    };
    
    string movie = "movie_name";
    vector<string> finalMovies;

    string answer1;
    string answer2;
    string answer3;
    string answer4;
    string answer5;

    cout << "1) What genre";
    cin >> answer1;
    cout << "2) What runtime (long or short)";
    cin >> answer2;
    cout << "3) what release year (last 5 years, last 10 years, doesnt matter)";
    cin >> answer3;
    cout << "4) List of actors";
    cin >> answer4;
    cout << "5) What rating (is the movie adult)?";
    cin >> answer5;
    
    // cout << "Animated or live-action"; // "animation is listed as a genre"
    // cout << "What type? (movie, episode, short)";




    cout << "\n";
    cout << "------------------------------------------------------------" << endl;
    cout << "\n";

    // pick random movie from final list
    srand(time(0));
    int randIndex = rand() % finalMovies.size();

    cout << "Your movie is: " + movie << endl;

    return 0;
}