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
    node->height = 1; // new node is initially
    // added at leaf
    return node;
};

Node* Avl::rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    // Return new root
    return x;
}

Node* Avl::leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    // Return new root
    return y;
}

int Avl::getBalance(Node *N) {
    if(N == NULL)
        return 0;
    return height(N->left) - height(N->right);
};

Node* Avl::insert(int key) {
    return this->insert(root, key);
}

Node* Avl::insert(Node* node, int key) {
    if (node == NULL)
        this->root = newNode(key);
        return this->root;
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if(key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
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
};


Node::Node(int key) {
    this->key = key;
};

Node::Node(int key, Node *left, Node *right) {
    this->key = key;
    this->left = left;
    this->right = right;
};


void Avl::preOrder(Node* node)
{
    cout << "RECURSIVE PRINTING !!!!" << endl;

    if(node != NULL)
    {
        cout << this->root->key << " ";
        preOrder(this->root->left);
        preOrder(this->root->right);
    }
}


void Avl::preOrder()
{
    cout << "PRINTING !!!!" << endl;
    preOrder(this->root);
}
