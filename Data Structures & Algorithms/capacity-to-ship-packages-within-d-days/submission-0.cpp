class Solution {
public:  
    bool CanWeShip(vector<int>& weights, int mid, int days){
        int actualdays = 1;
        int load = 0;
        int n = weights.size();
        for(int i = 0; i < n; i++){
            if(weights[i] + load > mid){
                actualdays++;
                load = weights[i];
            }
            else{
                load +=weights[i];
            }
        }
        return actualdays <=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(begin(weights),end(weights));
        int h = accumulate(begin(weights),end(weights),0);

        while(l <= h){
            int mid = l + (h-l)/2;
            if(CanWeShip(weights,mid,days)){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};