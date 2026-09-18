#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector <string>> my_map;

        for(int i=0; i<strs.size(); i++){
            string word = strs[i];
            string sorted = word;
            sort(sorted.begin(),sorted.end());

            my_map[sorted].push_back(word);
        }

        vector <vector <string>> result;

        for(auto& [sorted,word]: my_map)
            result.push_back(word);

        return result;
    }
};
