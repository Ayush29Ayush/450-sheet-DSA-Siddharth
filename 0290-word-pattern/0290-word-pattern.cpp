// https://leetcode.com/problems/word-pattern/discuss/2977947/LeetCode-The-Hard-Way-Explained-Line-By-Line
// refer this too => https://www.youtube.com/watch?v=XO4U2KWgIgY

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // convert s to a vector of strings
        // e.g. "dog cat cat dog" -> ["dog", "cat", "cat", "dog"]
        stringstream ss(s);
        string word;
        vector<string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        // the size of words needs to be same as that of pattern
        // e.g. words = ["xxx"], pattern = "xxx"
        if (words.size() != pattern.size()) {
            return false;
        }
        // for each word in words ...
        // char in pattern -> word
        // e.g. a -> dog
        // e.g. b -> cat
        unordered_map<char, string> m;
        set<string> used;
        for (int i = 0; i < words.size(); i++) {
            // check if map the pattern
            if (m.count(pattern[i])>0) {
                // if pattern[i] exists in the hashmap,
                // then we need to make sure that the word is correct
                // if correct mapping is not found, return false
                if (m[pattern[i]] != words[i]) {
                    return false;
                }
            } else {
                // each word can only map to one pattern, so check if the word is used before, if found in set then cannot be mapped and pattern is broken
                // so return false
                // e.g. pattern = "ab", s = "dog dog"
                if (used.find(words[i]) != used.end()) {
                    return false;
                }
                // if not, then map it   
                // e.g. a -> dog
                m[pattern[i]] = words[i];
                used.insert(words[i]);
            }
        }
        return true;
    }
};

// abba
// dog cat cat dog
// a -> dog
// b -> cat
// hashmap