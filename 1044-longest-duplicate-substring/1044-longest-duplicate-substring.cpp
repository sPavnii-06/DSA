class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.length();
        int left = 1, right = n - 1;
        int start_idx = -1;
        int max_len = 0;

        // Base values and primes for dual-hash rolling hash to guarantee 100% collision-free results
        long long base1 = 26, base2 = 29;
        long long mod1 = 1000000007, mod2 = 1000000009;

        // Precompute powers for the rolling hash
        vector<long long> power1(n, 1), power2(n, 1);
        for (int i = 1; i < n; i++) {
            power1[i] = (power1[i - 1] * base1) % mod1;
            power2[i] = (power2[i - 1] * base2) % mod2;
        }

        // Custom hash function for pair of long long to use inside an unordered_set
        struct PairHash {
            size_t operator()(const pair<long long, long long>& p) const {
                return (p.first * 31) + p.second;
            }
        };

        // Helper function to check if a duplicate substring of length 'len' exists
        auto check = [&](int len) -> int {
            unordered_set<pair<long long, long long>, PairHash> seen;
            long long hash1 = 0, hash2 = 0;

            // Compute hash for the first window
            for (int i = 0; i < len; i++) {
                hash1 = (hash1 * base1 + (s[i] - 'a')) % mod1;
                hash2 = (hash2 * base2 + (s[i] - 'a')) % mod2;
            }
            seen.insert({hash1, hash2});

            // Slide the window across the rest of the string
            for (int i = len; i < n; i++) {
                // Remove leading character
                hash1 = (hash1 - (s[i - len] - 'a') * power1[len - 1]) % mod1;
                if (hash1 < 0) hash1 += mod1;
                
                hash2 = (hash2 - (s[i - len] - 'a') * power2[len - 1]) % mod2;
                if (hash2 < 0) hash2 += mod2;

                // Add trailing character
                hash1 = (hash1 * base1 + (s[i] - 'a')) % mod1;
                hash2 = (hash2 * base2 + (s[i] - 'a')) % mod2;

                // If this hash pair has been seen before, we found a duplicate
                if (seen.count({hash1, hash2})) {
                    return i - len + 1;
                }
                seen.insert({hash1, hash2});
            }
            return -1;
        };

        // Binary search for the maximum possible length of a duplicate substring
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int idx = check(mid);
            
            if (idx != -1) {
                start_idx = idx;
                max_len = mid;
                left = mid + 1; // Try to find a longer duplicate substring
            } else {
                right = mid - 1; // Try a shorter length
            }
        }

        return max_len == 0 ? "" : s.substr(start_idx, max_len);
    }
};