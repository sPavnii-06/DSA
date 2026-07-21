
class Solution {
public:
    int maxActiveSectionsAfterTrade(std::string s) {
        int original_ones = 0;
        for (char c : s) {
            if (c == '1') original_ones++;
        }
        
        
        std::string t = "1" + s + "1";
        std::vector<int> zero_block_lengths;
        int current_zeros = 0;
        
        for (char c : t) {
            if (c == '0') {
                current_zeros++;
            } else {
                if (current_zeros > 0) {
                    zero_block_lengths.push_back(current_zeros);
                    current_zeros = 0;
                }
            }
        }
        if (current_zeros > 0) {
            zero_block_lengths.push_back(current_zeros);
        }
        
        
        int max_gain = 0;
        if (zero_block_lengths.size() >= 2) {
            for (size_t i = 0; i < zero_block_lengths.size() - 1; ++i) {
                max_gain = std::max(max_gain, zero_block_lengths[i] + zero_block_lengths[i + 1]);
            }
        }
        
        return original_ones + max_gain;
    }
};
