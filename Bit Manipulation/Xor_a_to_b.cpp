#include<bits/stdc++.h>
using namespace std;

int Xorcal(int num){
int check = num%4;
if(check == 0) return num;
else if(check == 1) return 1;
else if(check == 2) return num+1;
else if(check == 3) return 0;
}


int main()
{
int a = 3;
int b = 9;

cout<<(Xorcal(b) ^ Xorcal(a-1));

return 0 ;
}