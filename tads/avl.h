using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
    Node();
    Node(int key);
    Node(int key, Node *left, Node *right);
};

class Avl {
    private:
        Node* root;
        void preOrder(Node* node);
        Node* insert(Node* node, int key);
    public:
        Avl();
        ~Avl();
        int max(int a, int b);
        int height(Node *N);
        Node* newNode(int key);
        Node* rightRotate(Node *y);
        Node* leftRotate(Node *x);
        int getBalance(Node *N);
        Node* insert(int key);
        void preOrder();
};