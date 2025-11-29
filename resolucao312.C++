class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // adiciona 1 nas extremidades
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // dp[l][r] = máximo de moedas no intervalo aberto (l, r)
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // tamanho do intervalo
        for (int length = 2; length < n; length++) {
            for (int left = 0; left + length < n; left++) {
                int right = left + length;
            }
        }

    }
};
