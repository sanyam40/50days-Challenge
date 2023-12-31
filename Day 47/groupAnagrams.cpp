/*

Link : https://leetcode.com/problems/group-anagrams/description/

Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

*/

class Solution {
public:

    std::array<int,256>hash(string s){
        std::array<int,256>hash={0};
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }
        return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Using Hash
        map<std::array<int,256>, vector<string> >mp;

        for(auto str:strs){
            mp[hash(str)].push_back(str);
        }

        vector<vector<string>>ans;

        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans; 

        /* // Using Sort and Map 
        map<string, vector<string> >mp;

        for(auto str:strs){
            string s=str;
            sort(s.begin(),s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>>ans;

        for(auto it=mp.begin();it!=mp.end();it++){
            ans.push_back(it->second);
        }
        return ans; */
    }
};