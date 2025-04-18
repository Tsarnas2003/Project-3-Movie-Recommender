#include "Movie.h"

Movie::Movie(string title, string year, vector<string> genres, int runtime, bool isAdult, string type) {
    this->title = title;
    this->year = year;
    for(string g : genres) { this->genres.insert(g); }
    this->runtime = runtime;
    this->isAdult = isAdult;
    this->type = type;
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

string Movie::getType() {
    return type;
}

int Movie::getRank() {
    return rank;
}

void Movie::addRank(int n) {
    rank += n;
}

void Movie::clearRank() {
    rank = 0;
}


void Movie::updateRank(set<string> inputGenres, string inputYear, string inputIsAdult, string inputRuntime, string inputType) 
{
    const int CURRENT_YEAR = 2025;

    // updates for genres
    for (string genre : inputGenres) {
        if (this->genres.count(genre) == 1) {
            this->rank += 5;
        }
    }

    // updates for year
    if (inputYear == "10") { // released in last 10 years
        if ((CURRENT_YEAR - stoi(this->year)) <= 10) {
            this->rank += 3;
        } 
    } 
    else if (inputYear == "5") { // released in last 5 years
        if ((CURRENT_YEAR - stoi(this->year)) <= 5) {
            this->rank += 3;
        }
    }
    // no points award for "any"

    // updates for isAdult
    if (inputIsAdult == "Y" || inputIsAdult == "y") {
        if (this->isAdult) {
            this->rank += 3;
        }
    } 
    else if (inputIsAdult == "N" || inputIsAdult == "n") {
        if (!this->isAdult) {
            this->rank += 3;
        }
    }

    // updates for runtime
    if (inputRuntime == "short") {
        if (this->runtime <= 90) {
            this->rank += 3;
        }
    } 
    else if (inputRuntime == "medium") {
        if (this->runtime >= 90 && this->runtime <= 120) {
            this->rank += 3;
        }
    }
    else if (inputRuntime == "long") {
        if (this->runtime <= 120) {
            this->rank += 3;
        }
    }
    
    // updates for type
    if (inputType == "movie") {
        if (this->type == "movie") {
            this->rank += 1;
        }
    }
    else if (inputType == "short") {
        if (this->type == "short") {
            this->rank += 1;
        }
    }
    else if (inputType == "tvSeries") {
        if (this->type == "tvSeries") {
            this->rank += 1;
        }
    }
}