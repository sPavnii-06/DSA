class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        for(char ch:word1) map1[ch]++;
        for(char ch: word2) map2[ch]++;
        for(auto &pair: map1){
            if(map2.find(pair.first)==map2.end()) return false;
        }
        for(auto &pair :map2){
            if(map1.find(pair.first)==map1.end()) return false;
        }
        vector<int>arr1,arr2;
        for(auto &pair: map1) arr1.push_back(pair.second);
        for(auto &pair: map2) arr2.push_back(pair.second);
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(), arr2.end());
        return arr1==arr2;

        
    }
};