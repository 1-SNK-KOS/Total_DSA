bool isPowerOfTwo(int n)
{	
    // Write your code here.
    /*int quotient = n;
    while(quotient%2 == 0){
      quotient/=2;
      if(quotient == 1)return true;
    }
    return false;
*/

return !(n & (n-1));

}

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if(n<=0) return false;

        // return (n & n-1) == 0;
if(n==0)return false;
// if(n==1) return true;
 int quotient = n;
    while(quotient%2 == 0){
      quotient/=2;
    }
    if(quotient == 1)return true;
    return false;

    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0)return false;
        
        int bits=__builtin_popcount(n);
        
        if(bits==1)
            return true;
        return false;
    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return ceil(log2(n)) == floor(log2(n));
    }
};