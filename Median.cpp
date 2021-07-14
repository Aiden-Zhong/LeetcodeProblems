#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double median;

        vector<int> res;
        res.reserve(m+n);
        res.insert(res.end(),nums1.begin(),nums1.end());
        res.insert(res.end(),nums2.begin(),nums2.end());

        sort(res.begin(), res.end());

        int location = res.size()/2;

        if (res.size()%2 != 0) {
           median = res[location] * 1.0;
        } else {
            median = ((res[location-1] + res[location])/2.0) * 1.0;
        }
        return median;
    }
};