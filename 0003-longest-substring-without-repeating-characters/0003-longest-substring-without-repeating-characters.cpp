class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> lastSeen;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            char ch = s[right];

            // If character was already seen inside current window
            if (lastSeen.find(ch) != lastSeen.end() &&
                lastSeen[ch] >= left) {
                
                left = lastSeen[ch] + 1;
            }

            lastSeen[ch] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};