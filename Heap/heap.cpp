#include<bits/stdc++.h>
using namespace std;

class heap{

int a[100];
int size;

public:
heap(){
    size = 0;
    a[0] = -1;
}

// T.C O(logN)
void insert(int val){

    a[++size] = val;
    int idx = size;

    while(idx>1){
        int parent = idx/2;
        if(a[parent] < a[idx]){
            swap(a[parent],a[idx]);
            idx = parent;
        }
        else{
            return ;
        }
    }
    
}

// Whenever we call this is for deleting root node
// T.C O(logN)
void deleteheap(){

if(size == 0) {
cout<<"No element to delete"<<endl;

return ;
}
// at root leaf node val is replaced
a[1] = a[size];
--size;

int idx = 1;
while(idx<size){
    int i = idx;
int leftchild = 2*idx;
int rightchild = 2*idx + 1;

if(leftchild < size && a[leftchild]>a[idx]){
    // swap(a[leftchild],a[idx]);
    idx = leftchild;
}
else if(rightchild < size && a[rightchild] > a[idx]){
    // swap(a[rightchild],a[idx]);
    idx = rightchild;
}
else{
    return ;
}

swap(a[idx],a[i]);

}

}



void print(){

    for(int i=1;i<=size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

};

// T.C O(logN)
void heapify(int (&a)[6] , int size , int index){
 
 while(index<size){
    int i = index;
    int left = index*2;
    int right = index*2+1;

    if(left<=size && a[left]>a[index]){
        // swap(a[index],a[left]);
        index = left;
    }
    if(right<=size && a[right]>a[index]){
    //    / swap(a[right],a[index]);
        index = right;
    }
    if(index!=i){
    swap(a[index],a[i]);
    }
    else{
        return ;
    }
 }
}

void heapsort(int (&a)[6],int n){

    int t = n-1;
    while(t>1){

        swap(a[1],a[t]);

        t--;

        heapify(a,t,1);
    }
}
int main()
{
/*
heap h;

h.insert(60);
h.insert(55);
h.insert(53);
h.insert(54);
h.insert(59);

h.print();

h.deleteheap();
h.print();
*/
int arr[] = {-1,55,56,59,52,53};

int n = (sizeof(arr) / sizeof(arr[0]));
for(int i= n/2 ; i>=1 ;i--){
   /*int leftchild = i*2;
    int rightchild = i*2+1;

    if(leftchild<n && arr[leftchild]>arr[i]){
        heapify(arr,n,i);
    }
    else if(rightchild<n && arr[rightchild]>arr[i]){
        heapify(arr,n,i);
    }
*/
heapify(arr,n,i);
}

for(int i=0 ; i<n ;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;

heapsort(arr,n);

for(int i=1 ; i<n ;i++){
    cout<<arr[i]<<" ";
}


return 0 ;
}