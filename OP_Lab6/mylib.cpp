#include "mylib.h"
#include <iostream>
#include <string>

using namespace std;

template<typename T>
bool HashSet<T>::Iterator::isEnd() {
    return currentNode == nullptr;
}

template<typename T>
T HashSet<T>::Iterator::getValue() {
    return currentNode->data;
}

template<typename T>
void HashSet<T>::Iterator::moveToNext() {
    currentNode = currentNode->next;
}

template<typename T>
HashSet<T>::HashSet() {
    for (int i = 0; i < tableSize; ++i) {
        table[i] = nullptr;
    }
}

template<typename T>
HashSet<T>::~HashSet() {
    clear();
}

template<typename T>
void HashSet<T>::clear() {
    for (int i = 0; i < tableSize; ++i) {
        Node* node = table[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            delete temp;
        }
        table[i] = nullptr;
    }
}

template<typename T>
bool HashSet<T>::contains(const T& value) {
    int index = hashFunction(value);
    Node* node = table[index];
    while (node) {
        if (node->data == value) {
            return true;
        }
        node = node->next;
    }
    return false;
}

template<typename T>
void HashSet<T>::insert(const T& value) {
    if (contains(value)) {
        return;
    }
    int index = hashFunction(value);
    Node* newNode = new Node(value);
    newNode->next = table[index];
    table[index] = newNode;
}

template<typename T>
HashSet<T> HashSet<T>::difference(HashSet<T>& otherSet) {
    HashSet<T> result;
    for (int i = 0; i < tableSize; ++i) {
        Node* node = table[i];
        while (node) {
            if (!otherSet.contains(node->data)) {
                result.insert(node->data);
            }
            node = node->next;
        }
    }
    return result;
}

template<typename T>
typename HashSet<T>::Iterator HashSet<T>::setToBegin() {
    Node* head = nullptr;
    Node* prevNode = nullptr;

    for (int i = 0; i < tableSize; ++i) {
        Node* node = table[i];
        while (node) {
            Node* newNode = new Node(node->data);
            if (prevNode) {
                prevNode->next = newNode;
            }
            else {
                head = newNode;
            }
            prevNode = newNode;
            node = node->next;
        }
    }

    return Iterator(head);
}

template<typename T>
int HashSet<T>::hashFunction(const T& value) {
    size_t hashCode = hash<T>{}(value);
        
    hashCode = (hashCode * 31) + 17;
        
    return hashCode % tableSize;
}


template<typename T>
void printSet(HashSet<T>& set) {
    cout << "Set: ";
    typename HashSet<T>::Iterator it = set.setToBegin();
    while (!it.isEnd()) {
        cout << it.getValue() << " ";
        it.moveToNext();
    }
    cout << endl;
}

template<typename T>
void processHashSet() {
    HashSet<T> set;

    int size;
    cout << "Enter the number of elements in the set: ";
    cin >> size;

    for (int i = 0; i < size; ++i) {
        T element;
        cout << "Enter element " << (i + 1) << ": ";
        cin >> element;
        set.insert(element);
    }

    printSet(set);

    cout << endl;

    typename HashSet<T>::Iterator iter = set.setToBegin();
    int operation;
    do {
        cout << endl;
        cout << "Choose an operation:" << endl;
        cout << "1. Check element in the set" << endl;
        cout << "2. Add an element" << endl;
        cout << "3. Clear the set" << endl;
        cout << "4. Find the difference with another set" << endl;
        cout << "5. Set iterator to the beginning" << endl;
        cout << "6. Check if the iterator is at the end" << endl;
        cout << "7. Get the value of the current element" << endl;
        cout << "8. Move to the next element" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter the number for the selected operation: ";
        cin >> operation;

        switch (operation) {
            case 1: {
                T element;
                cout << "Enter the element to check: ";
                cin >> element;
                
                if (set.contains(element)) {
                    cout << "Element is present in the set." << endl;
                } else {
                    cout << "Element is not present in the set." << endl;
                }

                printSet(set);
                break;
            }
            case 2: {
                T element;
                cout << "Enter the element to add: ";
                cin >> element;
                set.insert(element);
                typename HashSet<T>::Iterator it = set.setToBegin();
                iter = it;
                cout << "Element added." << endl;

                printSet(set);
                break;
            }
            case 3: {
                set.clear();
                typename HashSet<T>::Iterator it = set.setToBegin();
                iter = it;
                cout << "Set cleared." << endl;
                
                printSet(set);
                break;
            }
            case 4: {
                HashSet<T> otherSet;
                int otherSetSize;
                cout << "Enter the number of elements in the other set: ";
                cin >> otherSetSize;

                for (int i = 0; i < otherSetSize; ++i) {
                    T element;
                    cout << "Enter element " << (i + 1) << " of the other set: ";
                    cin >> element;
                    otherSet.insert(element);
                }

                HashSet<T> differenceSet = set.difference(otherSet);

                cout << "Difference set: ";
                typename HashSet<T>::Iterator it = differenceSet.setToBegin();
                while (!it.isEnd()) {
                    cout << it.getValue() << " ";
                    it.moveToNext();
                }
                cout << endl;
                            
                printSet(set);
                break;
            }
            case 5: {
                iter = set.setToBegin();
                cout << "Iterator set to the beginning." << endl;
                break;
            }
            case 6: {
                if (iter.isEnd()) {
                    cout << "Iterator is at the end." << endl;
                } else {
                    cout << "Iterator is not at the end." << endl;
                }
                break;
            }
            case 7: {
                if (iter.isEnd()) {
                    cout << "Iterator is at the end." << endl;
                } else {
                    cout << "Current element value: " << iter.getValue() << endl;
                    printSet(set);
                }
                break;
            }
            case 8: {
                if (iter.isEnd()) {
                    cout << "Iterator is at the end. It will be moved to the begining." << endl;
                    iter = set.setToBegin();
                } else {
                    iter.moveToNext();
                    cout << "Moved to the next element." << endl;
                }
                break;
            }
            case 0: {
                cout << "Exiting the program." << endl;
                break;
            }
            default:
                cout << "Invalid operation choice." << endl;
                break;
        }
    } while (operation != 0);
}

template class HashSet<int>;
template class HashSet<double>;
template class HashSet<string>;

template void processHashSet<int>();
template void processHashSet<double>();
template void processHashSet<string>();


