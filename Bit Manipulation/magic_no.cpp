#include<bits/stdc++.h>
using namespace std;

int main()
{
int no = 3;
int ans = 0;

int base=1;
while(no>0){
    int digit = no&1;
    // ans+=(digit * pow(5,i));
    ans += digit * base;
    no = no>>1;
    base*=5;
}

cout<<ans;
return 0 ;
}