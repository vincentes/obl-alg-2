#include <iostream>
#include "tads/hash.cpp"

using namespace std;

int main() {
    // MEJORAR EL HASH PARA EVITAR COLISIONES
    // HAY PALABRAS QUE SE ESTAN CONTANDO DEMAS
    int N;
    cin >> N;
    Hash<int> hash = Hash<int> (N);
    for(int i = 0; i < N; i++) {
        string word;
        cin >> word;
        cout << "FOUND " << word << " " << i + 1 << "/" << N << endl;
        hash.insert(word);
    }

    cout << hash.duplicated();
}