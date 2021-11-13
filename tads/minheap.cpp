#include "minheap.h"
#include <iostream>

using namespace std;

HeapNode::HeapNode(int cost, int from, int to) {
    this->cost = cost;
    this->from = from;
    this->to = to;
}

HeapNode::HeapNode() {}

HeapNode::~HeapNode() {}

Heap::Heap(int capacity) {
    this->items = new HeapNode*[capacity];
    this->capacity = capacity;
    this->size = 0;
}

Heap::~Heap() {
    delete[] this->items;
}

int Heap::getLeftChildIndex(int parentIndex) {
    return 2 * parentIndex + 1;
}

int Heap::getRightChildIndex(int parentIndex) {
    return 2 * parentIndex + 2;
}

int Heap::getParentIndex(int childIndex) {
    return (childIndex - 1) / 2;
}

bool Heap::hasLeftChild(int index) {
    return getLeftChildIndex(index) < size;
}

bool Heap::hasRightChild(int index) {
    return getRightChildIndex(index) < size;
}

bool Heap::hasParent(int index) {
    return getParentIndex(index) >= 0;
}

int Heap::leftChild(int index) {
    return items[getLeftChildIndex(index)]->cost;
}

int Heap::rightChild(int index) {
    return items[getRightChildIndex(index)]->cost;
}

int Heap::parent(int index) {
    return items[getParentIndex(index)]->cost;
}

void Heap::swap(int indexOne, int indexTwo) {
    HeapNode* temp = items[indexOne];
    items[indexOne] = items[indexTwo];
    items[indexTwo] = temp;
}

int Heap::peek() {
    return items[0]->cost;
}

bool Heap::isEmpty() {
    return this->size == 0;
}

HeapNode* Heap::poll() {
    HeapNode* item = items[0];
    HeapNode* copy = new HeapNode(item->cost, item->from, item->to);

    swap(0, size - 1);
    delete items[size - 1];
    items[size - 1] = NULL;
    size--;
    heapifyDown();\
    
    return copy;
}

void Heap::ensureExtraCapacity() {
    if(size == capacity) {
        HeapNode** newItems = new HeapNode*[capacity * 2];
        for (int i = 0; i < size; i++)
        {
            newItems[i] = this->items[i];
        }
        this->items = newItems;
        capacity = capacity * 2;
        // delete[] newItems;
    }
}

void Heap::add(int cost, int from, int to) {
    ensureExtraCapacity();
    HeapNode* item = new HeapNode(cost, from, to);
    items[size] = item;
    size++;
    heapifyUp();
}

void Heap::heapifyUp() {
    int index = size - 1;
    while(hasParent(index) && parent(index) > items[index]->cost) {
        swap(getParentIndex(index), index);
        index = getParentIndex(index);
    }
}

void Heap::heapifyDown() {
    int index = 0;
    while(hasLeftChild(index)) {
        int smallerChildIndex = getLeftChildIndex(index);
        if(hasRightChild(index) && rightChild(index) < leftChild(index)) {
            smallerChildIndex = getRightChildIndex(index);
        }

        if(items[index]->cost < items[smallerChildIndex]->cost) {
            break;
        } else {
            swap(index, smallerChildIndex);
        }
        index = smallerChildIndex;
    }
}

void Heap::print() {
    for(int i = 0; i < this->size; i++) {
        cout << "[ " << this->items[i]->to << " " << items[i]->cost << "] ";
    }
    cout << endl;
}