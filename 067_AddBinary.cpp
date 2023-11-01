// Given two binary strings a and b, return their sum as a binary string.

 

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

class Solution {
public:
    string addBinary(string a, string b) {
        auto i = a.rbegin();
        auto j = b.rbegin();
        auto [fir, res] = charAdd(*i, *j, '0');
        string str;
        str.push_back(fir);
        ++i;
        ++j;

        while(i != a.rend() && j != b.rend()){
            auto [fir, sec] = charAdd(*i,*j, res);
            res = sec;
            str.push_back(fir);
            ++i;
            ++j;
        }

        while (i != a.rend()){
            auto [fir, sec] = charAdd(*i,'0',res);
            res = sec;
            str.push_back(fir);
            ++i;
        }

        while (j != b.rend()){
            auto [fir, sec] = charAdd(*j,'0',res);
            res = sec;
            str.push_back(fir);
            ++j;
        }


        if (res == '1') str.push_back(res);
        std::reverse(str.begin(), str.end());
        
        return str;
    }

    tuple<char, char> charAdd(char a, char b, char prev){
        int result = int(a + b + prev - '0' - '0' -'0');
        if (result == 3) return {'1', '1'};
        else if (result == 2) return {'0', '1'};
        else return {char(result + '0'), '0'};
    }
};
