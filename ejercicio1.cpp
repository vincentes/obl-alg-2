#include <iostream>
#include "tads/avl.h"
#include "tads/avl.cpp"

void deleteNodes(Node* node);

int main() {

    Avl* avl = new Avl();
    Node *root = NULL;

    int N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        int n_add;
        cin >> n_add;
        root = avl->insert(root, n_add);
    }

    avl->inorder(root);

    deleteNodes(root);

    root = NULL;

    return 0;
}

void deleteNodes(Node* node) {
    if(node) {
        deleteNodes(node->right);
        deleteNodes(node->left);
        delete node;
    }
}
