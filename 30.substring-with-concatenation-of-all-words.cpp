/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> res;
        if(s.length() == 0 || words.size() == 0) return res;
        
        unordered_map<string, int> dict;
        int count = 0, len = words[0].length();
        for(string word : words){
            dict[word]++;
            count++;
        }
        unordered_map<string, int> dict_copy = dict;
        int count_copy = count;
        
        for(int t = 0; t < len; t++){
            dict = dict_copy; // reset dict
            count = count_copy; // rest count
            int i = t, j = t;
            while(j < s.length()){
                if(j + len - 1 >= s.length()) break;
                string w1 = s.substr(j, len);
                if(dict.find(w1) != dict.end()){
                    if(dict[w1] > 0) count--;
                    dict[w1]--;
                }
                if(j - i + len == count_copy * len){
                    if(count == 0) res.push_back(i);
                    string w2 = s.substr(i, len);
                    if(dict.find(w2) != dict.end()){
                        if(dict[w2] >= 0) count++;
                        dict[w2]++;
                    }
                    i += len;
                }
                j += len;
            }  
        }
        return res;
	}
};

