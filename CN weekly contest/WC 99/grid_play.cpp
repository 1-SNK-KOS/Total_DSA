// This question not able to solve 
// This solution show TLE
// T.C O(2^N)

void path(int s1,int s2 ,int e1,int e2,vector<vector<int>> &v,int Alice ,int Bob ,int &happyA ,int &happyB){
if(happyA && happyB) return ;
Alice+=v[s1][s2];
Bob+=v[s1][s2];
if(s1 == e1 && s2 == e2 ){
    if(Alice%2 == 0) happyA =1;
    if(Bob%2 == 1) happyB =1;
}

// right
if(s2 < e2){
path(s1,s2+1,e1,e2,v,Alice,Bob,happyA,happyB);}
// down
if(s1 < e1){
path(s1+1,s2,e1,e2,v,Alice,Bob,happyA,happyB);}

return ;
}

vector<int> canBeHappy(int n, int m, int q, vector<vector<int>> &v, vector<vector<int>> &queries) {

vector<int>ans;
for(int i=0;i<queries.size();i++){
    int happyA=0,happyB=0;
    path(queries[i][0],queries[i][1],queries[i][2],queries[i][3],v,0,0,happyA,happyB);

    if(happyA && happyB){
        ans.push_back(1);
    }
    else{
        ans.push_back(0);
    }
}
  
  return ans;
}