class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int mini = INT_MAX;
       int maxPro = 0;
       for(int num : prices){
        if(num <= mini){
            mini = num;
        }
        maxPro = max(maxPro,num-mini);
       } 
       return maxPro;
    }
};
