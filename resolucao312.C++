class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // adiciona 1 nas extremidades
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp[l][r] = máximo de moedas no intervalo aberto (l, r)
        vector<vector<int>> dp(n, vector<int>(n, 0));

    }
};
