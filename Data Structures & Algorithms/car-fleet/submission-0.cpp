class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>>cars;

        for(int i = 0; i < n; i++){
            double time = (double)(target - position[i])/speed[i];
            cars.push_back({position[i],time});
        }

        sort(begin(cars),end(cars),greater<>());
        
        double last_time = 0;
        int carsfleet = 0;
        for(auto &car : cars){
            if(car.second > last_time){
                carsfleet++;
                last_time = car.second;
            }
        }
        return carsfleet;
    }
};
