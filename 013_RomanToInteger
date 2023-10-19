Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.



class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        tuple<int,bool> tup;
        for (string::iterator it = s.begin(); it!=s.end(); ++it){
            auto lookahead = it+1;
            tup = parseToken(*it, *lookahead);
            sum = sum + get<0>(tup);
            if (get<1>(tup) == true){
                ++it;
            }
        }
        return sum;
    }

    tuple<int,bool> parseToken(char cur,char lookahead){

        switch (cur){
            case 'I':
            if (lookahead == 'V'){
                return {4,true};
            } else if (lookahead == 'X'){
                return {9,true};
            } else{
                return {1, false};
            }

            case 'V':
            return {5,false};

            case 'X':
            if (lookahead == 'L'){
                return {40,true};
            } else if (lookahead == 'C'){
                return {90,true};
            } else {
                return {10,false};
            }

            case 'L':
            return {50,false};

            case 'C':
            if (lookahead == 'D'){
                return {400,true};
            } else if ( lookahead == 'M'){
                return {900,true};
            } else {
                return {100,false};
            }

            case 'D':
            return {500,false};

            case 'M':
            return {1000,false};
        }
        
        return {0,false};
    }

    
};
