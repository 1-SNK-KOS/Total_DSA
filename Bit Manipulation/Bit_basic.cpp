#include<bits/stdc++.h>
using namespace std;

int main()
{
  // Find no is odd or even
 /* int no = 0;
  cout<<"Enter no :"<<endl;
  cin>>no;

  if(no & 1) cout<<"Odd";
  else cout<<"Even";
*/

/*
// Every no appears twice leaving one no find it
int arr[7] = {1,2,3,4,3,2,1};
// one method is hashmap or array[maxno] or array[maxconstraints]
// By bits
int splno = 0;
for(auto x:arr){
   splno^=x;
}
cout<<splno;
*/

/*
// Find the ith bit 
int no = 13;
int i = 3;
int j = 2;

cout<<(no & (1<<(i-1)))<<"\n";
cout<<(no & (1<<(j-1)));
*/

/*
// Set the ith bit->turn it into 1  (or)
// Reset the ith bit ->turn it into 0 (and)
int no = 13; // 1101
int i = 2; // Set
int j = 2; // Reset

no = no | (1<<(i-1)); // 1111
cout<<(no)<<"\n";     // 15
cout<<(no & (1<<(i-1)))<<"\n";  // 2
no = no & ~(1<<(i-1)); // 1101
cout<<(no)<<"\n";   // 13
cout<<(no & (1<<(i-1)));  // 0
*/

// Find pos of right most set bit -> pos of rightmost 1 in binary representation of number
int no = 364;
for(int i=0;i<9;i++){
    if(no & (1<<i))cout<<i+1;
}
return 0 ;
}