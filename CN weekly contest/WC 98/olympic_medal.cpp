

/*
void helper(vector<int>&gold,vector<int>v,int index,int &sum,int cursum ,vector<vector<int>>&com){

  if(cursum == sum){
      com.push_back(v);
  }
  if(index == gold.size()) return ;
  cursum+=gold[index];
  v.push_back(index);
  helper(gold,v,index+1,sum,cursum,com);
  v.pop_back();
  cursum-=gold[index];
  helper(gold,v,index+1,sum,cursum,com);
  
  return ;
}
*/
void helper(int &n, int &g, int &s, int &b,int index, vector<vector<int>> &prizes , int gs ,int ss ,int bs ,int &c){
   if(c == 1) return;
   if(gs == g && bs == b && ss == s) { c = 1; return ;}
   if(index == n) return ;

    helper(n,g,s,b,index+1,prizes,gs,ss,bs,c);
    helper(n,g,s,b,index+1,prizes,gs+prizes[index][0],ss+prizes[index][1],bs+prizes[index][2],c);

  //  return abs(first-second);
}

int possibleOrNot(int n, int g, int s, int b, vector<vector<int>> prizes) {
    // Write your code here.
    
    // int ans = 0;
    //
   /* vector<int>gold;
    for(auto x:prizes){
        gold.push_back(x[0]);
    }
    vector<vector<int>>com;
    vector<int>v;
    helper(gold,v,0,g,0,com);
   
    for(int i=0;i<com.size();i++){
        int silver = 0, bronze = 0;
      for(int j=0;j<com[i].size();j++){
           silver +=prizes[(com[i][j])][1];
           bronze +=prizes[(com[i][j])][2];

           if(bronze > b || silver > s)break;
      }
      if(silver == s && bronze == b) return 1;
    }
*/

   int c =0;
   helper(n,g,s,b,0,prizes,0,0,0,c);
   return c;
}




/*
    Time Complexity: O(2^N)
    Space Complexity: O(2^N)

    Where 'N' denotes the number of games in the Olympics.
*/

int checkEveryPossibility(int idx, int g, int s, int b, vector<vector<int>> &prizes) {

    // If any of the 'G', 'S', or 'B' is zero, then return '0'.
    if (g < 0 || s < 0 || b < 0) {
        return 0;
    }

    // If 'idx' is equal to 'size of prizes'. 
    if (idx == prizes.size()) {

        // If 'G', 'S', and 'B' all them are zero, then return 'q'.
        if(g == 0 && s == 0 && b == 0) {
            return 1;
        }

        // Otherwise, return '0'.
        return 0;
    }

    // Store answer of 'checkEveryPossibility(idx + 1, G, S, B, prizes)' to the integer variable 'notChoose'.
    int notChoose = checkEveryPossibility(idx + 1, g, s, b, prizes);

    // Store answer of 'checkEveryPossibility(idx + 1, G - prizes[idx][0], S - prizes[idx][1], B - prizes[idx][2], prizes)' to the integer variable 'choose'.
    int choose = checkEveryPossibility(idx + 1, g - prizes[idx][0], s - prizes[idx][1], b - prizes[idx][2], prizes);

    // Return the maximum value of 'choose' and 'NotChoose'.
    return max(notChoose, choose);
}

int possibleOrNot(int n, int g, int s, int b, vector<vector<int>> prizes) {
    
    // Store the returned value of 'checkEveryPossibility(0, G, S, B, prizes)' in the intgere variable 'answer'.
    int answer = checkEveryPossibility(0, g, s, b, prizes);

    return answer;
}


// Written Better
/*
    Time Complexity: O(2^N)
    Space Complexity: O(2^N)

    Where 'N' denotes the number of games in the Olympics.
*/

int checkEveryPossibility(int idx, int g, int s, int b, vector<vector<int>> &prizes) {

    // If any of the 'G', 'S', or 'B' is zero, then return '0'.
    if (g < 0 || s < 0 || b < 0) {
        return 0;
    }

    // If 'idx' is equal to 'size of prizes'. 
    if (idx == prizes.size()) {

        // If 'G', 'S', and 'B' all them are zero, then return 'q'.
        if(g == 0 && s == 0 && b == 0) {
            return 1;
        }

        // Otherwise, return '0'.
        return 0;
    }

    // Store answer of 'checkEveryPossibility(idx + 1, G, S, B, prizes)' to the integer variable 'notChoose'.
    int notChoose = checkEveryPossibility(idx + 1, g, s, b, prizes);

    // Store answer of 'checkEveryPossibility(idx + 1, G - prizes[idx][0], S - prizes[idx][1], B - prizes[idx][2], prizes)' to the integer variable 'choose'.
    int choose = checkEveryPossibility(idx + 1, g - prizes[idx][0], s - prizes[idx][1], b - prizes[idx][2], prizes);

    // Return the maximum value of 'choose' and 'NotChoose'.
    return max(notChoose, choose);
}

int possibleOrNot(int n, int g, int s, int b, vector<vector<int>> prizes) {
    
    // Store the returned value of 'checkEveryPossibility(0, G, S, B, prizes)' in the intgere variable 'answer'.
    int answer = checkEveryPossibility(0, g, s, b, prizes);

    return answer;
}