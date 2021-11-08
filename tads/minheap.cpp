#include "minheap.h"
#include <iostream>

using namespace std;

HeapNode::HeapNode(int cost, int from, int to) {
    this->cost = cost;
    this->from = from;
    this->to = to;
}

HeapNode::HeapNode() {

}

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
    swap(0, size - 1);
    delete items[size - 1];
    size--;
    heapifyDown();
    HeapNode* copy = new HeapNode();
    copy->cost = item->cost;
    copy->from = item->from;
    copy->to = item->to;
    return copy;
}

void Heap::add(int cost, int from, int to) {
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
        cout << this->items[i]->cost << " ";
    }
    cout << endl;
}