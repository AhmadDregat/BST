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
        void makeemptytree(Node *leaf);
        Node*  Find(Node *r, int x);
        void insertHelper(Node *myroot,int value);
        void display(Node *root, int space);
        Node* remove(Node* r, int data) ;
        int helpsize=0;
        
        
        
    public:
        
        Node *myroot;
        
        Tree();
        void insert(int i);
        void  remove(int i);
        int size();
        int root();
        int parent(int i);
        int left(int i);
        int right(int i);
        void print();
        bool contains(int i);
        ~Tree() ;
        
    };
}