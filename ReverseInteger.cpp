#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        if (x < -pow(2,31) || x > pow(2,31)) {
            return 0;
        } else if (x<10) {    
            return x;
        } else {
            int len = to_string(x).length();
            for (int i = 0; i < len; i++) {
                if (i == 0) {
                    res += x%10;
                }
                else if (i+1 != len) {
                    res = x%10+res*(pow(10,i));
                }
                
                x /= 10;
            }
        }
        return res;
    }
};
