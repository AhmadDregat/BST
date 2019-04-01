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
        int helpsize=0;
    Node *FindNextNode(Node *curr) ;// Find the next number after num using current node


        
        
    public:
        
        Node *myroot;
        
        Tree();
        void insert(int i);
        bool remove(int num);
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
