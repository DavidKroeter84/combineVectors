#include "combine_vectors.h"
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;
using namespace combineVectors;

void print_vec(const vector<int> &nums) {
    const size_t sz = nums.size();
    if (sz==0) return;

    cout << "[";
    for (size_t i=0; i<sz-1; i++) { 
        cout << nums[i] << ", ";
    }  
    cout << nums[sz-1] << "]" << endl;
}

vector<int> get_vector() {
    vector<int> res;

    cout << "Enter ascending vector elements (break entering something that is not a number):" << endl;
    do {
        std::string input;
        int val;
        cout << "vec[" << res.size() << "]: ";
        cin >> input; // Get user input from the keyboard
        if (input.size() > 1) {
            cerr << "Please enter one digit at a time, breaking now" << endl;
            break;
        }
        
        if (isdigit(input[0])) val = input[0] - '0';
        else break;

        if (res.size() > 0 && val < res.back()) {
            cerr << "Please enter ascending elements, breaking now" << endl;
            break;
        }
        
        res.push_back(val);
 
    } while(true);

    cout << "I got the following vector: ";
    print_vec(res);

    return res;
}

int main() {

    cout << endl << "Collecting values for vec_1:" << endl;
    vector<int> vec_1 = get_vector();

    cout << endl << "Collecting values for vec_2:" << endl;
    vector<int> vec_2 = get_vector();

    cout << endl << "Calculating result:" << endl;
    vector<int> res = combine_vectors(vec_1, vec_2);
    cout << "The resulting vector is: ";
    print_vec(res);

    cout << endl << "Bye bye!" << endl;
    
    return 0;
}


