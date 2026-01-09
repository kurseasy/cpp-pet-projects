#include <iostream>
#include <map>
#include <sstream>
using namespace std;

int main() {
    string text = "hello world hello cpp";
    map<string, int> freq;
    string word;
    stringstream ss(text);

    while (ss >> word) {
        freq[word]++;
    }

    for (auto &p : freq) {
        cout << p.first << ": " << p.second << endl;
    }
    return 0;
}
