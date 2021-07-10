class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        bool flag = true;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(s[i]==')'){
                    if(st.empty() || st.top()!='('){
                        flag = false;
                        break;
                    }else{
                        st.pop();
                    }
                }
                if(s[i]=='}'){
                    if(st.empty() || st.top()!='{'){
                        flag = false;
                        break;
                    }else{
                        st.pop();
                    }
                }
                if(s[i]==']'){
                    if(st.empty() || st.top()!='['){
                        flag = false;
                        break;
                    }else{
                        st.pop();
                    }
                }
            }
        }
        if(!st.empty())flag = false;
        return flag;
    }
};

// easy stack 
