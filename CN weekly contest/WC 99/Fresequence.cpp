string findFreqsequence(string s) {
    // Write your code here.
    unordered_map<char,int>mp;

    int maxfreq= 0;
    for(int i=0;i<s.size();i++){
       mp[s[i]]++;
    // simplified version line
       maxfreq = max(maxfreq,mp[s[i]]);
    }
    
    /*string str="";
       int maxfreq = 0;
    for(auto x : mp){
      if(maxfreq<x.second){
          maxfreq = x.second;
          str = x.first;
      }
      else if(maxfreq == x.second){
          str+=x.first;
      }
    }


    string ans=""; 
    // string size = 1
    if(str.size() == 1){
        while(maxfreq>0){
            ans+=str;
            maxfreq--;
        }

        return ans;
    }
   
    // String size>1
    for(auto x:s){
        for(auto y:str){
            if (x == y) {
              ans += x;
              break;
            }
        }
      }       
    */

    // simplified
  /*  string ans="";

    for(auto x:s){
        if(mp[x] == maxfreq){
            ans+=x;
        }
    }
*/
  
    // return ans;
}

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    Where 'N' denotes length of the string 'S'.
*/


string findFreqsequence(string s) {

    // Make an integer array 'freq' of size '26', and initialize it with '0'.
    vector<int> freq(26, 0);
    
    // Initialize an integer variable 'N' with the 'length of the string'.
    int n = s.length();

    // Initialize an integer variable 'maxFreq' by '0'.
    int maxFreq = 0;

    for (int i = 0; i < n; i++) {

        // Increase the 'freq[S[i] - 'a']' by one.
        freq[s[i] - 'a']++;

        // Set 'maxFreq' to 'max(maxFreq, freq[S[i] - 'a'])'.
        maxFreq = max(maxFreq, freq[s[i] - 'a']);
    }

    // Initialize a string 'answer' with an empty string.
    string answer = "";

    for (int i = 0; i < n; i++) {

        // If 'freq[S[i] - 'a']' is equal to 'maxFreq', then add 'S[i]' at the back of the 'answer'.
        if (freq[s[i] - 'a'] == maxFreq) {
            answer.push_back(s[i]);
        }
    }

    return answer;
}

