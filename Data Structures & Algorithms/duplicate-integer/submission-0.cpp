#include <unordered_map>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> my_list;
        for(int i=0;i<nums.size();i++){
            if(my_list.find(nums[i]) != my_list.end())
                return true;
            else
                my_list[nums[i]] = i;
        }
        return false;
    }
};