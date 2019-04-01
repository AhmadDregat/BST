#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *root;
    Node *left;
    Node *right;
};


namespace ariel {
    class Tree {
    private:
void DestroyTree(Node *curr); // Destroy all subtrees of current node
        Node*  Find(Node *r, int x);
        void insertHelper(Node *myroot,int value);
        void display(Node *root, int space)const;
    Node* remove(Node* myroot, int data) ;
        int helpsize=0;
        Node* findMin(Node* t);

        
        
    public:
        
        Node *myroot;
        
        Tree();
        void insert(int i);
        void  remove(int i);
        int size();
        int root();
        int parent(int i);
        int left(int num);
        int right(int num);
        void print()const;
        bool contains(int i);
        ~Tree() ;
        
    };
}
