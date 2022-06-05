//https://www.codingninjas.com/codestudio/problems/stocks-are-profitable_893405?topList=striver-sde-sheet-problems
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/* We will buy at minimum price and sell at maximum price, since there is only one transcation hence we will buy at minimum price and for getting maximum profit we will choose the day at which it will be sold at high price hence max(pro,i-buy);
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX;
        int pro=0;
        for(auto i:prices){
            buy=min(buy,i);  //buy at minimum
            pro=max(pro,i-buy); // make maximum profit 
        }
        return pro;
    }
};
