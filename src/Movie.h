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
        Movie() {
            title = " ";
            year = " ";

        };
        Movie(string title, string year, vector<string> genres, int runtime, bool isAdult, string type);

        string getTitle();
        string getYear();
        set<string> getGenres();
        int getRuntime();
        bool getIsAdult();
        void clearRank();
        string getType();

        void setTitle(string title);
        void setYear(string year);
        void setGenres(set<string> genres);
        void setRuntime(int runtime);
        void setAdult(bool isAdult);
        void setType(string type);
        
        int getRank();
        void addRank(int n);
        void updateRank(set<string> inputGenres, string inputYear, string inputIsAdult, string inputRuntime, string inputType);
};

#endif // MOVIE_H