using namespace std;

class HeapNode
{
public:
    int key;
    int* list;
    int pos;
    int length;
    HeapNode(int key, int* list, int length);
    ~HeapNode();
    void removeKey();
    void updateKey();
};

class Heap
{
private:
    HeapNode* items;
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
    void ensureExtraCapacity();

public:
    int peek();
    int poll();
    void add(int key, int* list, int length);
    bool isEmpty();

    Heap(int capacity);
    ~Heap();
};