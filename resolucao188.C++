class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // Caso especial: k grande equivale a transações infinitas
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            }
        }

        // dp[j][0] = max lucro com j transações e sem ação
        // dp[j][1] = max lucro com j transações e com ação
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));

        // Inicialização
        for (int j = 0; j <= k; j++) {
            dp[j][0] = 0;
            dp[j][1] = -prices[0];
        }

        // Preenchimento da PD
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);     // vender
                dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]); // comprar
            }
        }
    }
};