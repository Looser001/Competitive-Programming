//https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return 0;
        }
        string prefix=strs[0], first = strs[0];
        for(int i = 1; i < strs.size(); i++){
            string temp;
            for(int j = 0; j < strs[i].size(); j++ ){
                if(first[j]==strs[i][j]){
                    temp += first[j];
                }
                else{
                    break;
                };
            }
            if(prefix.size() >= temp.size()){
                prefix = temp;
            }
        }
        return prefix;
    }
};
