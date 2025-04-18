#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>
#include <set>

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
        Movie() {
            title = "";
            year = "";
            genres.clear();
            runtime = 0;
        }
        Movie(string title, string year, vector<string> genres, int runtime, bool isAdult);

        string getTitle();
        string getYear();
        set<string> getGenres();
        int getRuntime();
        bool getIsAdult();
        int getRank();

        void addRank(int n);
        void updateRank(set<string> inputGenres, string inputRange, string inputRating, string inputRunTime, string inputSeriou);
};

#endif // MOVIE_H