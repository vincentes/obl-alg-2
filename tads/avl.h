using namespace std;

template <class T>
class node
{
public:
    T value;
    node<T> *left;
    node<T> *right;
    node(T value);
    node(T value, node<T> *left, node<T> *right );
};

template <class T>
class Avl {
private:
public:
    Avl(node root);
    ~Avl();
};