#include "Movie.h"

Movie::Movie(string title, string year, vector<string> genres, int runtime, bool isAdult) {
    this->title = title;
    this->year = year;
    for(string g : genres) {
        this->genres.insert(g);
    }
    this->runtime = runtime;
    this->isAdult = isAdult;
    this->rank = 0;
}

string Movie::getTitle() {
    return title;
}

string Movie::getYear() {
    return year;
}

set<string> Movie::getGenres() {
    return genres;
}

int Movie::getRuntime() {
    return runtime;
}

bool Movie::getIsAdult() {
    return isAdult;
}

int Movie::getRank() {
    return rank;
}

void Movie::addRank(int n) {
    rank += n;
}

void Movie::updateRank(set<string> inputGenres, string inputRange, string inputRating, string inputRunTime, string inputSerious) 
{
    const int CURRENT_YEAR = 2025;

    // updates for genres
    for(string genre : inputGenres) {
        if(this->genres.count(genre) == 1) {
            this->rank += 5;
        }
    }

    // updates for year
    if (inputRange == "10") {
        if((CURRENT_YEAR - stoi(this->year)) <= 10) {
            this->rank += 3;
        } 
    } 
    else if (inputRange == "5") {
        if((CURRENT_YEAR - stoi(this->year)) <= 5) {
            this->rank += 3;
        }
    }

    // updates for isAdult
    if(inputRating == "yes") {
        if(this->isAdult) {
            this->rank += 3;
        }
    } 
    else if(inputRating == "no") {
        if(!this->isAdult) {
            this->rank += 3;
        }
    }

    // updates for runtime
    if(inputRunTime == "short") {
        if(this->runtime <= 90) {
            this->rank += 3;
        }
    } 
    else if (inputRunTime == "long") {
        if(this->runtime <= 120) {
            this->rank += 3;
        }
    }
    else if (inputRunTime == "medium") {
        if(this->runtime >= 90 && this->runtime <= 120) {
            this->rank += 3;
        }
    }

    // still need updates for serious/lighthearted
}