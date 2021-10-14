#include "tads/heap.cpp"
#include "tads/heap.h"
#include <iostream>

using namespace std;

int main() {
    int K;
    cin >> K;
    Heap heap = NULL;
    for(int i = 0; i < K; i++) {
        int N;
        cin >> N;
        if(heap == NULL) {
            heap = new Heap(N);
        }

        int* list = new int[N - 1];
        int key;
        cin >> key;
        for(int j = 1; j < N; j++) {
            int element;
            cin >> element;
            list[j] = element;
        }

        heap.add(key, list, N);
    }

    while(!heap.isEmpty()) {
        cout << heap.poll() << endl;
    }
}