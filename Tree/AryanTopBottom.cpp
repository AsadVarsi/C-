#include <iostream>
#include <stdlib.h>
#include <queue>
#include <math.h>
using namespace std;

struct node
{
    int data;
    struct node *right;
    struct node *left;
    int level;
    int hd;
};

struct node *makenode(int x)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->right = NULL;
    p->left = NULL;
    return p;
};

void CreateTree(struct node **root)
{
    struct node *p, *q;
    int choice, x;
    if (*root == NULL)
    {
        cout << ("Enter the root node");
        cin >> x;
        p = makenode(x);
        *root = p;
        CreateTree(&(*root));
    }

    else
    {
        cout << "Whether the left of %d exist ?(0/1)" << (*root)->data;
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter the data of left node");
            cin >> x;
            p = makenode(x);
            (*root)->left = p;
            CreateTree(&p);
        }
        cout << "Whether the right of %d exist ?(0/1)" << (*root)->data;
        cin >> choice;
        if (choice == 1)
        {
            cout << ("Enter the data of right node");
            cin >> x;
            p = makenode(x);
            (*root)->right = p;
            CreateTree(&p);
        }
    }
}

int Height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            return 0;
        }
        else
        {
            return 1 + fmax(Height(root->left), Height(root->right));
        }
    }
}

void LevelorderTraversal(struct node *T)
{
    queue<struct node *> Q;
    Q.push(T);
    while (Q.size() != 0)
    {
        struct node *x;
        x = Q.front();
        Q.pop();
        cout << x->data << " ";
        if (x->left != NULL)
            Q.push(x->left);
        if (x->right != NULL)
            Q.push(x->right);
    }
}

void ZigzagTraversl(struct node *T)
{
    queue<struct node *> Q;
    Q.push(T);
    int h = Height(T);
    vector<int> HT[h + 1];
    HT[0].push_back(T->data);
    while (Q.size() != 0)
    {
        struct node *x;
        x = Q.front();
        Q.pop();
        if (x->left != NULL)
        {
            Q.push(x->left);
            x->left->level = x->level + 1;
            HT[x->left->level].push_back(x->left->data);
        }

        if (x->right != NULL)
        {
            Q.push(x->right);
            x->right->level = x->level + 1;
            HT[x->right->level].push_back(x->right->data);
        }
    }
    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j < HT[i].size(); j++)
        {
            cout << HT[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << "Zig" << endl;

    for (int i = 0; i <= h; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < HT[i].size(); j++)
            {
                cout << HT[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int j = HT[i].size() - 1; j >= 0; j--)
            {
                cout << HT[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl
         << "LeftView" << endl;

    for (int i = 0; i <= h; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cout << HT[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << "RightView" << endl;

    for (int i = 0; i <= h; i++)
    {
        for (int j = HT[i].size() - 1; j <= HT[i].size() - 1; j++)
        {
            cout << HT[i][j] << " ";
        }
        cout << endl;
    }
}

void Treeleftright(struct node *T)
{
    queue<struct node *> Q;
    Q.push(T);
    T->hd = 0;
    int h = Height(T);
    vector<int> HT[2 * h + 1];

    HT[0 + h].push_back(T->data);
    while (Q.size() != 0)
    {
        struct node *x;
        x = Q.front();
        Q.pop();
        if (x->left != NULL)
        {
            Q.push(x->left);
            x->left->hd = x->hd - 1;
            HT[(x->left->hd) + h].push_back(x->left->data);
        }

        if (x->right != NULL)
        {
            Q.push(x->right);
            x->right->hd = x->hd + 1;
            HT[(x->right->hd) + h].push_back(x->right->data);
        }
    }

    cout << "Top View" << endl;
    for (int i = 0; i <= 2 * h; i++)
    {
        if (HT[i].size() != 0)
        {
            cout << HT[i][0] << " ";
        }
    }

    cout << "Bottom View\n"
         << endl;
    for (int i = 0; i <= 2 * h; i++)
    {
        int l = HT[i].size();
        if (HT[i].size() != 0)
        {
            cout << HT[i][l - 1] << " ";
        }
    }

    cout << "Vertical Traversal\n"
         << endl;

    for (int i = 0; i <= 2 * h; i++)
    {
        int h = HT[i].size();

        for (int j = 0; j < h; j++)
        {
            if (HT[i].size() != 0)
            {
                cout << HT[i][j] << " ";
            }
        }
        cout << endl;
    }
}
int main()
{
    struct node *root = NULL;
    CreateTree(&root);
    LevelorderTraversal(root);
    cout << endl;
    ZigzagTraversl(root);

    cout << endl;
    Treeleftright(root);
}