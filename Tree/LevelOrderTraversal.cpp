#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

/******************************************/
struct node *makenode(int x){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
/******************************************/
void CreateTree(struct node **root){
    struct node *p,*q;
    int choice,x;
    if((*root)==NULL){
        cout<<"Enter the data of Root Node";
        cin>>x;
        p=makenode(x);
        (*root)=p;
        CreateTree(&(*root));
    }
    else{
        printf("left of %d exist?(1/0) ",(*root)->data);
        cin>>choice;
        if(choice==1){
            cout<<"Enter the data of left node";
            cin>>x;
            p=makenode(x);
            (*root)->left=p;
            CreateTree(&p);
        }
        printf("right of %d exist?(1/0) ",(*root)->data);
        cin>>choice;
        if(choice==1){
            cout<<"Enter the data of right node";
            cin>>x;
            p=makenode(x);
            (*root)->right=p;
            CreateTree(&p);
        }
    }
}
/******************************************/
void LevelOrderTraversal(struct node *t){
    queue<struct node *>q;
    q.push(t);
    while(q.size()!=0){
        struct node *x;
        x=q.front();
        q.pop();
        cout<<x->data<<" ";
        if(x->left!=NULL)
        q.push(x->left);
        if(x->right!=NULL)
        q.push(x->right);
    }
    cout<<"\n";
}
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/

int main()
{

    // queue<int>q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);

    // int x=q.front();
    // q.pop();
    // cout<<x<<"\n";
    // x=q.front();
    // cout<<x;
    struct node *root=NULL;
    CreateTree(&root);
    LevelOrderTraversal(root);
}