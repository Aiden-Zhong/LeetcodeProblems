#include<iostream>
#include<stack>
using namespace std;

class Soluction {
public:
    string reverseWords(string s){
        string x = "";
        stack <string> st;
        s.push_back(' ');

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                x += s[i];
            } else {
                st.push(x);
                x = "";
            }
        }

        x = "";
        while(!st.empty()) {
            x += st.top();
            st.pop();
            if (!st.empty()) {
                x += ' ';
            }
        }
        return x;
    }
};

int main() {
    string s = "Hey, how's going dude?";
    Soluction rev;
    string revered = rev.reverseWords(s);
    cout << revered;
}