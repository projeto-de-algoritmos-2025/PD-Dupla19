class Solution {
public:
    int superEggDrop(int k, int n) {
        if (n <= 1) return n;
        if (k == 1) return n; // precisa testar todos os andares em sequência

        // dp[j] = dp[m][j] no passo atual (m movimentos)
        vector<int> dp(k + 1, 0);

        int m = 0;
        while (dp[k] < n) {
            m++;
            // atualizar dp de trás pra frente para usar dp[m-1][*] ao calcular dp[m][*]
            for (int j = k; j >= 1; --j) {
                dp[j] = dp[j] + dp[j - 1] + 1;
            }
            // dp[0] permanece 0
        }
    }
};