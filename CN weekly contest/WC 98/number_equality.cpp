// My code
int canSheMakeEqual(int x, int y) {
    // Write your code here.
    if(x == y) return 1;
    if(x+1 == y-2 || y+1 == x-2) return 1;

    while(x<y){
        x+=1;
        y-=2;

        if(x == y){
            return 1;
        }
        else if(x>y){
            return 0;
        }
    }
    while(x>y){
        y+=1;
        x-=2;

        if(x == y){
            return 1;
        }
        else if(y>x){
            return 0;
        }   
    }
}

// Optimal solution
/*
    Time Complexity: O(1)
    Space Complexity: O(1)
*/

int canSheMakeEqual(int x, int y) {

    // Initialize an integer 'difference' equal to the absolute difference between 'x' and 'y'.
    int difference = abs(x - y);

    // Check if 'difference' is divisible by '3'.
    if (difference % 3 == 0) {

        // 'difference' is divisible by '3'.
        return 1;
    }
    else {

        // 'difference' is not divisible by '3'.
        return 0;
    }
}
