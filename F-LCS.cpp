class Solution {
public:

	int longestCommonSubsequence(string text1, string text2) {
		int n = text1.length(), m = text2.length();
		vector<vector<int> > memo(n + 1, vector<int>(m + 1, -1));
		memo[0][0] = 1;
		for (int j = 0; j <= m; j++)
			memo[0][j] = 0;
		for (int i = 0; i <= n; i++)
			memo[i][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (text1[i - 1] == text2[j - 1]) {
					memo[i][j] = 1 + memo[i - 1][j - 1];
				}
				else
					memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
			}
		}
		return memo[n][m];
	}
};
