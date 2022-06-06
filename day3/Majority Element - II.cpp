//https://www.codingninjas.com/codestudio/problems/majority-element-ii_893027?topList=striver-sde-sheet-problems&leftPanelTab=0

#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &nums)
{
    int num1=-1,num2=-2,c1=0,c2=0; //max of 2 ele only can come n/3 times
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==num1) c1++;
            else if(nums[i]==num2) c2++;
            
            else if(c1==0) {num1=nums[i];c1=1;}
            else if(c2==0) {num2=nums[i];c2=1;}
            else{
                
                c1--;c2--;
            }
        }
       int cnt1=count(nums.begin(),nums.end(),num1);
        int cnt2=count(nums.begin(),nums.end(),num2);
        vector<int>v;
        if(cnt1>(n/3)) v.push_back(num1);
        if(cnt2>(n/3)) v.push_back(num2);
        // if(v.size()==0) v.push_back(-1);
        return v;

}
