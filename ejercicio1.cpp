#include <iostream>
#include "tads/avl.h"
#include "tads/avl.cpp"

//
//#include <iostream>
//#include <queue>
//#include <unordered_map>
//#include <fstream>
//#include <string>
//#include <cstring>
//#include "tads/avl.h"
//
//using namespace std;
//
//struct node {
//    struct node *left;
//    int data;
//    int height;
//    struct node *right;
//
//};
//
//class AVL
//{
//private:
//
//public:
//    struct node * root;
//    AVL(){
//        this->root = NULL;
//
//    }
//
//    int calheight(struct node *p){
//
//        if(p->left && p->right){
//            if (p->left->height < p->right->height)
//                return p->right->height + 1;
//            else return  p->left->height + 1;
//        }
//        else if(p->left && p->right == NULL){
//            return p->left->height + 1;
//        }
//        else if(p->left ==NULL && p->right){
//            return p->right->height + 1;
//        }
//        return 0;
//
//    }
//
//    int bf(struct node *n){
//        if(n->left && n->right){
//            return n->left->height - n->right->height;
//        }
//        else if(n->left && n->right == NULL){
//            return n->left->height;
//        }
//        else if(n->left== NULL && n->right ){
//            return -n->right->height;
//        }
//    }
//
//    struct node * llrotation(struct node *n){
//        struct node *p;
//        struct node *tp;
//        p = n;
//        tp = p->left;
//
//        p->left = tp->right;
//        tp->right = p;
//
//        return tp;
//    }
//
//
//    struct node * rrrotation(struct node *n){
//        struct node *p;
//        struct node *tp;
//        p = n;
//        tp = p->right;
//
//        p->right = tp->left;
//        tp->left = p;
//
//        return tp;
//    }
//
//
//    struct node * rlrotation(struct node *n){
//        struct node *p;
//        struct node *tp;
//        struct node *tp2;
//        p = n;
//        tp = p->right;
//        tp2 =p->right->left;
//
//        p -> right = tp2->left;
//        tp ->left = tp2->right;
//        tp2 ->left = p;
//        tp2->right = tp;
//
//        return tp2;
//    }
//
//    struct node * lrrotation(struct node *n){
//        struct node *p;
//        struct node *tp;
//        struct node *tp2;
//        p = n;
//        tp = p->left;
//        tp2 =p->left->right;
//
//        p -> left = tp2->right;
//        tp ->right = tp2->left;
//        tp2 ->right = p;
//        tp2->left = tp;
//
//        return tp2;
//    }
//
//    struct node* insert(struct node *r,int data){
//
//        if(r==NULL){
//            struct node *n;
//            n = new struct node;
//            n->data = data;
//            r = n;
//            r->left = r->right = NULL;
//            r->height = 1;
//            return r;
//        }
//        else{
//            if(data < r->data)
//                r->left = insert(r->left,data);
//            else
//                r->right = insert(r->right,data);
//        }
//
//        r->height = calheight(r);
//
//        if(bf(r)==2 && bf(r->left)==1){
//            r = llrotation(r);
//        }
//        else if(bf(r)==-2 && bf(r->right)==-1){
//            r = rrrotation(r);
//        }
//        else if(bf(r)==-2 && bf(r->right)==1){
//            r = rlrotation(r);
//        }
//        else if(bf(r)==2 && bf(r->left)==-1){
//            r = lrrotation(r);
//        }
//
//        return r;
//
//    }
//
//    void levelorder_newline(){
//        if (this->root == NULL){
//            cout<<"\n"<<"Empty tree"<<"\n";
//            return;
//        }
//        levelorder_newline(this->root);
//    }
//
//    void levelorder_newline(struct node *v){
//        queue <struct node *> q;
//        struct node *cur;
//        q.push(v);
//        q.push(NULL);
//
//        while(!q.empty()){
//            cur = q.front();
//            q.pop();
//            if(cur == NULL && q.size()!=0){
//                cout<<"\n";
//
//                q.push(NULL);
//                continue;
//            }
//            if(cur!=NULL){
//                cout<<" "<<cur->data;
//
//                if (cur->left!=NULL){
//                    q.push(cur->left);
//                }
//                if (cur->right!=NULL){
//                    q.push(cur->right);
//                }
//            }
//
//
//        }
//    }
//
//    struct node * deleteNode(struct node *p,int data){
//
//        if(p->left == NULL && p->right == NULL){
//            if(p==this->root)
//                this->root = NULL;
//            delete p;
//            return NULL;
//        }
//
//        struct node *t;
//        struct node *q;
//        if(p->data < data){
//            p->right = deleteNode(p->right,data);
//        }
//        else if(p->data > data){
//            p->left = deleteNode(p->left,data);
//        }
//        else{
//            if(p->left != NULL){
//                q = inpre(p->left);
//                p->data = q->data;
//                p->left=deleteNode(p->left,q->data);
//            }
//            else{
//                q = insuc(p->right);
//                p->data = q->data;
//                p->right = deleteNode(p->right,q->data);
//            }
//        }
//
//        if(bf(p)==2 && bf(p->left)==1){ p = llrotation(p); }
//        else if(bf(p)==2 && bf(p->left)==-1){ p = lrrotation(p); }
//        else if(bf(p)==2 && bf(p->left)==0){ p = llrotation(p); }
//        else if(bf(p)==-2 && bf(p->right)==-1){ p = rrrotation(p); }
//        else if(bf(p)==-2 && bf(p->right)==1){ p = rlrotation(p); }
//        else if(bf(p)==-2 && bf(p->right)==0){ p = llrotation(p); }
//
//
//        return p;
//    }
//
//    struct node* inpre(struct node* p){
//        while(p->right!=NULL)
//            p = p->right;
//        return p;
//    }
//
//    struct node* insuc(struct node* p){
//        while(p->left!=NULL)
//            p = p->left;
//
//        return p;
//    }
//
//    int insuc_data(struct node* p){
//        while(p->left!=NULL)
//            p = p->left;
//
//        return p->data;
//    }
//};

int main() {
    cout << "Bueeeeenas" << endl;

    // OJO CON ESTO!!! TODO: Adaptar al ejercicio
    Avl* avl = new Avl();

    cout << "Bueeeeenas" << endl;

    /* Constructing tree given in
    the above figure */
    avl->insert(10);
    avl->insert(20);
    avl->insert(30);
    avl->insert(40);
    avl->insert(50);
    avl->insert(25);

    /* The constructed AVL Tree would be
                30
            / \
            20 40
            / \ \
        10 25 50
    */
    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    avl->preOrder();

    return 0;
//    int N;
//    cout << "Start" << endl;
//    cin >> N;
//    AVL avl;
//    cout << "Inserting" << endl;
//    for(int i = 0; i < N; i++) {
//        int n_add;
//        cin >> n_add;
//        avl.root = avl.insert(avl.root, n_add);
//    }
//
//    if(avl.root == NULL) {
//        cout << "AAAAAA " << endl;
//    }
//
//    cout << "Printing" << endl;
//    avl.levelorder_newline();
//
//    cout << "Displaying ordered" << endl;
//    for(int i = 0; i < N; i++) {
//        int min = avl.insuc_data(avl.root);
//        cout << min << endl;
//        avl.root = avl.deleteNode(avl.root, min);
//    }
//
//
    return 0;
}
