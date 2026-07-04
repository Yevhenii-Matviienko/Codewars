#include <string>
#include <vector>

using namespace std;

string range_extraction(vector<int> args) {
    vector<string> result_vector;
    int index = 0;
    while (index < args.size()) {
        int start = args[index];
        while (index + 1 < args.size() && args[index + 1] == args[index] + 1) {
            index++;
        }
        int end = args[index];
        if (end - start >= 2) {
            result_vector.push_back(to_string(start) + "-" + to_string(end));
        } 
        else if (end - start == 1) {
            result_vector.push_back(to_string(start));
            result_vector.push_back(to_string(end));
        } 
        else {
            result_vector.push_back(to_string(start));
        }
        index++;
    }
    string result_string;
    for (int index = 0; index < result_vector.size(); index++) {
        if (index > 0) {
            result_string += ",";
        }
        result_string += result_vector[index];
    }
    return result_string;
}