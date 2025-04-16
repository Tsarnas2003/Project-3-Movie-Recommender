// This should be in the issue1 branch
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Movie {
    private:
        string title;
        string year;
        string genre;
        string director;
        vector<string> actors;
        int runtime;

    public:
        Movie(string title, string year, string genre, string director, vector<string> actors, int runtime) {
            this->title = title;
            this->year = year;
            this->genre = genre;
            this->director = director;
            this->actors = actors;
            this->runtime = runtime;
        }
};

class Question {
    private:
        string question;

    public:
        Question(string question) {
            this->question = question;
            
        }
};

int main() 
{
    //system("Color 02");
    cout << "\n";
    cout << "Ultimate Movie Recommender" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "COP3530 Project 3" << endl;
    cout << "Authors: Jaxon Kundrat, Tyler Tsarnas, Robert Iuhasz" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n";

    vector<string> questions = {
        "Do you speak English?",
        "Are you feeling happy today? (Y/N):",
        "How patient are you feeling on a scale of 1-10?",
        "Pick a number 1-10?",
        "What's your favorite color?"
    };

    /*
    Small list of direct questions:
    1. What language?
    2. Do you like director X?
    3. What genre are you interested in?
    4. How old would you like the movie to be?
    5. What movie rating would you like? 
    */

    string movie = "movie_name";
    srand(time(0));
    int randIndex = -1;

    cout << "What genre";
    cout << "What runtime (long or short)";
    cout << "what release year (last 5 years, last 10 years, doesnt matter)";
    cout << "List of actors";
    cout << "What language (English, Spanish, doesn't matter)?";

    for (int i = 1; i <= 5; i++)
    {
        randIndex = rand() % questions.size();
        cout << to_string(i) + ") " + questions[randIndex] << endl;
        questions.erase(questions.begin() + randIndex);
        
        string answer;
        cin >> answer;
    }

    cout << "\n";
    cout << "------------------------------------------------------------" << endl;
    cout << "\n";

    cout << "Your movie is: " + movie << endl;

    return 0;
}