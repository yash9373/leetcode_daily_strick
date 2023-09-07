class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_to_int;
        roman_to_int['I'] = 1;
        roman_to_int['V'] = 5;
        roman_to_int['X'] = 10;
        roman_to_int['L'] = 50;
        roman_to_int['C'] = 100;
        roman_to_int['D'] = 500;
        roman_to_int['M'] = 1000;

        int result = roman_to_int[s.back()];

        for (int i = s.length() - 2; i >= 0; i--) {
            if (roman_to_int[s[i]] < roman_to_int[s[i + 1]]) {
                result -= roman_to_int[s[i]];
            } else {
                result += roman_to_int[s[i]];
            }
        }

        return result;
    }
};

