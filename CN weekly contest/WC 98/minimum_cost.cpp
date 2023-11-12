// My code
int atoz(char x,char y,int b){
    int curcost = (x-'a');
    curcost+=b;
    curcost+= ('z'-y);

    return curcost;
}

int ztoa(char x,char y,int a){
    int curcost = 'z'-x;
    curcost+=a;
    curcost+= (y-'a');

    return curcost;
}


int makeStringsEqual(int n, int a, int b, string& s, string& t) {
    // Write your code here.
    int cost = 0;
    for(int i=0;i<n;i++){
        if(s[i] == t[i]){
            continue;
        }
        else{
            if(s[i] < t[i]){
             int curcost = t[i] - s[i];
             curcost = min(curcost,atoz(s[i],t[i],b));
             cost+=curcost;
            }
            else{
                 int curcost = s[i] - t[i];
             curcost = min(curcost,ztoa(s[i],t[i],a));
             cost+=curcost;
            }
        }
    }

    return cost;
}

// better written code
/*
    Time complexity: O( N )
    Space complexity: O( 1 )
    
    where 'N' is the length of the string 'S'.
*/

int makeStringsEqual(int n, int a, int b, string& s, string& t) {
    
    // Declare integer variable 'ans'.
    int ans = 0;
    
    for (int i = 0; i < n; ++i) {
        
        // Getting characters at 'i'th index of string 's' and 't'.
        char ch1 = s[i], ch2 = t[i];
        
        // If both characters are same, continue.
        if (ch1 == ch2) {
            continue;
        }
        else {
            
            int forward = 0, backward = 0;
            
            // Calculating 'forward' variable.
            if (ch1 <= ch2) {
                forward = ch2 - ch1;
            }
            else {
                forward = ('z' - ch1) + a + (ch2 - 'a');
            }
            
            // Calculating 'backward' variable.
            if(ch2 <= ch1) {
                backward = ch1 - ch2;
            }
            else {
                backward = (ch1 - 'a') + b + ('z' - ch2);
            }
            
            ans += min(forward, backward);
        }
    }
    return ans;
}