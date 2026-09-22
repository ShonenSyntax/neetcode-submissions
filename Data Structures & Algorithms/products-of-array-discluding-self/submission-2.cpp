//Practice_Session

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int counter = 0;
        int product = 1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                counter++;
            else
                product *= nums[i];
        }

        vector<int> output;

        for(int i=0;i<nums.size();i++){    
            if(counter > 1)
                output.push_back(0);
            else if(counter == 1){
                if(nums[i]==0)
                    output.push_back(product);
                else
                    output.push_back(0);
            }
            else
                output.push_back(product/nums[i]);
        }
        return output;
    }
};
