vector<int> bitManipulation(int num, int i){
    // Write your code here.
    vector<int>ans(3);

    int x =  num & (1<<(i-1));
    x = (x>>i-1);
    ans[0] = x;
     x = num | (1<<(i-1));
    ans[1] = x;
    x = num & ~(1<<i-1);
    // x = num;
    ans[2] = x;

    return ans;
}

/*  
    Time Complexity : O(1)
    Space Complexity : O(1)
*/
vector<int> bitManipulation(int num, int i){
    // Create a vector to store the results of the bit manipulation.
    vector<int> ans;
    
    // Initialize variables to store the results of the get, set, and clear operations.
    int get = 0, set = 0, clear = 0;
    
    // Create a mask with a 1 in the 'i'th position and 0s in all other positions.
    int mask = (1 << (i-1));
        
    // Check if the 'i'th bit in 'num' is set (i.e., equals 1) by using the bitwise AND operator with the mask.
    if(num & mask) {
        get = 1; 
    }
    
    // Set the 'i'th bit in 'num' by using the bitwise OR operator with the mask.
    set = (num | mask);
    
    // Clear the 'i'th bit in 'num' by using the bitwise AND operator with the complement of the mask.
    clear = (num & (~mask)); 
    
    // Push the results of the 'get', 'set', and 'clear' operations to the vector.
    ans.push_back(get);
    ans.push_back(set);
    ans.push_back(clear);
    
    // Return the vector containing the results.
    return ans;
}
