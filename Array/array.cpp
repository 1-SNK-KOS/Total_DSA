#include<bits/stdc++.h>
using namespace std;

// Array is also a pointer when u pass as usual also
void change(int a[]){
    a[1] = 5;
}

int main()
{
int arr[] = {1,2,3,4};

change(arr);

cout<<arr[1];
return 0 ;
}