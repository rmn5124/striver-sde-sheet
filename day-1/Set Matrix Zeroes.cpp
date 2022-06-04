//https://leetcode.com/problems/set-matrix-zeroes/
//https://www.codingninjas.com/codestudio/problems/set-matrix-zeros_3846774?topList=striver-sde-sheet-problems&leftPanelTab=0

APPROACH-1 (BRUTE-FORCE)

// we will check for each instance of zero 
// It will only work if no digit is -1, and will give TLE on large size of the matrix.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<n;k++){
                        if(matrix[k][j]!=0){
                            matrix[k][j]=-1;
                        }
                    }
        
                    for(int k=0;k<m;k++){
                        if(matrix[i][k]!=0){ // so that it won't effect the remaining matrix
                            matrix[i][k]=-1;
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
// T.C -> O((m*n)*(m+n))
// S.C -> O(1)
// where m and n are column and row of the matrix respectively

APPROACH-2 (BETTER)
  class Solution {
public:
    // Here we will take two dummy arrays to store the row and column of the matrix which is zero, and we will traverse again in the matrix and check if either row or column is zero, then make that index zero.
    
    void setZeroes(vector<vector<int>>& matrix) {
       int n=matrix.size(),m=matrix[0].size();
        vector<int>row(n),col(m);
       
        for(int i=0;i<n;i++){
           for( int j=0;j<m;j++){
               if(matrix[i][j]==0){
                   row[i]=-1;
                   col[j]=-1;
               }
           }
        }
        
        for(int i=0;i<n;i++){
           for( int j=0;j<m;j++){
               if(row[i]==-1 or col[j]==-1){
                   matrix[i][j]=0;
               }
        }
    }
    }
};
// T.C (O(m*n + (m*n)))
// S.C O(m+n)
// where m and n are column and row of the matrix respectively

APPROACH-3 (OPTIMAL)
  /*My idea is simple: store states of each row in the first of that row, and store states of each column in the first of that column. Because the state of row0 and the state of column0 would occupy the same cell, I let it be the state of row0, and use another variable "col0" for column0. 
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool isZeroRow=0;
        bool isZeroCol=0;
        for(int i=0;i<m;i++){ // check 1st row
            if(matrix[0][i]==0) isZeroRow=1;
        }
        for(int i=0;i<n;i++){ // check 1st col
            if(matrix[i][0]==0) isZeroCol=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){  // check except of 1st row and column
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        // we will process 1st row and column later since it will effect all the matrix
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if( matrix[i][0]==0 or  matrix[0][j]==0 ) matrix[i][j]=0; //process except 1st
            }
        }
        if(isZeroRow){ // process 1st row
            for(int i=0;i<m;i++){
                matrix[0][i]=0;
        }
    }
        if(isZeroCol){ // process 1st col
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
        }
    }
    }
};
// T.C O(m*n )
// S.C O(1)
  
