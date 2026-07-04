#include <string>
#include <unordered_set>

using namespace std;

string stripComments(const string &str, const unordered_set<char> &markers) {
    string result;
    string line;
    for (int index = 0; index <= str.size(); index++) {
        if (index == str.size() || str[index] == '\n') {
            while (!line.empty() && line.back() == ' ') {
                line.pop_back();
            }
            result += line;
            if (index != str.size()) {
                result += '\n';
            }
            line.clear();
        } 
        else {
            if (markers.count(str[index])) {
                while (index < str.size() && str[index] != '\n') {
                    index++;
                }
                index--;
            } 
            else {
                line += str[index];
            }
        }
    }
    return result;
}