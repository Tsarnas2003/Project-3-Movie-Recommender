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
        string type;

        int rank;

    public:
        Movie(string title, string year, vector<string> genres, int runtime, bool isAdult, string type);

        string getTitle();
        string getYear();
        set<string> getGenres();
        int getRuntime();
        bool getIsAdult();
        string getType();
        
        int getRank();
        void addRank(int n);
        void updateRank(set<string> inputGenres, string inputYear, string inputIsAdult, string inputRuntime, string inputType);
};

#endif // MOVIE_H