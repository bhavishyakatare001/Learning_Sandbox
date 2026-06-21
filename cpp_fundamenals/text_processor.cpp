#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

// quick helper to strip punctuation and make everything lowercase
string cleanWord(string word) {
    string cleaned = "";
    for (char c : word) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }
    return cleaned;
}

int main() {
    // sample text to test the logic
    string text = "C++ is powerful. C++ is fast. Python is great for AI, but C++ builds the core. AI needs data, data needs processing.";

    unordered_map<string, int> freqMap;
    stringstream ss(text);
    string word;

    // extract and count words
    while (ss >> word) {
        string cleaned = cleanWord(word);
        if (!cleaned.empty()) {
            freqMap[cleaned]++;
        }
    }

    // move everything to a vector so we can actually sort it
    vector<pair<string, int>> sortedWords(freqMap.begin(), freqMap.end());

    // sort by frequency (highest first), then alphabetically if there's a tie
    sort(sortedWords.begin(), sortedWords.end(), [](auto& a, auto& b) {
        if (a.second != b.second) {
            return a.second > b.second; 
        }
        return a.first < b.first; 
    });

    cout << "Top Words:" << endl;
    cout << "----------" << endl;
    
    // just print the top 5
    int count = 0;
    for (auto& p : sortedWords) {
        if (count >= 5) break;
        cout << p.first << " : " << p.second << endl;
        count++;
    }

    return 0;
}
