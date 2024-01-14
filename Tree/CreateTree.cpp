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
int main()
{
    struct node *root=NULL;
    CreateTree(&root);
    PreOrderTraversal(root);
    printf("\n\n");
    InOrderTraversal(root);
    printf("\n\n");
    PostOrderTraversal(root);
    printf("\n\n");

}