#include <algorithm>
#include "bTree.h"
#include <iostream>
#include <list>
using namespace std;

/*
int maxDepth(node root, int curDepth){
    int depth=0;
    if(&root==NULL){
        depth= curDepth;
    }
    else{
        curDepth++;
        if(root.left!=NULL&&root.right!=NULL){
            depth= max(maxDepth(*root.left,curDepth),maxDepth(*root.right,curDepth));
        }
        else if(root.left!=NULL){
            depth= maxDepth(*root.left,curDepth);
        }
        else if(root.right!=NULL){
            depth= maxDepth(*root.right,curDepth);
        }
        else{
            depth= curDepth;
        }
    }
    return depth;
}
int minDepth(node root, int curDepth){
    int depth=0;
    if((&root)==NULL){
        depth =curDepth;
    }
    else{
        curDepth++;
        if(root.left!=NULL&&root.right!=NULL){
             depth= min(minDepth(*root.left,curDepth),minDepth(*root.right,curDepth));
        }
        else{
             depth=curDepth;
        }
    }
    return depth;
}
node inOrderSuccessor(node root){
}
bool checkBalanced(node root){
    return ((maxDepth(root,0)-minDepth(root,0))>1?false: true);

}
*/

/*
 *inOrderTraversal:
 LeftCurrentRight
 if we have right child print it
 if we do not have
 go up til parent has right child 
 if it has go to leftmost leaf or right child of parent

 if our parent is root and  does not have children right of us print null
 if it has children go to leftmost of rigt

 so check if we r left child in some substree 
 if not null
 if we are left go to right and print leftmost pf it
 
 *
 *
 * */
node inOrderTraversal(node root,int key,int &answer){ 
    node *ans=new node();
    ans.data=root.data;
    if(&root!=NULL){
        if(root.left!=NULL){
            inOrderTraversal(*root.left,key,answer);
        }
        cout<<root.data<<" ";
        if(root.right!=NULL){ 
            if(root.data==key){
                answer=inOrderTraversal(*root.right,key,answer).data;
            }
            else{
                ans.data=-1;
                inOrderTraversal(*root.right,key,answer);
            }
        }
    }
    return ans;
}
node bTree:: inOrderSuccessor(int data,int &answer){
    return inOrderTraversal(*root,data,answer);
}
int main(){
    bTree bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);
    bt.insert(8);
    bt.insert(9);
    bt.insert(10);
    int answer=-1;
    //bt.print();
    //
    cout<<bt.inOrderSuccessor(3,answer).data;
    cout<<answer;
    //cout<<endl<<< inOrderTraversal(*bt.root).data<<endl;

    bTree bt2;
    bt2.insert(2);
    bt2.insert(1);
    bt2.insert(3);
    
   
    return 0;
}
