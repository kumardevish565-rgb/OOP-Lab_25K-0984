#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ifstream file("article.txt");
    if(!file.is_open()) {
        cerr << "Error opening file article.txt\n";
        return 1;
    }
    int chCount=0,wordCount=0,punctCount=0,lineCount=0;
    string line;
    while(getline(file,line)) {
        lineCount++;
        chCount+=line.length();
        size_t pos=0;
        while((pos=line.find_first_of(".!?,-;:",pos))!=string::npos){
            punctCount++;
            line[pos++]=' ';
        }
        istringstream ss(line);
        string word;
        while (ss >> word) {
            wordCount++;
        }
    }
    file.close();
    ofstream newFile("report.txt");
    if(newFile.is_open()) {
        newFile << "Total Characters:" << chCount << "\nTotal Words:" << wordCount << "\nTotal Lines:" << lineCount << "\nNo of Punctuation Marks:" << punctCount << endl;
    }
    else {
        cout << "Error opening file report.txt\n";
        return 1;
    }
    return 0;
}