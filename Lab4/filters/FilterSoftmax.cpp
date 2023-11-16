#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include "filter.hpp"

using namespace std;

class FilterSoftmax : public Filter {

    public:

        void modify_csv(vector<vector<double>>& data) override {
        
        for(int i = 0; i < data.size(); i++) {

            double row_sum = 0;

            for(int j = 0; j < data[i].size(); j++) {

                row_sum += data[i][j];

            }

            for(int j = 0; j < data[i].size(); j++) {

                data[i][j] = data[i][j] / row_sum;

            }   

        }

    };

};

int main() {

    FilterSoftmax filter;
    vector<vector<double>> data = filter.pull_csv();
    filter.modify_csv(data);
    filter.push_csv(data);
    
}
