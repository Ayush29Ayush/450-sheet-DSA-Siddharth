// https://www.youtube.com/watch?v=slqQfhL6kQU
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        vector<int> ans;
        
        // edge case
        if(p.size()>s.size())
            return {};
        
        // a->0 b->1 c->2 etc till z->25
        for(int i=0; i<p.size(); i++)
        {
            phash[p[i]-'a']++;
            shash[s[i]-'a']++;
        }
        // once phash is initialized, it will not change.
        // only shash will keep changing
        
        // checking the 1st substring
        if(phash==shash)
            ans.push_back(0);
        // ab aage ka for loop se dekh lo, excluding the 1st substring
        for(int i=p.size(); i<s.size(); i++)
        {
            // SLIDING WINDOW
            shash[s[i]-'a']++;
            shash[s[i-p.size()]-'a']--;
            // agar match kar gaya toh starting position daaloge
            if(shash==phash)
                ans.push_back(i+1 - p.size());
        }
        return ans;
    }
};