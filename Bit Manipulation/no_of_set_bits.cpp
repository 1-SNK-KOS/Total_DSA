#include<bits/stdc++.h>
using namespace std;

int main()
{
int num = 132445;
cout << bitset<32>(num).to_string().substr(32 - log2(num))<<endl;
int count = 0;

// Complement Method (rightmost set bit method)
// while(num>0){
//     num-=(num & (-num));
//     count++;
// }

// Less than by 1 method
// while(num>0){
//     count++;
//     num = num & (num-1);
// }

//Built in method
cout<<__builtin_popcount(num);

// cout<<count;
return 0 ;
}