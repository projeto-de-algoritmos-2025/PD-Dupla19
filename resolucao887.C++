class Solution {
public:
    int superEggDrop(int k, int n) {
        if (n <= 1) return n;
        if (k == 1) return n; // precisa testar todos os andares em sequência

        // dp[j] = dp[m][j] no passo atual (m movimentos)
        vector<int> dp(k + 1, 0);

        int m = 0;
        
    }
};