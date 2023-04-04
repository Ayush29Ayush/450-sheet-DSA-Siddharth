/*
    YOUTUBE VIDEO for refernce : <https://www.youtube.com/watch?v=QonXo5Em5VA>
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/optimal-partition-of-string/
*/

class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen(26, -1);
        
        int count = 0;
        int substringStart = 0;

        for (int i = 0; i < s.length(); i++)
        {
            // agar iss char ko pehle dekha hai toh udhar tak ek substring so count++, and ab new substring ka start from present index
            if (lastSeen[s[i] - 'a'] >= substringStart) 
            {
                count++;
                substringStart = i;
            }
            
            // har char ko last kahan dekha hai voh update karte jao har iteration mein
            lastSeen[s[i] - 'a'] = i;
        }
        // last wale subtring ke liye +1
        return count+1;
    }
};
