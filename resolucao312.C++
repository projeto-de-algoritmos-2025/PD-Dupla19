class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // adiciona 1 nas extremidades
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

    }
};
