#include <string>
using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        if(strs.empty())
            return "\036";
        for(int i=0;i<strs.size();i++){
            if(i>0)
                encoded_string += "\037" + strs[i];
            else
                encoded_string += strs[i];
        }
        return encoded_string;
    }

    vector<string> decode(string encoded_string) {
        vector<string> decoded_string = {};
        if(encoded_string == "\036")
            return {};
        int j = 0;
        for(int i=j;i<encoded_string.size();i++){
            if(encoded_string[i]=='\037'){
                decoded_string.push_back(encoded_string.substr(j,i-j));
                j = i+1;
            }
        }
        decoded_string.push_back(encoded_string.substr(j));
        return decoded_string;
    }
};

