class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        
        // sab char ke iterate karte hue ab after removal, jitne bach gaye they are the reqd char of the string but in reverse order
        for(char ch : s){

            if(ch == '#'){
                if(s1.empty())
                    continue;
                s1.pop();
            }else{
                s1.push(ch);
            }
        }

        for(char ch : t){

            if(ch == '#'){
                if(s2.empty())
                    continue;
                s2.pop();
            }else{
                s2.push(ch);
            }
        }
        
        // ab even if it is in reverse order, just compare if same or not
        return (s1==s2);
    }
};