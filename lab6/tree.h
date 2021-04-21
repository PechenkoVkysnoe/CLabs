class Tree
{
public:
    struct Node
    {
        char key;
        Node* left, * right, * next, * prev;
        Tree* tree;
        Node(char key)
        {
            this->key = key;
            this->left = this->right = nullptr;
        }
    };
    Tree();
    ~Tree();
    void clear();
    int size();
    bool empty();
    void RecursiveDeleteNode(Node* node);
    void insert(char key);
    void erase(char key);
    Node* find(char key);
    Node* next(char key);
    Node* prev(char key);
    int MaxDepth();
private:
    int my_size;
    Node* my_root;
    Node* find(Node* node, char key);
    void insert(Node* node, char key);
    void erase(Node* node, char key);
    void erase(Node* node, char key, Node* parent);
    int MaxDepth(Node* node);
};
