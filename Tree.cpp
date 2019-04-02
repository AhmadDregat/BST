#include <iostream>
#include "Tree.hpp"
using namespace std ;
//////////////////////////

// Constructors
ariel::Tree::Tree()
{
    helpsize=0;
    Tree::myroot=NULL;
}


/////////////////////////
void ariel:: Tree::rmAll(Node* root){
    if(root==NULL)return;
    rmAll(root->left);
    rmAll(root->right);
    if(root->data==myroot->data){
        delete myroot->root;
        myroot->root=NULL;
    }
    delete root;
    root=NULL;
}
ariel::Tree::~Tree(){
    rmAll(myroot);
}
//////////////////////////

/*
 * Find(int i) : Find a node the tree with value i. Its O(lgn)
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
void ariel::Tree::insertHelp(int key,Node *leaf){
    if(key< leaf->data){
        if(leaf->left!=NULL)
            insertHelp(key, leaf->left);
        else{
            leaf->left=new Node;
            leaf->left->data=key;
            leaf->left->left=NULL;
            leaf->left->right=NULL;
            leaf->left->root=leaf;
        }
    }
    else if(key>=leaf->data){
        if(leaf->right!=NULL)
            insertHelp(key, leaf->right);
        else{
            leaf->right=new Node;
            leaf->right->data=key;
            leaf->right->left=NULL;
            leaf->right->right=NULL;
            leaf->right->root=leaf;
        }
    }
    
}
void ariel::Tree::insert(int val){
    
    if(myroot!=NULL){
        if(contains(val))
            throw "the value is exists!";
        insertHelp(val,myroot);
        helpsize++;
    }
    else{
        myroot=new Node;
        myroot->data=val;
        myroot->left=NULL;
        myroot->right=NULL;
        myroot->root=NULL;
        helpsize++;
    }
}

  /*
 * Insert(int data) : Add a node the tree with value data Its O(lgn)
 *//*
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
*/


//////////////////////////

/*
 * remove (int i) : remove a node the tree with value n. Its O(lgn)
 */

//////////////////////////

    int  ariel::Tree::size(){
        return helpsize;
    }

    //////////////////////////

    
    
    int ariel::Tree::root(){
        if (myroot == NULL)
            throw "No root node";
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


  bool ariel::Tree::remove(int num)
{
    Node *del = Find(myroot,num);
    // If the number doesnt exist
    if (del == NULL)
        throw "No such number to remove";
    // Node is a leaf
    if (del->left == NULL && del->right == NULL)
    {
        if (del->root != NULL)
        {
            if (del->root->right == del)
                del->root->right = NULL;
            else
                del->root->left = NULL;
        }
        // Node is root
        else
        {
            myroot = NULL;
        }
        delete del;
        helpsize--;
        return true;
    }
    // Node has one child
    else if (del->left == NULL || del->right == NULL)
    {
        Node *temp = NULL;
        if (del->left == NULL)
            temp = del->right;
        if (del->right == NULL)
            temp = del->left;

        if (del->root != NULL)
        {
            temp->root = del->root;
            if (del->root->right == del)
                del->root->right = temp;
            else
                del->root->left = temp;
        }
        // Node is root
        else
        {
            myroot = temp;
            temp->root = NULL;
        }

        delete del;
        helpsize--;
        return true;
    }
    else if (del->left != NULL && del->right != NULL)
    {
        // look for inorder successor
        Node *next = FindNextNode(del);
        int temp = next->data;
        // Use recursive call to delete the next node
        remove(temp);
        // Change value
        del->data = temp;
        return true;
    }
    return false;
}

         //////////////////////////
Node *ariel::Tree::FindNextNode(Node *curr) // Find the next number after num using current node
{
    Node *next = curr->right;
    while (next->left != NULL)
    {
        next = next->left;
    }
    return next;
}
         //////////////////////////  
            void ariel::Tree::print() const //print the tree inorder values
            {
               cout << endl;
               if (myroot == NULL)
               cout << "Tree is empty";
                else
                display(myroot,10);
                 cout << endl;
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

//////////////////////////

int ariel::Tree::right(int num) //return value of the left child
{
    Node *temp = Find(myroot, num);
    if (temp == NULL)
    {
        throw "The number isn't in the tree";
    }
    if (temp->right == NULL)
    {
        throw "No right child";
    }
    return temp->right->data;
}
//////////////////////////

          
 int ariel::Tree::left(int num) //return value of the left child
{
    Node *temp = Find(myroot, num);
    if (temp == NULL)
    {
        throw "The number isn't in the tree";
    }
    if (temp->left == NULL)
    {
        throw "No left child";
    }
    return temp->left->data;
}
