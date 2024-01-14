#include<iostream>
#include<stdio.h>
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
void PreOrderTraversal(struct node *t){
    if(t!=NULL){
        cout<<t->data<<" ";
        PreOrderTraversal(t->left);
        PreOrderTraversal(t->right);
    }
}
/******************************************/
void InOrderTraversal(struct node *t){
    if(t!=NULL){
        InOrderTraversal(t->left);
        cout<<t->data<<" ";
        InOrderTraversal(t->right);
    }
}
/******************************************/
void PostOrderTraversal(struct node *root){
    struct node *t;
    t=root;
    if(t!=NULL){
        PostOrderTraversal(t->left);
        PostOrderTraversal(t->right);
        cout<<t->data<<" ";
    }
}
/******************************************/

/******************************************/
int main()
{
    struct node *root=NULL;
    root=makenode(1);
    root->left=makenode(2);
    root->right=makenode(5);
    root->left->left=makenode(3);
    root->left->right=makenode(4);
    root->right->right=makenode(6);
    PreOrderTraversal(root);
    printf("\n\n");
    InOrderTraversal(root);
    printf("\n\n");
    PostOrderTraversal(root);
    printf("\n\n");

}