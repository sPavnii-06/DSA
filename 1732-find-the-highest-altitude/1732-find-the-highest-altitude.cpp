class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_altitude = 0;
        int cur_altitude = 0;
        for(int g: gain){
            cur_altitude+= g;
            max_altitude = std::max(max_altitude, cur_altitude);
        }
        return max_altitude;
        
    }
};