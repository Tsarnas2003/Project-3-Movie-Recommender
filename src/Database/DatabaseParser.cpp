#include <iostream>
#include <set>
#include <sstream>
#include <fstream>
#include <map>
#include <vector>
#include <random>

const int BLOCK_SIZE = 50;

using namespace std;

struct Title {
    string titleType;
    string primaryTitle;
    int startYear;
    bool isAdult;
    set<string> genres;
    int runtimeMinutes;
};

/*For some sake of modernity, I made it so that we only include titles more recent
 * than 1950... I don't think we'd want to recommend silent, grained out, black and white films.
 * Can easily change if we wanted to.
 */

bool validYear(string yearStr, int& yearInt){
    if (yearStr == "\\N"){
        return false;
    }
    yearInt = stoi(yearStr);
    return yearInt > 1950;
}

set<string> splitGenres(string genresStr){
    set<string> genres;
    stringstream ss(genresStr);
    string genre;
    while(getline(ss,genre,',')){
        genres.insert(genre);
    }
    return genres;
}

bool parseLine(string line, Title& entry){
    stringstream ss(line);
    string tconst, titleType, primaryTitle, originalTitle, isAdult, startYearStr, endYear, runtimeMinutes, genres;
    getline(ss, tconst, '\t');
    getline(ss, titleType, '\t');
    getline(ss, primaryTitle, '\t');
    getline(ss, originalTitle, '\t');
    getline(ss, isAdult, '\t');
    getline(ss, startYearStr, '\t');
    getline(ss, endYear, '\t');
    getline(ss, runtimeMinutes, '\t');
    getline(ss, genres, '\t');

    int startYear;
    if(validYear(startYearStr,startYear) && (genres != "\\N" && runtimeMinutes != "\\N" && (titleType != "\\N" && (titleType == "tvEpisode" || titleType == "movie" || titleType == "short"))&& primaryTitle != "\\N")){
        entry.titleType = titleType;
        entry.primaryTitle = primaryTitle;
        entry.startYear = startYear;
        isAdult == "0" ? entry.isAdult = 0 : entry.isAdult = 1;
        entry.genres = splitGenres(genres);
        entry.runtimeMinutes = stoi(runtimeMinutes);
    }else{
        return false;
    }
    return true;
}

/* Paths for the files were orginally absolute paths.
 * I wasn't sure how to do this in CLion without absolute paths.
 * After I finished the csv file I replaced the file paths with their relative paths
 * Edit: I set my working directory to the repo and relative paths starting working
 * Not sure how it'll affect you guys so I'll leave this here.
 * (This shouldn't even matter cause the csv file is done...)
 */
void parseDatabase(){
    string input = "src/Database/title.basics.tsv";
    string output = "src/Database/Database.csv";
    ifstream inputFile(input);
    ofstream outputFile(output);
    if (!inputFile || !outputFile){
        cout << "File couldn't open. Bad pathing :(" << endl;
    }
    cout << "File open" << endl;
    string header;
    getline(inputFile,header);

    //This will be confusing and probably not the best way to go about this
    //Will make nested maps to keep track of how many of each title we get so data is evenly distributed
    //map from categories to (genres to title)
    map<string, map<string, vector<Title>>> titleData;
    map<string,int> typeLimits = {{"movie", 10000},{"tvEpisode", 5000},{"short", 5000}};
    string line;
    inputFile.seekg(0,ios::end);
    int tsvSize = inputFile.tellg();
    bool done = false;
    int titleCounter = 0;
    while (!done){
        int randomPos = (rand() * rand()) % tsvSize;
        string line;
        int counter = 0;
        inputFile.clear();
        //initial position may be in the middle of a line
        inputFile.seekg(randomPos, ios::beg);
        string throwAway;
        getline(inputFile, throwAway);
        while (counter < BLOCK_SIZE && getline(inputFile,line)){
            counter++;
            Title entry;
            if (!parseLine(line, entry)){
                continue;
            }
            string titleType = entry.titleType;
            int typeCounter = 0;
            if (titleCounter > 20000){
                done = true;
                break;
            }
            for (auto genrePair : titleData[titleType]){
                typeCounter += genrePair.second.size();
            }
            if (typeCounter > typeLimits[titleType]){
                continue;
            }
            for (auto genre : entry.genres){
                titleData[titleType][genre].push_back(entry);
                titleCounter++;
            }
        }
    }
    for (auto category : titleData){
        for (auto genre : category.second){
            for (auto entry :genre.second){
                outputFile << entry.primaryTitle << "," << entry.startYear << ",{";
                for (auto it = entry.genres.begin(); it != entry.genres.end(); it++){
                    outputFile << *it << (next(it) == entry.genres.end() ? "" : ",");
                }
                outputFile << "}," << entry.runtimeMinutes << "," << entry.isAdult << "," << entry.titleType << "\n";
            }
        }
    }
    return;
}

int main(){
    parseDatabase();
    return 0;
}