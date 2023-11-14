#include<bits/stdc++.h>
using namespace std;

int main()
{
int a = 2;
int b = 4;
int ans = 1;
int base = a;

while(b>0){
int last = b&1;
if(last!=0) ans*=( base);
base*=base;
b = b>>1;
}

cout<<ans;
return 0 ;
}