#include<bits/stdc++.h>
using namespace std;

int main()
{
int b = 3;
// 1st method (directly xor from 0 to a)->T.C O(b)

// 2nd Method (by obervation there is a pattern in 4-4 packs)
int check = b%4;
if(check == 0)cout<<b;
else if(check == 1)cout<<"1";
else if(check == 2)cout<<b+1;
else if(check == 3)cout<<"0";


return 0 ;
}