#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include "filter.hpp"

using namespace std;

class FilterSquare : public Filter {

    public:

        void modify_csv(vector<vector<double>>& data) override {
        
        for(int i = 0; i < data.size(); i++) {

            for(int j = 0; j < data[i].size(); j++) {

                data[i][j]  = 1 / (1 + exp(-data[i][j]));

            }   

        }

    };

};

int main() {

    FilterSquare filter;
    vector<vector<double>> data = filter.pull_csv();
    filter.modify_csv(data);
    filter.push_csv(data);
    
}
