// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true

    class Solution {
    public:
        // backtracking implementation  
        bool isValid(string s) {
            try{
                consume_token(s.c_str());
            } catch (...){
                return false;
            }
            return true;
        }
        
        void consume_token(const char* c){
            while(*(c) != '\0'){
                switch (*c){
                    case '(':  
                    c = parse_s(c+1);              
                    break;
                    case '[':
                    c = parse_m(c+1);
                    break;
                    case '{':
                    c = parse_l(c+1);
                    break;
                    default:
                    throw "wrong";
                }
            }
            exit:
                return;
        }

        const char* parse_s(const char* c){            
            while(true){
                switch (*c){
                    case '(':
                    c = parse_s(c+1);
                    break;
                    case '[':
                    c = parse_m(c+1);
                    break;
                    case '{':
                    c = parse_l(c+1);
                    break;
                    case ')':
                    goto exit;
                    default:
                    throw "wrong";
                }
            }
            exit:
                return (c+1);
        }
        const char* parse_m(const char* c){            
            while(true){
                switch (*c){
                    case '(':
                    c = parse_s(c+1);
                    break;
                    case '[':
                    c = parse_m(c+1);
                    break;
                    case '{':
                    c = parse_l(c+1);
                    break;
                    case ']':
                    goto exit;
                    default:
                    throw "wrong";
                }
            }
            exit:
                return (c+1);
        }
        const char* parse_l(const char* c){            
            while(true){
                switch (*c){
                    case '(':
                    c = parse_s(c+1);
                    break;
                    case '[':
                    c = parse_m(c+1);
                    break;
                    case '{':
                    c = parse_l(c+1);
                    break;
                    case '}':
                    goto exit;
                    default:
                    throw "wrong";
                }
            }
            exit:
                return (c+1);
        }

    };
