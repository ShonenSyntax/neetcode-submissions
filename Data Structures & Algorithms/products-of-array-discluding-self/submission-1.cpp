class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int counter = 0;
        vector <int> output;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                counter++;
            else
                product *= nums[i];
        }
        
        for(int i=0;i<nums.size();i++){
            if(counter==0)
                output.push_back(product/nums[i]);
            else if(counter==1){
                if(nums[i]==0)
                    output.push_back(product);
                else
                    output.push_back(0);
            }
            else
                output.push_back(0);
        }
        return output;
    }
};
