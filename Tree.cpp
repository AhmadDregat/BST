

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
           Tree::this->myroot=NULL;

        }
        /*
         *distractor
         */
        ariel::Tree:: ~Tree(){
            makeemptytree(myroot);
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
        Node* t = Find(myroot, i);
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
        void ariel::Tree::insertHelper(Node *myroot,int value){
        if (myroot->data==value){
            throw invalid_argument("This number is available in the tree");
        }
        else if (myroot->data > value ){
            myroot->left=  insert(myroot->left,value);
        }
        if (value >myroot->data){
            myroot->right=  insert(myroot->right,value);
        }

    }
        /*
         * remove (int i) : remove a node the tree with value n. Its O(lgn)
         */
        bool ariel::Tree:: remove(int i ){
            Node* parent = myroot;
            Node* current = myroot;
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
                if(current==myroot){
                    myroot = NULL;
                }
                if (!isLeftChild) {
                    parent->right = NULL;
                } else {
                    parent->left = NULL;
                }
            }
                //Case 2 : if node to be deleted has only one child
            else if(current->right==NULL){
                if(current==myroot){
                    myroot = current->left;
                }else if(isLeftChild){
                    parent->left = current->left;
                }else{
                    parent->right = current->left;
                }
            }
            else if(current->left==NULL){
                if(current==myroot){
                    myroot = current->right;
                }else if(isLeftChild){
                    parent->left = current->right;
                }else{
                    parent->right = current->right;
                }
            }else if(current->left!=NULL && current->right!=NULL){

                //now we have found the minimum element in the right sub tree
                Node* successor	 = getSuccessor(current);
                if(current==myroot){
                    myroot = successor;
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
            return sizehelp(this->myroot);

        }
        int ariel::Tree::sizehelp(Node *myroot){
            if (myroot==NULL){
                size=0;
                return size;
            }
            else return 1+sizehelp(myroot->left)+sizehelp(myroot->right);

        }



        int ariel::Tree::root(){
            if (myroot == NULL)
                throw "No root node";
            return myroot->value;
        }

        int ariel::Tree:: parent (int i ){
            Node* temp =parent(myroot,i);
            if (temp==NULL) {
                throw::invalid_argument("No Parent found");

            }
            else
                return temp->data;

        }
        void ariel::Tree::print() const  {
            display(myroot);
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
    Node* ariel::Tree::parent(Node *myroot, int i) {
        if (myroot->data == i) {
            if (myroot->left == NULL) {
                return NULL;
            }
            else if ((v->left != NULL && myroot->left->data == i) || (myroot->right != NULL && myroot->right->data == i)) {

                return  myroot;
            }
            if (dreg::parent(myroot->left, i) != NULL) {
                return dreg::parent(myroot->left, i);
            }

            else if (dreg::parent(myroot->right, i) != NULL) {

                return 	dreg::parent(myroot->right, i);

            }
        }
    }
        int ariel::Tree::right (int i ){
            return right (Node *r,i)
        }
    int ariel::Tree:: right (Node *r,int i){
        if (r->data==i){
            if (myroot->right==NULL){
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

            return left (myroot,i)
        }

        int ariel::Tree:: left (Node *r ,int i ){
            if (r->data==i){
                if (myroot->left==null){
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



