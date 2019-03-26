#include<iostream>
using namespace std;


struct Node
{
    int value;
    Node *root;
    Node *left;
    Node *right;
    // Constructor
    Node(int num);
    Node();
};

namespace ariel {
    class Tree {
    private:
        void  makeemptytree(Node *leaf);
        bool  Find(Node *r, int x);
        void insertHelper(Node *myroot,int value);
        int sizehelp (Node *myroot);
        int  right (Node *r,int i);
        int left (Node *r,int i);
        Node* parent(Node *myroot, int i);
        void display(Node* t);



    public:

        Node *myroot;

        Tree();
        void insert(int i);
        bool  remove(int i);
        int size();
        int root();
        int parent(int i);
        int left(int i);
        int right(int i);
        void print()const;
        bool contains(int i);
        ~Tree() ;

    };
}





