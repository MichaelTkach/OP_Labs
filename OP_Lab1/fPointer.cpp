#include "fPointer.h"
#include <iostream>
#include <cstring>
using namespace std;

void printFileContents(const char* filename) {
    FILE* filePtr = fopen(filename, "r");
    cout << endl << "----------" << filename << "----------" << endl;
    char ch;
    while ((ch = fgetc(filePtr)) != EOF) {
        printf("%c",ch);
    }
    fclose(filePtr);
    cout << endl;
}

void appendToFile(const char* filename) {
    char delimiter = '/';
    char answer, str[1000];
    printf("\nDo you want to append information to the file? (If yes - press y or any other letter if not): ");
    cin.ignore();
    scanf("%c", &answer);
    if (answer == 'y') {
        FILE* filePtr = fopen(filename, "a"); 
        printf("Enter new strings. If you want to stop then enter '%c'): \n", delimiter);
        cin.ignore();
        int i = 0;
        int ch;
        while (i < 1000 - 1 && (ch = getchar()) != EOF && ch != delimiter) {
            str[i++] = (char) ch;
        }
        str[i] = '\0'; 
        fprintf(filePtr, "%s\n", str);
        printf("New data was successfully appended to the file '%s'.\n", filename);
        fclose(filePtr);
        FILE* filePtr1 = fopen(filename, "r");
        
        printf("Do you want to check contents of a '%s' file? (If you do then enter y or else any other symbol): ", filename);
        cin.ignore();
        scanf("%c", &answer);
        if (answer == 'y') {
            printFileContents(filename);
        }
    }
}

void writeWordsToFile(const char* inputFile, const char* outputFile) {
    FILE* in = fopen(inputFile, "r");
    FILE* out = fopen(outputFile, "w");
    
    char line[100];
    while (fgets(line, 100, in)) {
        char* word = strtok(line, " .,\n");
        while (word) {
            fprintf(out, "%s ", word);
            word = strtok(NULL, " .,\n");
        }
        fprintf(out, "\n");
    }

    fclose(in);
    fclose(out);
    cout << "Words were written to the file.\n";
}

void removeDuplicateFile(const char* inputFilename) {
    char outputFilename[] = "temp.txt";
    FILE* inputFile = fopen(inputFilename, "r");
    FILE* outputFile = fopen(outputFilename, "w");

    char line[1000];
    while (fgets(line, 1000, inputFile)) {

        char* words[100];
        int count = 0;
        char* p = strtok(line, " ");
        while (p != NULL) {
            words[count++] = p;
            p = strtok(NULL, " ");
        }

        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                if (strcmp(words[i], words[j]) == 0) {

                    for (int k = j; k < count - 1; k++) {
                        words[k] = words[k + 1];
                    }
                    count--;
                    j--;
                }
            }
        }

        for (int i = 0; i < count; i++) {
            fprintf(outputFile, "%s", words[i]);
            if (i != count - 1) {
                fprintf(outputFile, " ");
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    remove(inputFilename);
    rename(outputFilename, inputFilename);
    cout << "Duplicates were removed from the file." << endl;
}

void findMostCommonFile(const char* inputFileName) {
    char outputFileName[] = "temp.txt";
    FILE* inputFile = fopen(inputFileName, "r");
    FILE* outputFile = fopen(outputFileName, "w");
    
    char line[1024];

    while (fgets(line, 1024, inputFile)) {
        char* newlinePos = strchr(line, '\n');
        if (newlinePos) {
            *newlinePos = '\0';
        }

        int charCount[128] = {};
        const char* currentChar = line;
        while (*currentChar) {
            charCount[static_cast<int>(*currentChar)]++;
            currentChar++;
        }
        int maxCount = 0;
        char mostCommonChar = '\0';
        charCount[32]=0; 
        for (int i = 0; i < 128; i++) {
            if (charCount[i] > maxCount) {
                maxCount = charCount[i];
                mostCommonChar = static_cast<char>(i);
            }
        }

        fprintf(outputFile, "%s ('%c' - %d)\n", line, mostCommonChar, maxCount);
    }

    fclose(inputFile);
    fclose(outputFile);
    remove(inputFileName);
    rename( outputFileName, inputFileName);
    cout << "Most common symbols in lines of file are found." << endl;
}

void createFile() {
    char filename[50], answer1, answer2;
    char outputFileName[]="output";
    do {
        cout << "Enter filename: ";
        cin >> filename;
        
        FILE* filePtr = fopen(filename, "r");
        
        if (filePtr == NULL) {
            filePtr = fopen(filename, "w");
            cout << "File '" << filename << "' has been successfully created!" << endl;

            fclose(filePtr);
            appendToFile(filename);
            char outputFileName[]="output";
            writeWordsToFile(filename, outputFileName);
            printFileContents(outputFileName);
            removeDuplicateFile(outputFileName);
            printFileContents(outputFileName);
            findMostCommonFile(outputFileName);
            printFileContents(outputFileName);
        } else {
            cout << "File " << filename << " already exists. " << endl;

            printFileContents(filename);
            fclose(filePtr);
            appendToFile(filename);
            writeWordsToFile(filename, outputFileName);
            printFileContents(outputFileName);
            removeDuplicateFile(outputFileName);
            printFileContents(outputFileName);
            findMostCommonFile(outputFileName);
            printFileContents(outputFileName);
        }

        cout << "Do you want to continue session? (y/n): ";
        cin >> answer2;
        cout << endl;
    } while (answer2 != 'n'); 
}
