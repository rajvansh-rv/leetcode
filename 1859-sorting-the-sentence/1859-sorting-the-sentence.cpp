class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string word;

        vector<string> ans(9);

        while (ss >> word) {
            int pos = word.back() - '0';
            word.pop_back();

            ans[pos - 1] = word;
        }

        string result = "";

        for (int i = 0; i < 9; i++) {
            if (ans[i].empty()) continue;

            if (!result.empty()) {
                result += " ";
            }

            result += ans[i];
        }

        return result;
    }
};