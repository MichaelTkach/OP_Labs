#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class HashSet {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    static const int tableSize = 100;
    Node* table[tableSize];

public:
    class Iterator {
    private:
        Node* currentNode;

    public:
        Iterator(Node* node) : currentNode(node) {}

        bool isEnd();

        T getValue();

        void moveToNext();
    };

    HashSet();

    ~HashSet();

    void clear();

    bool contains(const T& value);

    void insert(const T& value);

    HashSet<T> difference(HashSet<T>& otherSet);

    Iterator setToBegin();

private:
    int hashFunction(const T& value);
};

template<typename T>
void printSet(HashSet<T>& set);

template <typename T>
void processHashSet();

