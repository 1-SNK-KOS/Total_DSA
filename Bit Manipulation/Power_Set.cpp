/*
    Time Complexity: O(2^N)
    Space Complexity: O(N*(2^N))

    Where N is the number of elements in array
*/
#include <bits/stdc++.h> 

void subsequence(vector<int> &v, vector<vector<int>> &ans,vector<int>seq,int idx){
    if(idx == v.size()){
        return ;
    }
    // s.insert(seq);
    subsequence(v,ans,seq,idx+1);
    seq.push_back(v[idx]);
    ans.push_back(seq);
    subsequence(v,ans,seq,idx+1);
}

vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    // unordered_set<vector<int>>s;
    // vector<int>seq;
    // subsequence(v,s,seq,0);

    vector<vector<int>>ans;
    vector<int>seq;
    subsequence(v,ans,seq,0);
    // unordered_set<vector<int>>::iterator it;
    // for(it = s.begin() ; it!=s.end() ;it++){
    //   ans.push_back(*it);
    // }

    // works for 3 size only.
   /* int n = v.size();
    for(int i=0;i<n;i++){
        vector<int>seq;
        seq.push_back(v[i]);
        ans.push_back(seq);
        for(int k=i+1;k<n;k++){
            vector<int>seq2 = seq;
          for (int j = k; j < n; j++) {
            seq2.push_back(v[j]);
            ans.push_back(seq2);
          }
        }
    }
*/
    return ans;
}

/*
    Time Complexity: O(N*(2^N))
    Space Complexity: O(N*(2^N))

    Where N is the number of elements in array
*/
// Brute Force
vector<vector<int>> pwset(vector<int> &arr) 
{
    int n = arr.size();

    // Create an array to store all subsets
    vector <vector <int>> ans = {{}};

    // Traverse through the array ARR
    for (int i = 0; i < n; i++) 
    {
        int element = arr[i];
        int len = ans.size();

        // Traverse through the array ans from 0 to len index
        for (int j = 0; j < len; j++) 
        {
            vector<int> temp = ans[j];

            // Include element in the subset temp
            temp.push_back(element);
            ans.push_back(temp);
        }
    }

    // Return the array ans
    return ans;
}


/*
    Time Complexity: O(N*(2^N))
    Space Complexity: O(N*(2^N))

    Where N is the number of elements in array
*/
// Bit Mask
vector<vector<int>> pwset(vector<int> arr) 
{
    int n = arr.size();

    // Create an array to store all subsets
    vector<vector<int>> ans;

    for (int i = 0; i <= pow(2, n); i++)
    {
        vector<int> temp;

        // Traverse through the array ARR
        for (int j = 0; j < n; j++) 
        {
            // Check if j-th bit is set
            if (i & (1 << j)) 
            {
                temp.push_back(arr[j]);
            }
        }

        // Insert the subset temp in ans
        ans.push_back(temp);
    }

    // Return the array ans
    return ans;
}

