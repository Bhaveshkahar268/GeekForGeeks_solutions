class Solution {
    private:
    inline bool inBounds(int i,int j,vector<vector<int>> &mat){ return i >=0 && i< mat.size() && j>=0 && j < mat[0].size();}
  public:
    int findPerimeter(vector<vector<int>> &mat) {
        // code here
        int perimeter = 0;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,-1,0,1};
        for(int i = 0;i <mat.size() ; i++){
            for(int j=0 ; j<mat[0].size();j++){
                if(mat[i][j] == 1){
                    int neighbors = 0;
                    for(int k=0;k<4;k++){
                        int nx = i +dx[k];
                        int ny = j + dy[k];
                        if(inBounds(nx,ny,mat) && mat[nx][ny] == 1){
                            neighbors++;
                        }
                    }
                    perimeter += 4 - neighbors;
                }
            }
        }
        return perimeter;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna