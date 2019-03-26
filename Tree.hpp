#include<iostream>
using namespace std;
using namespace ariel ;
using namespace Tree ;

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
        bool  Find(node *r, int x);
        void insertHelper(Node *root,int value);
        int sizehelp (Node *root);
        int  right (Node *r,int i);
        int left (Node *r,int i);
        Node* parent(Node *root, int i);
        void display(Node* t);



    public:

        Node *root;

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


