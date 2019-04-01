#include <iostream>
#include "Tree.hpp"
using namespace std ;

// Constructors
ariel::Tree::Tree()
{
    Tree::myroot=NULL;
}
/*
 *distractor
 */
ariel::Tree:: ~Tree(){
    makeemptytree(myroot);
}

void ariel::Tree:: makeemptytree(Node *leaf){
    if (leaf != NULL) {
        makeemptytree(leaf->right);
        makeemptytree(leaf->left);
        delete leaf;
    }
}
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
bool ariel::Tree::contains(int i ){
    if(Find(myroot, i)==NULL)
        return false;
    else
        return true ;
}

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

    int  ariel::Tree::size(){
        return helpsize;
    }

    
    
    
    int ariel::Tree::root(){
        if (myroot == NULL)
            throw::invalid_argument( "No root node");
        return myroot->data;
    }
    
    
    
    /*
     * inorder
     * */
void ariel::Tree::display(Node *root, int space)
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


    Node* ariel::Tree::remove(Node* root, int k) {
        
        // Base case
        if (root == NULL)
            return root;
        
        // Recursive calls for ancestors of
        // node to be deleted
        if (root->data > k) {
            root->left = remove(root->left, k);
            return root;
        }
        else if (root->data < k) {
            root->right = remove(root->right, k);
            return root;
        }
        
        // We reach here when root is the node
        // to be deleted.
        
        // If one of the children is empty
        if (root!=NULL&&root->left == NULL) {
            Node* temp = root->right;
            root=NULL;
            delete root;
            return temp;
        }
        else if (root!=NULL&&root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        // If both children exist
        else {
            
            Node* succParent = root->right;
            
            // Find successor
            Node *succ = root->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }
            
            // Delete successor.  Since successor
            // is always left child of its parent
            // we can safely make successor's right
            // right child as left of its parent.
            succParent->left = succ->right;
            
            // Copy Successor Data to root
            root->data = succ->data;
            
            // Delete Successor and return root
            delete succ;
            return root;
        }
    }
            void ariel::Tree::print() {
                ariel::Tree::display(myroot,0);
            }
         
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

            int ariel::Tree::right (int i ){
                Node *t=Find(myroot, i);
                if(t->right==NULL)
                    throw "error!";
                else
                    return t->right->data;
            }

            int ariel::Tree::left(int i){
                Node *t=Find(myroot, i);
                if(t==NULL||t->left==NULL)
                    throw "error!";
                else
                    return t->left->data;
            }
