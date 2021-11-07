Avl::Avl() {
    this->root = NULL;
};

Avl::~Avl() {

};

int Avl::height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
};

int Avl::max(int a, int b) {
    return (a > b)? a : b;
}

Node* Avl::newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
};

Node* Avl::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    return x;
}

Node* Avl::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    return y;
}

int Avl::getBalance(Node *N) {
    if(N == NULL)
        return 0;
    return height(N->left) - height(N->right);
};


Node* Avl::insert(Node* node, int key) {
    if (node == NULL) {
        return newNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if(key > node->key) {
        node->right = insert(node->right, key);
    } else {
        node->count++;
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1  && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node::Node() {
    this->count = 1;
};

Node::Node(int key) {
    this->key = key;
    this->count = 1;
};

Node::Node(int key, Node *left, Node *right) {
    this->key = key;
    this->left = left;
    this->right = right;
    this->count = 1;
};


void Avl::inorder(Node* node)
{
    if(node != NULL){
        inorder(node->left);
        for(int i = 0; i < node->count; i++) {
            cout << node->key << endl;
        }
        inorder(node->right);
    }
}



