
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') continue;

                char ch = board[i][j];

                string row = "row" + to_string(i) + ch;
                string col = "col" + to_string(j) + ch;
                string box = "box" + to_string(i / 3) + to_string(j / 3) + ch;

                if (st.count(row) || st.count(col) || st.count(box))
                    return false;

                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }

        return true;
    }
};
