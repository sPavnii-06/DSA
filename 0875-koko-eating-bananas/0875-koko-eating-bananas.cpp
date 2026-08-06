class Solution {
public:
    bool canEat(vector<int>& piles, int speed, int h) {
        long long hours = 0;
        for (int bananas : piles) {
            hours += (bananas + speed - 1) / speed; 
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canEat(piles, mid, h)) {
                ans = mid;
                high = mid - 1; // try smaller speed
            } else {
                low = mid + 1;  // need larger speed
            }
        }
        return ans;
    }
};