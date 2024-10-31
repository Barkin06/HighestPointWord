#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;

string highestScoringWord(const string& str) {
    int res1 = 0;
    string word;
    vector<pair<string, int>> res2;

    
    for (char c : str) {
        if (isalpha(c)) {
            int ascii = toupper(c) - 64;
            res1 += ascii;
            word += c;
        }
        else if (c == ' ') {
            res2.push_back(make_pair(word, res1));
            word = "";    
            res1 = 0;     
        }
    }

    
    if (!word.empty()) {
        res2.push_back(make_pair(word, res1));
    }

    
    int maxScore = 0;
    string highestWord;
    for (pair<string, int> pair : res2) {
        if (pair.second > maxScore) {
            maxScore = pair.second;
            highestWord = pair.first;
        }
    }

    return highestWord;
}

int main() {
    string text = "hello world programming is fun";
    string result = highestScoringWord(text);
    cout << "The highest scoring word is: " << result << endl;
    return 0;
}
