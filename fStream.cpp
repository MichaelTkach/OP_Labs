#include "fStream.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <unordered_set>
#include <algorithm>
using namespace std;

void printFileContents(string& filename) {
    cout << endl << "----------" << filename << "----------" << endl;
    char ch;
    ifstream inFile(filename);
    while (inFile.get(ch)) { // Поки не досягнуто кінця файлу
        cout << ch; // Виводимо символи на екран
    }
    cout << endl;
}

void appendToFile(string& filename) {
    string str;
    char delimiter = '/';
    char answer;
    cout << endl << "Do you want to append information to the file? (If you do then enter y or else any other symbol): ";
    cin >> answer;
    if (answer == 'y') {
        ofstream outFile(filename, ios::app);
        cout << "Enter new strings. If you want to stop then enter '" << delimiter << "'): " << endl;
        cin.ignore();
        getline(cin, str, delimiter);
        outFile << str << '\n';
        cout << "New data was successfully appended to the file '" << filename << "'." << endl;
        outFile.close();
        ifstream inFile(filename);

        cout << "Do you want to check contents of a '" << filename << "' file? (If you do then enter y or else any other symbol): ";
        cin.ignore();
        cin >> answer;
        if (answer == 'y') {
            printFileContents(filename);
        }
    }
}

void writeWordsToFile(string& inputFile, string& outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    string line, word;
    while (getline(inFile, line)) {
        size_t pos = 0, len = line.length();
        while (pos < len) {
            // Пошук наступного слова
            size_t start = line.find_first_not_of(" .,\n", pos);
            size_t end = line.find_first_of(" .,\n", start);

            if (start == string::npos) break;

            if (end == string::npos || end >= len) {
                // Останнє слово в рядку
                outFile << line.substr(start) << " ";
                break;
            } else {
                outFile << line.substr(start, end - start) << " ";
            }

            pos = end + 1;
        }
        outFile << endl;
    }

    inFile.close();
    outFile.close();
    cout << "Words were written to the file.\n";
}

void removeDuplicateFile(string& fileName) {
    string outputFileName = "output.txt";

    ifstream inputFile(fileName);
    ofstream outputFile(outputFileName);
    unordered_set<string> uniqueWords;
    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            if (uniqueWords.count(word) == 0) {
                uniqueWords.insert(word);
                outputFile << word << " ";
            }
        }
        outputFile << endl;
        uniqueWords.clear();
    }

    inputFile.close();
    outputFile.close();

    remove(fileName.c_str());
    rename(outputFileName.c_str(), fileName.c_str());
    cout << "Duplicates were removed from the file." << endl;
}

void findMostCommonFile(string& inputFileName) {
    string outputFileName = "temp.txt";

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    string line;

    while (getline(inputFile, line)) {
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());

        int charCount[128] = {};
        const char* currentChar = line.c_str();

        while (*currentChar) {
            charCount[static_cast<int>(*currentChar)]++;
            currentChar++;
        }

        int maxCount = 0;
        char mostCommonChar = '\0';
        charCount[32]=0;//обнуление количества пробелов  

        for (int i = 0; i < 128; i++) {
            if (charCount[i] > maxCount) {
                maxCount = charCount[i];
                mostCommonChar = static_cast<char>(i);
            }
        }

        outputFile << line << " ('" << mostCommonChar << "' - " << maxCount << ")\n";
    }
    
    inputFile.close();
    outputFile.close();
    remove(inputFileName.c_str());
    rename(outputFileName.c_str(), inputFileName.c_str());
    cout << "Most common symbols in lines of file are found." << endl;
}

void createFile1() {
    string filename, answer1, answer2;
    string outputFileName = "output";
    do {
        cout << "Enter filename: ";
        cin >> filename;

        ifstream inputFile(filename);
        if (!inputFile.is_open()) { // Якщо файл не існує, то створюємо його
            cout << "File '" << filename << "' has been successfully created!" << endl;

            appendToFile(filename);
            writeWordsToFile(filename, outputFileName);
            printFileContents(outputFileName);
            removeDuplicateFile(outputFileName);
            printFileContents(outputFileName);
            findMostCommonFile(outputFileName);
            printFileContents(outputFileName);
        } else { // Якщо файл існує, то виводимо його вміст
            cout << "File '" << filename << "' already exists." << endl;

            printFileContents(filename);
            appendToFile(filename);
            writeWordsToFile(filename, outputFileName);
            printFileContents(outputFileName);
            removeDuplicateFile(outputFileName);
            printFileContents(outputFileName);
            findMostCommonFile(outputFileName);
            printFileContents(outputFileName);
        }
        cout << "Do you want to continue session? (If you do then enter y or else any other symbol): ";
        cin >> answer2;
        cout << endl;
    } while (answer2 != "n");
}
