#include<iostream>
#include<vector>
#include<queue>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    int level;
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
    struct node *p;
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
int max(int a,int b){
    if(a>b)
    return a;
    else
    return b;
}
/******************************************/
int Height(struct node *t){
    if(t==NULL)
    return 0;
    else{
        if(t->left==NULL &&t->right==NULL)
        return 0;
        else
        return 1+max(Height(t->left),Height(t->right));
    }
}
/******************************************/
void LevelOrderTraversal(struct node *t){
    queue<struct node *>q;
    q.push(t);
    int h=Height(t);
    vector<int> ht[h+1];
    t->level=0;
    ht[0].push_back(t->data);
    while(q.size()!=0){
        struct node *x;
        x=q.front();
        q.pop();
        if(x->left!=NULL)
        {
            q.push(x->left);
            x->left->level=x->level+1;
            int i=x->left->level;
            ht[i].push_back(x->left->data);
        }
        if(x->right!=NULL)
        {
            q.push(x->right);
            x->right->level=x->level+1;
            int i=x->right->level;
            ht[i].push_back(x->right->data);
        }
    }
    cout<<"LevelOrder";
    cout<<"\n";
    for(int i=0;i<=h;i++){
        for(int j=0;j<ht[i].size();j++){
            cout<<ht[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"ZigZag";
    cout<<"\n";
    for(int i=0;i<=h;i++){
        if(i%2==0){
            for(int j=0;j<ht[i].size();j++){
            cout<<ht[i][j]<<" ";
            }
        }
        else{
            for(int j=ht[i].size()-1;j>=0;j--){
                cout<<ht[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
    cout<<"LeftView";
    cout<<"\n";
    for(int i=0;i<=h;i++){
        for(int j=0;j==0;j++){
            cout<<ht[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"RightView";
    cout<<"\n";
    for(int i=0;i<=h;i++){
        for(int j=ht[i].size()-1;j==ht[i].size()-1;j--){
            cout<<ht[i][j]<<" ";
        }
        cout<<"\n";
    }

}

/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/
/******************************************/

int main()
{
    struct node *root=NULL;
    CreateTree(&root);
    LevelOrderTraversal(root);
}
