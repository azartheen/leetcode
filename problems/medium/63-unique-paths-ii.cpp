/*
Unique Paths II

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // similiar to 62 - Unique Paths 
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++) {
            if(obstacleGrid[i][0]!=1) dp[i][0]=1;
            // if obstacleGrid[i][0]==1, there is no way to reach row i..m 
            else break;
        }
        for(int j=0;j<n;j++) {
            if(obstacleGrid[0][j]!=1) dp[0][j]=1;
            // if obstacleGrid[0][j]==1, there is no way to reach col j..m 
            else break;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                // if it is an obstacle, dp[i][j] is 0
                // only sum for cells without obstacles
                if(!obstacleGrid[i][j]) {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};