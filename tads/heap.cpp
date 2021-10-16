#include "heap.h"
#include "iostream"

HeapNode::HeapNode(int key, int* list, int length) {
    this->key = key;
    this->list = list;
    this->pos = 0;
    this->length = length;
}

HeapNode::HeapNode() {

}

HeapNode::~HeapNode() {
    delete[] this->list;
}

void HeapNode::removeKey() {

    key = list[pos];
    pos++;
}

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
    return items[getLeftChildIndex(index)]->key;
}

int Heap::rightChild(int index) {
    return items[getRightChildIndex(index)]->key;
}

int Heap::parent(int index) {
    return items[getParentIndex(index)]->key;
}

void Heap::swap(int indexOne, int indexTwo) {
    HeapNode* temp = items[indexOne];
    items[indexOne] = items[indexTwo];
    items[indexTwo] = temp;
}

int Heap::peek() {
    return items[0]->key;
}

bool Heap::isEmpty() {
    return this->size == 0;
}

int Heap::poll() {
    int item = items[0]->key;

    // Is items[0] empty
    if(items[0]->length == items[0]->pos) {
        swap(0, size - 1);
        delete items[size - 1];
        size--;
    } else {
        items[0]->removeKey();
    }

    heapifyDown();

    return item;
}

void Heap::add(int key, int* list, int n) {
    HeapNode* item = new HeapNode(key, list, n);
    items[size] = item;
    size++;
    heapifyUp();
}

void Heap::heapifyUp() {
    int index = size - 1;
    while(hasParent(index) && parent(index) > items[index]->key) {
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

        if(items[index]->key < items[smallerChildIndex]->key) {
            break;
        } else {
            swap(index, smallerChildIndex);
        }
        index = smallerChildIndex;
    }
}