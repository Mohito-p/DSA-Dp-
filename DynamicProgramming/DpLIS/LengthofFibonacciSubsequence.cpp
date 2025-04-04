class Solution {
    public:
        int f2(vector<int>& nums) {
            int n = nums.size();
            unordered_map<int, int> index;
            vector<vector<int>> dp(n, vector<int>(n, 2)); // Minimum length of Fibonacci-like sequence is 2
            int maxLength = 0;
    
            // Store indices of elements in nums
            for (int i = 0; i < n; i++) {
                index[nums[i]] = i;
            }
    
            // Check all pairs
            for (int j = 1; j < n; j++) {
                for (int i = 0; i < j; i++) {
                    int prevNum = nums[j] - nums[i];
                    if (prevNum < nums[i] && index.find(prevNum) != index.end()) {
                        int k = index[prevNum]; // Find index of prevNum
                        dp[i][j] = dp[k][i] + 1;
                        maxLength = max(maxLength, dp[i][j]);
                    }
                }
            }
            return maxLength >= 3 ? maxLength : 0; // If maxLength < 3, return 0 (no valid subsequence)
        }
        unordered_map<int, int> index; // Stores index of each number in nums
        vector<vector<int>> dp;
    
        int f(int i, int j, vector<int>& nums) {
            if (dp[i][j] != -1) return dp[i][j]; // Return memoized result
    
            int ans = 2; // Default length of Fibonacci sequence
            int nextNum = nums[i] + nums[j];
    
            if (index.find(nextNum) != index.end()) {
                int k = index[nextNum];
                if (k > j) { // Ensure increasing indices
                    ans = f(j, k, nums) + 1;
                }
            }
            
            return dp[i][j] = ans;
        }
    
        int lenLongestFibSubseq(vector<int>& nums) {
            int n = nums.size();
            dp = vector<vector<int>>(n, vector<int>(n, -1)); // Initialize DP table
    
            for (int i = 0; i < n; i++) {
                index[nums[i]] = i; // Store index of each number
            }
    
            int maxLength = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    maxLength = max(maxLength, f(i, j, nums)); // Call recursive function
                }
            }
    
            return maxLength >= 3 ? maxLength : 0; // If no valid sequence, return 0
        }
    };

