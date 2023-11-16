#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "json.hpp"

using namespace std;
using namespace nlohmann;

class Application {

    public:

    virtual void load_data() = 0;

    virtual void modify_data() = 0;

    virtual void save_data() = 0;

    void run() {

        load_data();
        modify_data();
        save_data();

    }

};

class DataModifier : public Application {

    public:

    vector<vector<string>> data_csv;
    json data_json;
    ifstream inputFile;
    ofstream outputFile;
    string path;

    DataModifier(string input, string output) {
        inputFile = ifstream(input);
        outputFile = ofstream(output);
        path = input;
    }

    void load_data() override {

        if(path[path.size() - 1] == 'v') {
            cout << path[path.size() - 1];
            load_csv();
        }
        else if(path[path.size() - 1] == 'n') {
            cout << path[path.size() - 1];
            load_json();
        }

    }

    void modify_data() override {

        if(path[path.size() - 1] == 'v') {
            modify_csv();
        }
        else if(path[path.size() - 1] == 'n') {
            modify_json();
        }
        
    }

    void save_data() override {

        if(path[path.size() - 1] == 'v') {
            save_csv();
        }
        else if(path[path.size() - 1] == 'n') {
            save_json();
        }

    }

    void load_json() {
        data_json = json::parse(inputFile);
    }

    void load_csv() {

        string line;

        while (getline(inputFile, line)) {

            vector<string> row;
            istringstream lineStream(line);
            string cell;

            while (getline(lineStream, cell, ',')) {
                row.push_back(cell);
            }

            data_csv.push_back(row);

        }
    }

    void modify_csv() {

        for (int i = 0; i < data_csv.size(); i++){

            for(int j = 0; j < data_csv[i].size(); j++) {

                for(int k = 0; k < data_csv[i][j].size(); k++) {

                    data_csv[i][j][k] += 1;

                }

            }

        }
    }

    void modify_json() {

        for(auto i = data_json.begin(); i != data_json.end(); i++) {

            string vrijednost = i.value();

            for(int i = 0; i < vrijednost.size(); i++)  {
                vrijednost[i] += 1;
            }

            data_json[i.key()] = vrijednost;

        }
    }

    void save_csv() {

        for(vector<string> row : data_csv) {

            for(int i = 0; i < row.size(); i++) {

                outputFile << row[i];

                if(i < row.size() - 1) {

                    outputFile << ",";

                }

            }

            outputFile << "\n";

        }
    }

    void save_json() {
        outputFile << data_json;
    }

};

int main() {

    DataModifier modifier("../data/ulaz.csv", "../data/izlaz.csv");
    
    modifier.run();

}