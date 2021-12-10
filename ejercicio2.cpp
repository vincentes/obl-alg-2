#include <iostream>
#include "tads/hash.cpp"

using namespace std;

int main() {
    int N;
    cin >> N;
    Hash<int> *hash = new Hash<int> (N);
    for(int i = 0; i < N; i++) {
        string word;
        cin >> word;
        hash->insert(word);
    }

    cout << hash->duplicated();
    delete hash;
}