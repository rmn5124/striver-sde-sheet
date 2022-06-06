//https://www.codingninjas.com/codestudio/problems/majority-element_842495?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h> 
int findMajorityElement(int a[], int n) {
	// Write your code here.
    unordered_map<int, int> m;
      for(int i = 0 ;i<n;i++){
          m[a[i]]++;
      }
      for(auto x:m){
          if(x.second>n/2)
              return x.first;
      }
      return -1;
    
}
