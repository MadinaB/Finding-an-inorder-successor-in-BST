#ifndef bTree_h
#define bTree_h
#include <iostream>
#include <list>
#include <math.h> 
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
  bool visited=false;
};
class bTree{

public:
    bTree();
    ~bTree();

    void insert(int key);
    //node *search(int key);
    void destroy_tree();
    void print(node *leaf);
    void print();
    //bool checkBalanced();
    node  inOrderSuccessor(int data);
    list<pair<int,list<node> > > listOfDepths();

    //list<pair<node,list<node>>> depths=bt.listOfDepths();

    void destroy_tree(node *leaf);
    void insert(int key, node *leaf);
    //node *search(int key, node *leaf);

    node *root;
};



list<pair<int,list<node> > > bTree::listOfDepths(){

    list<pair<int,list<node> > > l;
    int level=0;
    list<node> queue;
    if(root!=NULL){
        root->visited=true;
        queue.push_back(*root);
        //l.push_back(make_pair(level,queue));
        int n=0;
        level=1;
        list<node> nodesOnLevel;
        nodesOnLevel.push_back(*root);
        while(!queue.empty()){
            node r=queue.front();
            queue.pop_front();
            cout<<level<<" n:"<<n<<" pow(2,n):"<<pow(2,n);
            if(level==pow(2,n)){
                //cout<<level<<endl;
                l.push_back(make_pair(n+1,nodesOnLevel));
                nodesOnLevel.clear();
                level=0;
                n++;
            
            }
            
        if(r.left!=NULL){
            if(r.left->visited==false){
                r.left->visited=true;
                nodesOnLevel.push_back(*r.left);
                queue.push_back(*r.left);
                //nodesOnLevel.push_back(*root.left);

            }
        }

        if(r.right!=NULL){
            if(r.right->visited==false){
                r.right->visited=true;
                nodesOnLevel.push_back(*r.right);
                queue.push_back(*r.right);
                //nodesOnLevel.push_back(*root->right);

            }
        }
            level+=2;
        }
        //if(!nodesOnLevel.empty()){
        if(level!=0){
            l.push_back(make_pair(n+1,nodesOnLevel));
        }
    }
    return l;
}
void bTree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->data=key;
    root->left=NULL;
    root->right=NULL;
  }
  //cout<<"root is:"<<root->data<<endl;
}
bTree::~bTree()
{
  destroy_tree();
}

bTree::bTree()
{
      root=NULL;
}

void bTree::destroy_tree()
{
  destroy_tree(root);
}

void bTree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}


void bTree::insert(int key, node *leaf)
{
  if(key< leaf->data)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->data=key;
      leaf->left->left=NULL;
      leaf->left->right=NULL;   
    }  
  }
  else if(key>=leaf->data)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->data=key;
      leaf->right->left=NULL;  
      leaf->right->right=NULL; 
    }
  }
}


void bTree::print()
{
    if(root!=NULL){

        cout<<" root is: ";
        cout<<root->data;

       // cout<<" left is: ";
        print(root->left);
        //cout<<" right is: ";
        print(root->right);
    }
}
void bTree::print(node *leaf)
{
    if(leaf!=NULL){
        cout<<leaf->data;
        cout<<" left is: ";
        print(leaf->left);
        cout<<" right is: ";
        print(leaf->right);
    }
}
#endif
