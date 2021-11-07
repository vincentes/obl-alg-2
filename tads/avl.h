using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
    int count;
    Node();
    Node(int key);
    Node(int key, Node *left, Node *right);
};

class Avl {
    private:
        Node* root;
    public:
        Avl();
        ~Avl();
        int max(int a, int b);
        int height(Node *N);
        Node* newNode(int key);
        Node* rightRotate(Node *y);
        Node* leftRotate(Node *x);
        int getBalance(Node *N);
        Node* insert(Node* node, int key);
        void inorder(Node* node);
};