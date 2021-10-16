#include "tads/heap.cpp"
#include "tads/heap.h"
#include <iostream>
#include "string.h"

using namespace std;

int main() {
    int K;
    cin >> K;
    Heap* heap = new Heap(K);
    for(int i = 0; i < K; i++) {
        int N;
        cin >> N;

        int* list = new int[N - 1];
        int key;
        cin >> key;
        for(int j = 1; j < N; j++) {
            int element;
            cin >> element;
            list[j] = element;
        }

        heap->add(key, list, N - 1);
    }

    while(!heap->isEmpty()) {
        cout << heap->poll() << endl;
    }
}