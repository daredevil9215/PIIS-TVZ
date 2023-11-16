#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Filter {

    public:

        vector<vector<double>> pull_csv() {

            string line;
            vector<vector<double>> rez;

            while (getline(cin, line)) {

                vector<double> row;
                istringstream lineStream(line);
                string cell;

                while (getline(lineStream, cell, ',')) {
                    row.push_back(stod(cell));
                }

                rez.push_back(row);

            }

            return rez;
        }

        virtual void modify_csv(vector<vector<double>>& data) = 0;

        void push_csv(vector<vector<double>>& data) {

            for(int i = 0; i < data.size(); i++) {

                for(int j = 0; j < data[i].size(); j++) {

                    if(j == data[i].size() - 1) {
                        cout << data[i][j];
                    }
                    else {
                        cout << data[i][j] << ",";
                    }

                }

                cout << endl;

            }
        }   

};
