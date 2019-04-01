#include <iostream>
#include "Tree.hpp"
using namespace std ;
//////////////////////////

// Constructors
ariel::Tree::Tree()
{
    Tree::myroot=NULL;
}
//////////////////////////

void ariel::Tree::DestroyTree(Node *curr) // Destroy all subtrees of current node
{
    if (curr)
    {
        DestroyTree(curr->left);
        DestroyTree(curr->right);
        delete curr;
    }
}

ariel::Tree::~Tree() // Deconstructor for tree
{
    DestroyTree(myroot);
}
//////////////////////////

/*
 * contains(int i) : Find a node the tree with value i. Its O(lgn)
 */
Node* ariel::Tree::Find(Node *r,int x){
    if(r!=NULL){
        if(x==r->data)
            return r;
        if(x<r->data)
            return ariel::Tree::Find(r->left,x);
        else
            return ariel::Tree::Find(r->right,x);
    }
    else return NULL;
}
//////////////////////////

bool ariel::Tree::contains(int i ){
    if(Find(myroot, i)==NULL)
        return false;
    else
        return true ;
}
//////////////////////////

/*
 * Insert(int data) : Add a node the tree with value data Its O(lgn)
 */
void ariel::Tree:: insert(int data){
    if(contains(data))
        throw "error!";
    if (myroot==NULL ){
        myroot=new Node;
        myroot->data=data;
        myroot->left=NULL;
        myroot->right=NULL;
        myroot->root=NULL;
        helpsize++;
    }else{
        insertHelper(myroot,data);
        helpsize++;
    }
}
//////////////////////////

void ariel::Tree::insertHelper(Node *r,int value){

    if (r->data > value ) {
        if(r->left!=NULL){
            insertHelper(r->left, value);
        }else {
            r->left =new Node ;
            r->left->data=value;
            r->left->root=r;
            r->left->left=NULL;
            r->left->right=NULL;
        }
    }
   else if (value > r->data)  {
        if(r->right!=NULL){
            insertHelper(myroot->right,value);
        }
        else {
            r->right =new Node ;
            r->right->data=value;
            r->right->root=r;
            r->right->right=NULL;
            r->right->left=NULL;
        }
    }
}


//////////////////////////

/*
 * remove (int i) : remove a node the tree with value n. Its O(lgn)
 */
void ariel::Tree:: remove(int x)
    {
        if(!contains(x))
            throw "error!";
        if(myroot!=NULL){
            if(myroot->data==x){
                myroot=NULL;
                delete myroot;
            }
            ariel::Tree::remove(myroot,x);
            helpsize--;
        }
    }
//////////////////////////

    int  ariel::Tree::size(){
        return helpsize;
    }

    //////////////////////////

    
    
    int ariel::Tree::root(){
        if (myroot == NULL)
            throw::invalid_argument( "No root node");
        return myroot->data;
    }
    
    
    ///////////////////////////////////
    /*
     * inorder
     * */
void ariel::Tree::display(Node *root, int space)const
{
    // Base case
    if (root == NULL)
        return;
    
    // Increase distance between levels
    space += helpsize;
    
    // Process right child first
    ariel::Tree::display(root->right, space);
    
    // Print current node after space
    // count
    cout<<endl;
    for (int i = helpsize; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";
    
    // Process left child
    ariel::Tree::display(root->left, space);
}
//////////////////////////


    Node* ariel::Tree::remove(Node* myroot, int data) {
	if (myroot == NULL)
        return myroot;

    if (data < myroot->data){

		Node* temp=ariel::Tree::remove(myroot->left, data);
        myroot->left =temp;
		}
   
    else if (data > myroot->data)
		{

			Node* temp=ariel::Tree::remove(myroot->right, data);
        myroot->right=temp;
}else
    {
      
        if (myroot->left == NULL)
        {
            Node *temp = myroot->right;
            delete myroot;
            return temp;
        }
        else if (myroot->right== NULL)
        {
            Node *temp = myroot->left;
            
            delete myroot;
            return temp;
        }
        //////////////////////////

        Node *temp = ariel::Tree::findMin(myroot->right);

      
        myroot->data=(temp->data);

        // Delete the inorder successor
        myroot->right=(ariel::Tree::remove(myroot->right, temp->data));
    }
    return myroot;
}

//////////////////////////

    Node* ariel::Tree::findMin(Node* t)
    {
	if(t == NULL)
		return NULL;
	else if(t->left == NULL)
		return t;
	else
		return ariel::Tree::findMin(t->left);
    }
         //////////////////////////

            void ariel::Tree::print() const{
                ariel::Tree::display(myroot,0);
            }
         //////////////////////////

            int ariel::Tree::parent(int num) //return value of the parent of num
            {
                   Node *temp = Find(myroot,num);
                 if (temp == NULL)
                {
                 throw "The number isn't in the tree";
                 }
              if (temp->root == NULL)
                  {
                       throw "No parent";
                 }
                   return temp->root->data;
                }

         /*   int ariel::Tree:: parent (int i ){
                Node *temp =Find(myroot,i);
                if(temp!=NULL){
                    if (temp->root==NULL) {
                        throw::invalid_argument("No Parent found");
                    }
                    else
                        return temp->root->data;
                }
                else
                    throw "error!";
            }*/
//////////////////////////

            int ariel::Tree::right (int i ){
                Node *t=Find(myroot, i);
                if(t->right==NULL)
                    throw "error!";
                else
                    return t->right->data;
            }
//////////////////////////

            int ariel::Tree::left(int i){
                Node *t=Find(myroot, i);
                if(t==NULL||t->left==NULL)
                    throw "error!";
                else
                    return t->left->data;
            }
