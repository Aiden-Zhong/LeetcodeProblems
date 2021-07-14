#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    void reverseWords(string& a) {

        int n = a.length();

        // step 1. reverse the whole string
        reverse(a, 0, n - 1);

        // step 2. reverse each word
        reverseWords(a, n);

        // step 3. clean up spaces
        cleanSpaces(a, n);

    }

    //Step 1
    void reverse(string& a, int i, int j)
    {
        while (i < j)  swap(a[i++], a[j--]);    
    }

    //Step 2
    void reverseWords(string& a, int n)
    {
        int i = 0, j = 0;

        while (i < n)
        {
            while (i < j) i++; //make i and j equal (j might be ahead as it might have seen a word before)
            while (i < n && a[i] == ' ') i++; // skip spaces

            while (j < i) j++; //make j and i equal (i might be ahead as it found few spaces)
            while (j < n && a[j] != ' ') j++; // skip non spaces

            reverse(a, i, j - 1);                      // reverse the word
        }
    }

    //Step 3
    void cleanSpaces(string& a, int n)
    {
        int i = 0, j = 0;

        while (j < n)
        {
            while (j < n && a[j] == ' ') j++;             // skip spaces
            while (j < n && a[j] != ' ') a[i++] = a[j++]; // keep non spaces
            while (j < n && a[j] == ' ') j++;             // skip spaces
            if (j < n) a[i++] = ' ';                      // keep only one space
        }

        a = a.substr(0, i);
    }

};

int main()
{
    Solution s;
    string str = "the sky is blue";
    s.reverseWords(str);
    cout << str;
}