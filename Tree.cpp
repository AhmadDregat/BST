
#include <iostream>
#include "Tree.hpp"
using namespace std ;
using namespace ariel ;
using namespace Tree ;
struct Node {
    Node::Node(int val) // Counstructor with value
    {
        root = NULL;
        left = NULL;
        right = NULL;
        value = val;
    }

    Node::Node() // Empty counstructor
    {
        root = NULL;
        left = NULL;
        right = NULL;
    }

};

        // Constructors
        ariel::Tree::Tree()
        {
           Tree::this->root=NULL;

        }
        /*
         *distractor
         */
        ariel::Tree:: ~Tree(){
            makeemptytree(root);
        }

       void ariel::Tree:: makeemptytree(Node *leaf){
        if (leaf != NULL) {
            dreg:: emptytree(leaf->left);
            dreg:: emptytree(leaf->right);
            delete leaf;
        }
        return NULL;
    }
    bool ariel::Tree::contains(int i ){
        Node* t = Find(root, i);
        if(t==NULL)return false;
        else
            return true ;
    }
        /*
         * contains(int i) : Find a node the tree with value i. Its O(lgn)
         */
    bool ariel::Tree:: Find(Node *r, int x){
        if (r==NULL){
            return false ;
        }
        else if (x>r->data){
            return contains(r->left,x);
        }else if(x<r->data){
            return contains(r->right,x);
        }
        return r;
    }
        /*
         * Insert(int data) : Add a node the tree with value data Its O(lgn)
         */
        void ariel::Tree:: insert(int data){
            if (root==NULL ){
                root=new Node(data);

            }else{
                this->insertHelper(root,data);
            }
        }
        void ariel::Tree::insertHelper(Node *root,int value){
        if (root->data==value){
            throw invalid_argument("This number is available in the tree");
        }
        else if (root->data > value ){
            root->left=  insert(root->left,value);
        }
        if (value >root->root){
            root->right=  insert(root->right,value);
        }

    }
        /*
         * remove (int i) : remove a node the tree with value n. Its O(lgn)
         */
        bool ariel::Tree:: remove(int i ){
            Node* parent = root;
            Node* current = root;
            bool isLeftChild = false;
            while(current->data!=id){
                parent = current;
                if(current->data>id){
                    isLeftChild = true;
                    current = current->left;
                }else{
                    isLeftChild = false;
                    current = current->right;
                }
                if(current ==NULL){
                    return false;
                }
            }
            //if i am here that means we have found the node
            //Case 1: if node to be deleted has no children
            if(current->left==NULL&& current->right==NULL){
                if(current==root){
                    root = NULL;
                }
                if (!isLeftChild) {
                    parent->right = NULL;
                } else {
                    parent->left = NULL;
                }
            }
                //Case 2 : if node to be deleted has only one child
            else if(current->right==NULL){
                if(current==root){
                    root = current->left;
                }else if(isLeftChild){
                    parent->left = current->left;
                }else{
                    parent->right = current->left;
                }
            }
            else if(current->left==NULL){
                if(current==root){
                    root = current->right;
                }else if(isLeftChild){
                    parent->left = current->right;
                }else{
                    parent->right = current->right;
                }
            }else if(current->left!=NULL && current->right!=NULL){

                //now we have found the minimum element in the right sub tree
                Node* successor	 = getSuccessor(current);
                if(current==root){
                    root = successor;
                }else if(isLeftChild){
                    parent->left = successor;
                }else{
                    parent->right = successor;
                }
                successor->left = current->left;
            }
            return true;
        }

        int  ariel::Tree:: size (){
            return sizehelp(this->root);

        }
        int ariel::Tree::sizehelp(Node *root){
            if (root==NULL){
                size=0;
                return size;
            }
            else return 1+sizehelp(root->left)+sizehelp(root->right);

        }



        int ariel::Tree::root(){
            if (root == NULL)
                throw "No root node";
            return root->value;
        }

        int ariel::Tree:: parent (int i ){
            Node* temp =parent(root,i);
            if (temp==NULL) {
                throw::invalid_argument("No Parent found");

            }
            else
                return temp->data;

        }
        void ariel::Tree::print() const  {
            display(root);
            cout << endl;
}

         /*
           * inorder
           * */
         void ariel::Tree:: display(Node* t){
          if (t == NULL)
            return;
             display(t->left);
             cout << t->data << " ";
             dreg::display(t->right);
        }
    Node* ariel::Tree::parent(Node *root, int i) {
        if (root->data == i) {
            if (root->left == NULL) {
                return NULL;
            }
            else if ((root->left != NULL && root->left->data == i) || (root->right != NULL && root->right->data == i)) {

                return  root;
            }
            if (dreg::parent(root->left, i) != NULL) {
                return dreg::parent(root->left, i);
            }

            else if (dreg::parent(root->right, i) != NULL) {

                return 	dreg::parent(root->right, i);

            }
        }
    }
        int ariel::Tree::right (int i ){
            return right (Node *r,i)
        }
    int ariel::Tree:: right (Node *r,int i){
        if (r->data==i){
            if (root->right==NULL){
                cout << "No right Child for"<< i << endl;
                return -1;
            }else return  r->right->data;
        }
        if (i<r.data){
            right(r->left,i);
        }
        else if (i>r->data){
            right(r->right,i);
        }
    }
        int ariel::Tree:: left(int i){

            return left (root,i)
        }

        int ariel::Tree:: left (Node *r ,int i ){
            if (r->data==i){
                if (root->left==null){
                    cout << "No Left Child for"<< x << endl;
                    return -1;
                }else return  r->left->data;
            }
            if (i<r->data){
                left(r->left,i);
            }
            else if (i>r->data){
                left(r->right,i);
            }
        }


    };


