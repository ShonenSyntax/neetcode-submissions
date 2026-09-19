#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map <int,int> unique;
        vector <int> result;

        for(int i=0; i<nums.size(); i++)
            unique[nums[i]]++;
    
        for(int i=0; i<k; i++){
            int highest_key = -1;
            int highest_freq = INT_MIN;
            for(auto& [num,freq] : unique){
                if(freq>highest_freq){
                    highest_freq = freq;
                    highest_key = num;
                }
            }
            result.push_back(highest_key);
            unique.erase(highest_key);
        }
        return result;
    }
};
