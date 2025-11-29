class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // adiciona 1 nas extremidades
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        // dp[l][r] = máximo de moedas no intervalo aberto (l, r)
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // tamanho do intervalo
        for (int length = 2; length < n; length++) {
            for (int left = 0; left + length < n; left++) {
                int right = left + length;

                // escolhe o último balão a ser estourado
                for (int i = left + 1; i < right; i++) {
                    int coins = dp[left][i] + dp[i][right]
                        + nums[left] * nums[i] * nums[right];

                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }

        return dp[0][n - 1];
    }
};
