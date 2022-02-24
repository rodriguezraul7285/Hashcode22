#include <bits/stdc++.h>

using namespace std;
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

void split(const string& str, const string& delim, vector<string>& parts) { // credits: @Todd Gamblin (stackoverflow.com)
    size_t start, end = 0;
    while (end < str.size()) {
        start = end;
        while (start < str.size() && (delim.find(str[start]) != string::npos)) {
            start++;  // skip initial whitespace
        }
        end = start;
        while (end < str.size() && (delim.find(str[end]) == string::npos)) {
            end++; // skip to end of word
        }
        if (end-start != 0) {  // just ignore zero-length strings.
            parts.push_back(string(str, start, end-start));
        }
    }
}
void printResults(map<string,vector<string>> results){
    ofstream archive;
    archive.open("results.txt");

    archive<<results.size()<<'\n';

    for(const auto &keys:results){
        archive<< keys.first<<'\n';
        for(string a: keys.second)
            archive<<a<<' ';
        archive<<'\n';
    }

    archive.close();

}
void inputFileReading(vector<Contribuitor> &contribuitors, vector<Project> &projects){
    string line;
    int linenum=0;
    int c=1,p=1;
    ifstream readFile ("a_an_example.in.txt");
    if (readFile.is_open())
    {

        getline (readFile, line);
        linenum++;
        vector<string> parts;
        split(line, " ", parts);
        c = stoi(parts[0]);
        p = stoi(parts[1]);
        parts.clear();
        contribuitors.resize(c);
        projects.resize(p);
        // first line

        for (int i = 0; i < c; ++i) {//contribuitors
            getline (readFile, line);
            split(line, " ", parts);
            contribuitors[i].name = parts[0];
            contribuitors[i].skills.resize(stoi(parts[1]));
            parts.clear();
            for (int j = 0; j < contribuitors[i].skills.size(); ++j) {
                getline (readFile, line);
                split(line, " ", parts);
                contribuitors[i].skills[j].name = parts[0];
                contribuitors[i].skills[j].level = stoi(parts[1]);
            }
            parts.clear();
        }
        for (int i = 0; i < p; ++i) {//read the projects
            getline (readFile, line);
            split(line, " ", parts);
            projects[i].name = parts[0];
            projects[i].duration = stoi(parts[1]);
            projects[i].score = stoi(parts[2]);
            projects[i].bestBefore = stoi(parts[3]);
            projects[i].Roles.resize(stoi(parts[4]));
            parts.clear();
            for (int j = 0; j < projects[i].Roles.size(); ++j) { //read the roles in each project
                getline (readFile, line);
                split(line, " ", parts);
                projects[i].Roles[j].name = parts[0];
                projects[i].Roles[j].level = stoi(parts[1]);
                parts.clear();
            }
        }
        readFile.close();
    }

    else cout << "Unable to open file";

}
void createMaps(vector<Contribuitor> &contribuitorsVector,  vector<Project> &projectsVector, map<string, Contribuitor> &contribuitorsMap, map<string, Project> &projectsMap){
    for (Contribuitor contValue: contribuitorsVector){
        contribuitorsMap[contValue.name]=contValue;
    }
    for (Project projectValue: projectsVector){
        projectsMap[projectValue.name] = projectValue;
    }
}


int main () {

    vector<Contribuitor> contribuitorsVector;
    vector<Project> projectsVector;
    inputFileReading(contribuitorsVector, projectsVector);
    map<string, Contribuitor> contribuitorsMap;
    map<string, Project> projectsMap;
    createMaps(contribuitorsVector, projectsVector,contribuitorsMap,projectsMap);



    map<string ,vector<string>> res;
    vector<string> contriS;
    for (int i = 0; i < contribuitorsVector.size(); ++i) {
        contriS.push_back(contribuitorsVector[i].name);
    }
    for (int i = 0; i < projectsVector.size(); ++i) {
        res.insert(pair<string,vector<string>>(projectsVector[i].name, contriS));
    }
    printResults(res);
    return 0;
}