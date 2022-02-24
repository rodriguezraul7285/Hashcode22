#include <bits/stdc++.h>

using namespace std;

/*
int main () {
    ofstream writeFile ("a_an_example.in.txt");
    if (writeFile.is_open())
    {
        writeFile << "This is a line.\n";
        writeFile << "This is another line.\n";
        writeFile.close();
    }
    else cout << "Unable to open file";
    return 0;
}*/

void inputFileReading(){
    string line;
    ifstream readFile ("a_an_example.in.txt");
    if (readFile.is_open())
    {
        while ( getline (readFile, line) )
        {
            cout << line << '\n';
        }
        readFile.close();
    }

    else cout << "Unable to open file";

}
struct Skill{
    string name;
    short level;
};
struct Contribuitor{
    string name;
    vector<Skill> skills;
};
struct Project{
    string name;
    int duration;
    int score;
    int bestBefore;
    vector<Skill> Roles;
};


int main () {
    int C=0,P=0;//contributors and proyects.



    return 0;
}