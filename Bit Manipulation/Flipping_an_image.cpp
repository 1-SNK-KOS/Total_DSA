class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int rows = image.size();
        int col = image[0].size();

        for(int i=0;i<rows;i++){
            for(int j=0;j<col/2;j++){
                swap(image[i][j],image[i][col-1-j]);
                image[i][j]^=1;
                image[i][col-1-j]^=1;
            }
            if(col&1)image[i][col/2]^=1;
        }
        
        return image;
    }
};

class Solution {
public:
        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n=image.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<(n+1)/2;j++)
            {
                int temp=image[i][j]^1;
                image[i][j]=image[i][n-1-j]^1;
                image[i][n-1-j]=temp;
            }
        }
        return image;
    }
};