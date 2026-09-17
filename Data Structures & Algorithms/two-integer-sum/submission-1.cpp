#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> occur;

        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            int compliment = target - x;
            if(occur.find(compliment) !=occur.end())
                return {occur[compliment],i};
            else
                occur[nums[i]] = i;
        }
            return {};
    }
};
