#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> letters;

        if(s.size()!=t.size())
            return false;
        
        for(int i=0;i<s.size();i++)
            letters[s[i]]++;

        for(int i=0;i<t.size();i++)
        {
            if(letters.find(t[i])!=letters.end() && letters[t[i]]>0)
                letters[t[i]]--;
            else
                return false;
        }
        return true;
    }
};
