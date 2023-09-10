class Solution {
public:
const int MOD = 1000000007;

int countOrders(int n) {
    long long dp[n + 1];
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * (2 * i - 1) % MOD;
        dp[i] = (dp[i] * i) % MOD;
    }
    
    long long result = dp[n];
    
    return result;
}

};