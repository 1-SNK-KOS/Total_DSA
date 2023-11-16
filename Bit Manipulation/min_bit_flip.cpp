class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;

        while(start>0 || goal>0){
            // cout<<(start & 1)<<" "<<(goal & 1)<<endl;
            if((start&1) != (goal&1)) count++;
            // cout<<count<<endl;
            start = start>>1;
            goal = goal>>1;
        } 

        return count;
    }
};

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr = start^goal;

        int ans = 0;

        while(xorr)
        {
            xorr = xorr&(xorr-1);
            ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int M = max(start, goal);
        int m = min(start, goal);

        int cnt = 0;
        for(int i=1 ; i<=M ; i=i<<1){
            bool b1, b2;
            b1 = i&M;
            b2 = i&m;

            if(b1 != b2){
                cnt++;
            }
        }

        return cnt;
    }
};