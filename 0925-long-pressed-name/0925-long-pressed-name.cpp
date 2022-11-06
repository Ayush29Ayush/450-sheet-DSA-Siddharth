// TWO POINTER lagega
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0; // for name
        int j = 0; // for typed
        
        // if(name.length()==1 && typed.length()==1)
        // {
        //     if(name[0]!=typed[0])
        //         return false;
        //     else
        //         return false;
        // }
        
        while(i<name.length() && j<typed.length())
        {
            // agar dono hi equal hai toh next index pe kudh jao
            if(name[i]==typed[j])
            {
                i++;
                j++;
            }
            // agar dono equal nahi hai toh ek baar pichle index ke saath compare karke dekhlo kahi voh same toh nahi since faulty keyboard hai
            else if(i>0 && name[i-1]==typed[j])
            {
                j++;
            }
            // agar typed mein voh char hua hi nahi toh wrong type hua hai
            else
            {
                return false;
            }
        }
        
        // abhi j uss position pe hoga jahan name khatam ho chuka hoga and typed ka ek koi extra char hoga
        while(j<typed.length())
        {
            if(typed[j]!=name[i-1])
                return false;
            j++;
        }
        
        return i==name.size();
    }
};