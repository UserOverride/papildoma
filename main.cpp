#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

string cleanWord(string word) {
    string cleaned;
    for (char c : word) {
        if (!ispunct(c) && c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5' && c != '6' && c != '7' && c != '8' && c != '9') {
            cleaned += c;
        }
    }

    return cleaned;
}

void parser(string text, map<string, int>& wordCount, map<string, set<int>>& wordLines) {
    istringstream stream(text);
    string line;
    int lineNumber = 0;
    while (getline(stream, line)) {
        lineNumber++;
        istringstream lineStream(line);
        string word;
        while (lineStream >> word) {
            word = cleanWord(word);
            if (!word.empty()) {
                wordCount[word]++;
                wordLines[word].insert(lineNumber);
            }
        }
    }
}

vector<string> findURLs(string text) {
    vector<string> urls;
    regex urlRegex(R"((https?://|www\.)\S+|\b[a-zA-Z0-9.-]+\.(com|net|org|lt|edu)\b)");
    auto words_begin = sregex_iterator(text.begin(), text.end(), urlRegex);

    for (sregex_iterator i = words_begin; i != sregex_iterator(); i++) {
        urls.push_back((*i).str());
    }

    return urls;
}

void writeWordsNumbers(map<string, int> wordCount, string filename) {
    ofstream file(filename);
    for (auto pair : wordCount) {
        if (pair.second > 1) {
            file << pair.first << ": " << pair.second << endl;
        }
    }
}

void writeWordsLocationTable(map<string, set<int>> wordLines, string filename) {
    ofstream file(filename);
    for (auto pair : wordLines) {
        if (pair.second.size() > 1) {
            file << pair.first << ": ";
            for (int line : pair.second) {
                file << line << " ";
            }
            file << "\n";
        }
    }
}

void writeUlrToFile(vector<string> urls, string filename) {
    ofstream file(filename);
    for (string url : urls) {
        file << url << endl;
    }
}

bool fileExistanceValidator (string fileName) {
    ifstream file(fileName);
    if (!file.good()) {
        throw runtime_error("Failas pavadinimui \"" + fileName + "\" neegzistuoja!");
    }
    return file.good();
}

int main() {
    if (fileExistanceValidator("input.txt"))
    {
        string text;
        ifstream inFile("input.txt");

        string line;
        while (getline(inFile, line)) {
            text += line + "\n";
        }
        inFile.close();

        map<string, int> wordsWithCount;
        map<string, set<int>> wordsRelefantLinesLocations;
        parser(text, wordsWithCount, wordsRelefantLinesLocations);

        writeWordsNumbers(wordsWithCount, "rez1.txt");
        writeWordsLocationTable(wordsRelefantLinesLocations, "rez2.txt");

        vector<string> urls = findURLs(text);
        writeUlrToFile(urls, "rez3.txt");
    }
    return 0;
}