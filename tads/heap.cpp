#include "heap.h"
using namespace std;

HeapNode::HeapNode(int key, int* list, int length) {
    this->key = key;
    this->list = list;
    this->pos = 0;
    this->length = length;
}

HeapNode::~HeapNode() {
    delete[] this->list;
}

void HeapNode::removeKey() {
    key = list[pos];
    pos++;
}

Heap::Heap(int capacity) {
    this->items = new HeapNode[capacity];
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
    return items[getLeftChildIndex(index)].key;
}

int Heap::rightChild(int index) {
    return items[getRightChildIndex(index)].key;
}

int Heap::parent(int index) {
    return items[getParentIndex(index)].key;
}

void Heap::swap(int indexOne, int indexTwo) {
    HeapNode* temp = items[indexOne];
    items[indexOne] = items[indexTwo];
    items[indexTwo] = temp;
}

int Heap::peek() {
    return items[0].key;
}

bool Heap::isEmpty() {
    return this->size == 0;
}

int Heap::poll() {
    int item = items[0].key;
    items[0].removeKey();
    if(items[0].length == items[0].pos) {
        delete items[0];
    } else {
        add(items[0].key, items[0].list, items[0].length);
    }
    items[0] = items[size - 1];
    size--;
    heapifyDown();

    return item;
}

void Heap::add(int key, int* list, int n) {
    HeapNode* item = new HeapNode(key, list, n);
    ensureExtraCapacity(item.length);
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

void Heap::ensureExtraCapacity(int n) {
    if(size == capacity) {
        HeapNode* newArray = new HeapNode[capacity + n];
        for(int i = 0; i < capacity; i++) {
            newArray[i] = items[i];
        }
        capacity += n;
        delete[] items;
        items = newArray;
    }
}