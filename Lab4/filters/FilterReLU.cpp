#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "filter.hpp"

using namespace std;

class FilterReLU : public Filter {

    public:

        void modify_csv(vector<vector<double>>& data) override {
        
        for(int i = 0; i < data.size(); i++) {

            for(int j = 0; j < data[i].size(); j++) {

                if(data[i][j] <= 0) {
                    data[i][j] = 0;
                }

            }   

        }

    };

};

int main() {

    FilterReLU filter;
    vector<vector<double>> data = filter.pull_csv();
    filter.modify_csv(data);
    filter.push_csv(data);
    
}
