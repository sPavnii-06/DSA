class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        for (auto &seat : reservedSeats) {
            int row = seat[0], col = seat[1];
            rowMask[row] |= (1 << col);
        }
        
        int result = 0;
        
        for (auto &[row, mask] : rowMask) {
            bool left = !(mask & ((1<<2)|(1<<3)|(1<<4)|(1<<5)));
            bool right = !(mask & ((1<<6)|(1<<7)|(1<<8)|(1<<9)));
            bool middle = !(mask & ((1<<4)|(1<<5)|(1<<6)|(1<<7)));
            
            if (left && right) result += 2;
            else if (left || right || middle) result += 1;
        }
        result += (n - rowMask.size()) * 2;
        
        return result;
    }
};