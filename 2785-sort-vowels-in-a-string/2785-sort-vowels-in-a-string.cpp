class Solution {
public:
    string sortVowels(string s) {
        int freq[128] = {};

        for (char c : s) {
            if (isVowel(c)) freq[c]++;
        }

        int j = 0;
        const string vowels = "AEIOUaeiou";

        for (char &c : s) {
            if (isVowel(c)) {
                while (freq[vowels[j]] == 0) j++;
                c = vowels[j];
                freq[vowels[j]]--;
            }
        }

        return s;
    }

private:
    bool isVowel(char c) {
        return c == 'a'|| c == 'e' || c == 'i' ||
               c == 'o' || c == 'u'   ||
               c ==   'A'   ||c == 'E' || c == 'I' ||
               c == 'O' || c == 'U';
    }
};