#include<bits/stdc++.h>

vector<int> howManyAreAnagrams(int n, int m, vector<string>& a, vector<string>& b) {
    // Write your code here. 
  /*  vector<pair<string,unordered_map<char,int>>>v;
    vector<int>ans;

    for(auto x:a){
      unordered_map<char,int>mp;
        for(auto y:x){
          mp[y]++;
        }
        v.push_back({x,mp});
    }

    vector<pair<string,unordered_map<char,int>>>w;
 
       for(auto x:b){
      unordered_map<char,int>mp;
        for(auto y:x){
          mp[y]++;
        }
        w.push_back({x,mp});
    }


    for(auto x:w){
        int anagrams = 0;
        for(auto y:v){
            if(x.first.size() == y.first.size()){
                int check=0;
               for(auto z:x.first){
                   if(x.second[z] == y.second[z]){
                     check++;
                   }
               }
               if(check == x.first.size()) anagrams++;
            }
        }
        ans.push_back(anagrams);
    }

    return ans;
    */
  vector<int>ans;

    for(int i=0;i<n;i++){
      string s = a[i];
      sort(s.begin(),s.end());
      a[i] = s;
    }
   
    for(int i=0;i<m;i++){
      string s = b[i];
      sort(s.begin(),s.end());
      b[i] = s;
    }
   
   for(int i=0;i<m;i++){
     int anagram = 0;
     for(int j=0;j<n;j++){
         if(b[i].size() == a[j].size()){
           if(b[i] == a[j])anagram++;
         }
     }
     ans.push_back(anagram);
   }

   return ans;
}

/*
    Time complexity: O( N * log(K1) + M * log(K2) )
    Space complexity: O( N )
    
    where 'N' is the length of the array 'A', 
    'M' is the length of array 'B', 
    'K1' is the average length of the strings in the array 'A' 
    and 'K2' is the average length of the strings in the array 'B'.
*/

vector<int> howManyAreAnagrams(int n, int m, vector<string>& a, vector<string>& b) {
    
    // Declaring hashmap 'freq'.
    unordered_map<string, int> freq;
    
    for (int i = 0; i < n; ++i) {
        
        // Declaring string 'temp'.
        string temp = a[i];
        
        // Sorting string 'temp'.
        sort(begin(temp), end(temp));
        
        // Incrementing frequency of 'temp' by '1'.
        freq[temp]++;
    }
    
    // Declaring integer array 'ans'.
    vector<int> ans(m, 0);
    
    for (int i = 0; i < m; ++i) {
        
        // Declaring string 'temp'.
        string temp = b[i];
        
        // Sorting string 'temp'.
        sort(begin(temp), end(temp));
        
        ans[i] = freq[temp];
    }
    
    return ans;
}