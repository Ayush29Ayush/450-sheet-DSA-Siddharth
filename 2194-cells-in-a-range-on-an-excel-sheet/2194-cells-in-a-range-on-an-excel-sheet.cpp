class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> result;
        int no1 = s[1]-'0', no2 = s[4]-'0', max_n, min_n;
        char a = s[0], b = s[3];

        max_n = max(no1,no2);
        min_n = min(no1,no2);

        char j = a;
        while(j <= b){
            int i = min_n;
            while(i <= max_n){
                result.push_back(j+to_string(i));
                i++;
            }
            j++;
        }
        return result;
    }
};