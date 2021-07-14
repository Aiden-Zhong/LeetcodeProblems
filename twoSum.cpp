#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        map <int, int> hashmap;
        vector<int> output;
        for (int i = 0; i < nums.size(); i++) {
            int secondele = target - nums[i];
            if (hashmap.find(secondele)!=hashmap.end()&&hashmap.find(secondele)->second!=i) {
                output.push_back(i);
                output.push_back(hashmap.find(secondele)->second);
                return output;
            }
            hashmap.insert(pair<int,int>(nums[i],i));
        }
        return output;
    }
};

 void print(std::vector <int> const &a) {
        std::cout << "The vector elements are : ";

         for(int i=0; i < a.size(); i++)
         std::cout << a[i] << ' ';
    }

int main() {
    Solution s;
    vector<int> v = {2, 7, 11, 15};
    print(s.twoSum(v, 9));

}