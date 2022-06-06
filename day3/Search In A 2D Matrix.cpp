//https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_980531?topList=striver-sde-sheet-problems

#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & matrix, int n, int m, int target) {
    // Write your code here.
     
        int left=0,right=m-1;
        
        while(left<n and right>=0){
          if(matrix[left][right]==target) return 1;
          else if(matrix[left][right]>target) right--;
          else left++;
        }
        return false;
}
