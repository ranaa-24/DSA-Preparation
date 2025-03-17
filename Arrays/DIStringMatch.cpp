class Solution {
    public:
        vector<int> diStringMatch(string s) {
            int n = s.length();
            int willIncrease = 0, willDecrease = n;  
            // we have to fill the res with the values of 0 to n 
            vector<int> res;
            for(char& ch : s){
                // of we see Inrease the will greedly choose a number that is smaller.. further it wil inrease anyway..
                if(ch == 'I') res.push_back(willIncrease++);
                else res.push_back(willDecrease--);
            }
    
            // push willIncrease or wilDecrease coz both will have same val
            res.push_back(willDecrease);
            return res;
        }
    };