class Solution {
    public:
    bool compare(string &s1,string &s2){
         if(s1.size()!=s2.size()+1) return false;
         int first=0;
         int second=0;
         while(first<s1.size()){
            if(s1[first]==s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
         }
         if(first==s1.size() && second==s2.size()) return true;
         return false;
    }
        static bool comp(string &a, string &b) {
            return a.size() < b.size();
        }
        int f(vector<string>& words){
            sort(words.begin(),words.end(),comp);
                   int n = words.size();
                vector<int> dp(n, 1);
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < i; ++j)
                        if (compare(words[i],words[j])){
                            dp[i] = max(dp[i],dp[j] + 1);
                        }
                return *max_element(dp.begin(), dp.end());
        }
        int longestStrChain(vector<string>& words) {
            return f(words);
        }
    };