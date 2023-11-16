#include <bits/stdc++.h> 
int flipBits(int* arr, int n) 
{
    // WRITE YOUR CODE HERE
    // not working 
//     int count=0;
//     int maxones = 0;
//     for(int i=0;i<n;i++){
//        if(arr[i]) count++;
//         arr[i]^=1;
//     }
//     // cout<<count<<endl;
//    int extra = 0;
//    int total = 0;
//    for(int i=0;i<n;i++){
//        if(arr[i]){
//        extra++;
//        total++;
//        }
//        else{
//         //    cout<<extra<<endl;
//            extra = 0;
//        } 
//       maxones = max(maxones,extra);
//    }
//   if(total<count+maxones)  return count + maxones;
//   return total;


/*

int ans = 0;
int ones = 0;
int maxval = 0;
for(int i=0;i<n;i++){
    if(arr[i])ones++;
   
    int count0 = 0,count1=0;
    for(int j=i;j<n;j++){
      if(arr[j])count1++;
      else count0++;

      maxval = max(maxval,count0 - count1);
    }
}

return maxval + ones;
*/

int total_one = 0;
int maxval = 0;
int currsum = 0;
for(int i=0;i<n;i++){

    if(arr[i]) total_one++;

    int val = 0;
    if(arr[i]) val=-1;
    else val = 1;
 
 currsum = max(val,currsum+val);
 maxval = max(maxval,currsum);

}

return maxval + total_one;
}