template<class T>
class Node{
public:
    T value;
    Node *left, *right;
    Node()
    {
        left = right = NULL;
    }
    Node(T val, Node *l = NULL, Node *r = NULL)
    {
        value = val;
        left = l;
        right = r;
    }
};
