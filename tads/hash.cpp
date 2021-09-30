#include "hash.h"
#include <iostream>
using namespace std;

template <class T>
HashNode<T>::HashNode(string key, T value) {
    this->key = key;
    this->value = value;
}

template <class T>
HashNode<T>::HashNode(string key, T value, HashNode<T> *next) {
    this->key = key;
    this->value = value;
    this->next = next;
}

template <class T>
bool Hash<T>::isPrime(int n) {
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

template <class T>
int Hash<T>::supPrime(int n) {
    if (n <= 1)
        return 2;

    int prime = n;
    bool found = false;
    while (!found) {
        prime++;
        if (isPrime(prime))
            found = true;
    }
    return prime;
}

template <class T>
Hash<T>::Hash(int max) {
    this->max = max;
    this->top = supPrime(max);
    this->hash = new HashNode<T> *[top];
    this->twos = 0;
    for (int i = 0; i < top; this->hash[i++] = NULL);
}

template <class T>
Hash<T>::~Hash() {
    for (int i = 0; i < top; empty(this->hash[i++]));
    delete[] this->hash;
}


template <class T>
int Hash<T>::hashPos(string key) {
    int hashVal = 0;
    int p = 7;
    for(int i = 0; i < key.length(); i++) {
        hashVal += (int)key[i] * p ^ i;
    }
    return hashVal % top;
}

template <class T>
void Hash<T>::empty(HashNode<T> *node) {
    if (node)
    {
        empty(node->next);
        delete node;
    }
}

template <class T>
void Hash<T>::insert(string key) {
    int hashPos = this->hashPos(key);
    HashNode<T>* node = hash[hashPos];
    while(node) {
        if(node->key == key) {
            node->value++;
            if(node->value == 2) {
                twos++;
            } else if(node->value == 3) {
                twos--;
            }
            return;
        }
        node = node->next;
    }

    HashNode<T> *newNode = new HashNode<T>(key, 1, hash[hashPos]);
    hash[hashPos] = newNode;
}

template <class T>
int Hash<T>::duplicated() {
   return twos;
}