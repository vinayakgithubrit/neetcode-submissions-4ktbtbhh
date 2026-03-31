class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp; 
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }
        
        string result = "";
        auto vec = mp[key];
        int l = 0;
        int h = (int)vec.size() - 1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(vec[mid].first <= timestamp){
                result = vec[mid].second;
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return result;
    }
};
