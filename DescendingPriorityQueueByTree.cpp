#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
/******************************************/
void MaxHeapify(int a[], int i, int n)
{
    int l, r, max;
    while (2 * i + 1 <= n)
    {
        l = 2 * i + 1;
        r = l + 1;
        max = l;
        if (r <= n)
        {
            if (a[r] > a[l])
                max = r;
        }
        if (a[max] > a[i])
            swap(a[max], a[i]);
        else
            break;
        i = max;
    }
}
/******************************************/
void Enqueue(int a[], int *n, int x)
{
    a[*n + 1] = x;
    *n = *n + 1;
    int p, c;
    p = (*n - 1) / 2;
    c = *n;
    while (c > 0 && a[c] > a[p])
    {
        swap(a[c], a[p]);
        c = p;
        p = (p - 1) / 2;
    }
}
/******************************************/
int DeQueue(int a[], int *n)
{
    int x;
    x = a[0];
    a[0] = a[*n];
    (*n) = (*n - 1);
    MaxHeapify(a, 0, *n);
}
/******************************************/
void BuildMaxHeap(int a[],int n){
    int i;
    for(i=(n-1)/2;i>=0;i--){
        MaxHeapify(a,i,n);
    }
}
void Traverse(int a[], int n)
{
    for (int i = 0; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
/******************************************/

int main()
{
    //    int a[100];
    //    int n=-1;
    int a[100] = {10, 20, 40, 60, 70};
    int n = 4;
    BuildMaxHeap(a,4);
    while (1)
    {
        int ch;
        cout << "1.EnQueue\n2.DeQueue\n3.Traverse";
        cin >> ch;

        if (ch == 1)
        {
            int x;
            cout << "Enter Desired Element";
            cin >> x;
            Enqueue(a, &n, x);
        }
        else if (ch == 2)
            DeQueue(a, &n);
        else if (ch == 3)
            Traverse(a, n);
        else
            cout << "Valid Choice\n";
    }
}
