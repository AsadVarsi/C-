#include<iostream>
#include<stdlib.h>
using namespace std;
/******************************************/
void MaxHeapify(int a[],int i,int n){
    int l,r,max;
    while (2*i+1 <= n){
        l=2*i+1;
        r=l+1;
        max=l;
        if(r<=n){
            if(a[r]>a[l])
            max=r;
        }
        if(a[max]>a[i])
        swap(a[max],a[i]);
        else
        break;
        i=max;
    }
}
/******************************************/
void BuildMaxHeap(int a[],int n){
    int i;
    for(i=(n-1)/2;i>=0;i--){
        MaxHeapify(a,i,n);
    }
}
/******************************************/
void HeapSort(int a[],int n){
    BuildMaxHeap(a,n);
    int last=n;
    while(last>0){
        swap(a[0],a[last]);
        MaxHeapify(a,0,last-1);
        last--;
    }

}
/******************************************/
void traverse(int a[],int n){
    for(int i=0;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
/******************************************/
int main()
{
    int a[10]={60,50,100,20,10,200,30,150,160,120};
    int n=9;
    HeapSort(a,n);
    traverse(a,n);
}