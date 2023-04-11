#pragma once
#include <iostream>
#include <cstring>
using namespace std;

void printFileContents(const char* filename);

void appendToFile(const char* filename);

void writeWordsToFile(const char* inputFile, const char* outputFile);

void removeDuplicateFile(const char* inputFilename);

void findMostCommonFile(const char* inputFileName);

void createFile();
