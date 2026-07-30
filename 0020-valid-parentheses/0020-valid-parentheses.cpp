class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char ch : s) {

            // Opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {

                // Stack empty
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                // Check matching brackets
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                    return false;
            }
        }

        return st.empty();
    }
};