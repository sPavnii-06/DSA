class Solution {
public:
    multiset<int> left, right;

    void balance() {
        while (left.size() > right.size() + 1) {
            right.insert(*left.rbegin());
            auto it = left.end();
            --it;
            left.erase(it);
        }

        while (left.size() < right.size()) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }

    void add(int num) {
        if (left.empty() || num <= *left.rbegin())
            left.insert(num);
        else
            right.insert(num);

        balance();
    }

    void remove(int num) {
        auto it = left.find(num);

        if (it != left.end())
            left.erase(it);
        else {
            it = right.find(num);
            right.erase(it);
        }

        balance();
    }

    double getMedian(int k) {
        if (k % 2)
            return *left.rbegin();

        return ((double)*left.rbegin() + *right.begin()) / 2.0;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;

        for (int i = 0; i < k; i++)
            add(nums[i]);

        ans.push_back(getMedian(k));

        for (int i = k; i < nums.size(); i++) {
            remove(nums[i - k]);
            add(nums[i]);

            ans.push_back(getMedian(k));
        }

        return ans;
    }
};