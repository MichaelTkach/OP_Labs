#include "fPointer.h"
#include "fStream.h"
using namespace std;

int main(int argc, char* argv[]) {

    if (!strcmp(argv[2], "FileStream")){
        cout << "FileStream mode activated.\n";
        createFile1();
        cin.ignore();

    } else if (!strcmp(argv[2], "FilePointer")) {
        cout << "FilePointer mode activated.\n";
        createFile();
        cin.ignore();

    } else {
        cout << "Unknown mode." << endl << "Available modes: FilePointer, FileStream.";
    }

   return 0;
}

