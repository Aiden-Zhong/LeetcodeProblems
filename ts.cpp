#include <unordered_map>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Step 1 reverse the whole string
//Step 2 reverse words
//Step 3 remove extra speaces


class Solution {
public:
    void reverseWords(string& s) {
        int slength = s.length();
        reverse(s, 0, slength-1);
        reverseWords(s, slength);
        cleanSpaces(s, slength);
    }

    void reverse(string& s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }

    void reverseWords(string& s, int length) {
        int i = 0, j = 0;
        while (i < length) {
            while (i < j) { i++; }
            while (i < length && s[i] == ' ') { i++; }

            while (j < i) { j++; }
            while (j < length && s[j] != ' ') { j++; }
            reverse(s, i, j - 1);
        }
    }

    void cleanSpaces(string& s, int length) {
        int i = 0, j = 0;
        while (j < length) {
            while (j < length && s[j] == ' ') { j++; }
            while (j < length && s[j] != ' ') { s[i++] = s[j++]; }
            while (j < length && s[j] == ' ') { j++; }
            if (j < length) { s[i++] = ' '; }
        }
        s = s.substr(0, i);
    }

};

int main()
{
    Solution s;
    string str = "the sky is blue";
    s.reverseWords(str);
    cout << str;
}