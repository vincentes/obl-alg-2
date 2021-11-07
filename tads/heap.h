#ifndef HEAP_H
#define HEAP_H
class HeapNode
{
public:
    int key;
    int* list;
    int pos;
    int length;
    HeapNode(int key, int* list, int length);
    HeapNode();
    ~HeapNode();
    void removeKey();
    void updateKey();
};

/**
 * Min Heap
 */
class Heap
{
private:
    HeapNode** items;
    int capacity;
    int size;
    int getLeftChildIndex(int parentIndex);
    int getRightChildIndex(int parentIndex);
    int getParentIndex(int childIndex);

    bool hasLeftChild(int index);
    bool hasRightChild(int index);
    bool hasParent(int index);

    int leftChild(int index);
    int rightChild(int index);
    int parent(int index);
    void swap(int indexOne, int indexTwo);
    void heapifyDown();
    void heapifyUp();

public:
    int peek();
    int poll();
    void add(int key, int* list, int length);
    bool isEmpty();
    void print();

    Heap(int capacity);
    ~Heap();
};

#endif