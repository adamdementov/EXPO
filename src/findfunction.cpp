#include "declarations.h"

#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>

using namespace std;

std::string parts_speech[3][3500];

extern string date_time();
void findfunction(){

}

int main() {
    string word;
    cout << "What word do you want to find" << endl;
    cin >> word;

    vector<string> word_files;
    word_files.push_back("~/EXPO/doc/Nouns.txt");
    word_files.push_back("~/EXPO/doc/Adjectives.txt");
    word_files.push_back("~/EXPO/doc/Verbs.txt");


    int i = 0,j = 0;
    string line;

    while (i<3){
        ifstream file((word_files.at(i)).c_str());

        if(file.is_open()){
            cout << date_time() << " [SETUP_ALGORITHM]: File " << word_files.at(i) << " succesfully opened." << endl;

            while(getline(file, line)){
                    parts_speech[i][j] = line;
                    j++;
            }
        }
        else cout << date_time() <<" [ERROR][SETUP_ALGORITHM]: line 27 failure, file did not open." << endl;

        i++;

        file.close();
    }

    cout << date_time() << " [SETUP_ALGORITHM]: Exited function." << endl;
}