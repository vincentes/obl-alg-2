#include <string>
#include <cstring>

using namespace std;

template <class T>
class HashNode
{
public:
    string key;
    T value;
    HashNode<T> *next;
    HashNode(string key, T value);
    HashNode(string key, T value, HashNode<T> *next);
};


template <class T>
class Hash {
private:
    int max;
    int top;
    HashNode<T> **hash;;
    int amount;
    int twos;
    int hashPos(string key);
    bool isPrime(int num);
    int supPrime(int num);
    void empty(HashNode<T> *node);
public:
    Hash(int max);
    ~Hash();
    void insert(string key);
    void remove(string key);
    bool exists(string key);
    bool isEmpty(string key);
    int length();
    int duplicated();
};

