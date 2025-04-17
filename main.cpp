// This should be in the issue1 branch
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

class Movie {
    private:
        string title;
        string year;
        set<string> genres;
        int runtime;
        bool isAdult;
        int rank;

    public:
        Movie(string title, string year, vector<string> genres, int runtime, bool isAdult) {
            this->title = title;
            this->year = year;
            for(string g : genres) {
                this->genres.insert(g);
            }
            this->runtime = runtime;
            this->isAdult = isAdult;
            rank = 0;
        }


        set<string> getGenres() {
            return genres;
        }

        string getTitle() {
            return title;
        }
        int getRuntime() {
            return runtime;
        }

        string getYear() {
            return year;
        }

        bool getIsAdult() {
            return isAdult;
        }

        int getRank() {
            return rank;
        }

        void addRank(int n) {
            rank += n;
        }




};


void updateRanks(Movie &movie, set<string> genre, string range, string rating,string runTime, string serious) {
    int currentYear = 2025;
    for(string gen : genre) {
        if(movie.getGenres().count(gen) == 1) {            // updates for genres
            movie.addRank(5);
        }
    }




    if (range == "10") {
        if((currentYear - stoi(movie.getYear())) <= 10) {
            movie.addRank(3);
        }                                                                      // updates for year

    } else if (range == "5") {
        if((currentYear - stoi(movie.getYear())) <= 5) {
            movie.addRank(3);
        }
    }



    if(rating == "yes") {
        if(movie.getIsAdult()) {
            movie.addRank(3);
        }                                                                   // updates for isAdult
    } else if(rating == "no") {
        if(!movie.getIsAdult()) {
            movie.addRank(3);
        }
    }


    if(runTime == "short") {
        if(movie.getRuntime() <= 90) {
            movie.addRank(3);
        }
    } else if (runTime == "long") {
        if(movie.getRuntime() <= 120) {
            movie.addRank(3);                               // updates for runtime
        }
    }
    else if (runTime == "medium") {
        if(movie.getRuntime() >= 90 && movie.getRuntime() <= 120) {
            movie.addRank(3);
        }
    }






}

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

    set<string> genres;


    string answer1;
    string answer2;
    string answer3;
    string answer4;
    string answer5;

    cout << "1) What genre (Choose from Animation, Drama, Adventure, Comedy, Horror, Romance, Action, Family)?\n "; // maybe give a list of options for this one and let user do multiple
    cout << "Enter multiple genres seperated by comas (e.g, Action,Comedy)\n";
    getline(cin, answer1);
    stringstream ss(answer1);
    string choice;
    while(getline(ss, choice, ',')) {
        choice.erase(remove_if(choice.begin(), choice.end(), ::isspace),choice.end());
        genres.insert(choice);

    }


    //cin >> answer1;
    cout << "2) What runtime (long or short or medium)\n";  // <90 min = short, 90-120 = medium, >120 = long
    cin >> answer2;
    cout << "3) what release range do you prefer?\n";
    cout << "Options: Last 5 years, Last 10 years, any\n";
    cout << "Enter 5, 10, or any\n";
    cin >> answer3;
    cout << "4) What rating (is the movie adult)?\n"; // boolean
    cin >> answer4;
    cout << "5) Do you want something lighthearted or serious\n"; // lighthearted = comedy,animation, romance, family
    cin >> answer5;                                             // serious = drama, thriller, War, Crime, Horror
    
    // cout << "Animated or live-action"; // "animation is listed as a genre"
    //
    // cout << "What type? (movie, episode, short)";

    // Testing

    for (auto g : genres) cout << g << "\n";
    cout << answer2 << endl;
    cout << answer3 << endl;
    cout << answer4 << endl;
    cout << answer5 << endl;


// another question to help

    cout << "\n";
    cout << "------------------------------------------------------------" << endl;
    cout << "\n";

    // pick random movie from final list
    //srand(time(0));
    //int randIndex = rand() % finalMovies.size();

    cout << "Your movie is: " + movie << endl;



    // testing update ranks

    for(Movie& m : movies) {
        updateRanks(m,genres, answer3, answer4, answer2, answer5);
    }


    for (Movie m : movies) {
        cout << m.getTitle() << " " << m.getRank() << endl;
    }



    return 0;
}







