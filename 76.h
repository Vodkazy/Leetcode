class Solution {
public:
    int ct[1000];
    int cs[1000];
    set<char>ch_set;

    bool check(){ // s是否覆盖t
        bool flag = true;
        for(auto iter=ch_set.begin();iter!=ch_set.end();iter++){
            if(cs[*iter-'A']<ct[*iter-'A']){
                flag = false;
                break;
            }
        }
        return flag;
    }

    string minWindow(string s, string t) {
        for(int i=0;i<t.length();i++)ch_set.insert(t[i]);

        if(s.length()==1){
            if(s==t)return s;
            else return "";
        }

        memset(ct,0,sizeof(ct));
        for(int i=0;i<t.length();i++)ct[t[i]-'A']+=1;
        
        memset(cs,0,sizeof(cs));

        int minn = 9999999;
        int pos_l = -1, pos_r = -1;

        int l = 0;
        int r = 0;
        cs[s[l]-'A'] = 1;
        while(l<=r&&r<s.length()){
            if(!check()){
                r++;
                if(r<s.length()) cs[s[r]-'A'] += 1;
            } else {
                if(r-l+1 < minn){
                    minn = r-l+1;
                    pos_l = l;
                    pos_r = r;
                }
                cs[s[l]-'A'] -= 1;
                l++;
            }
        }
        if(pos_l==-1)return "";
        return s.substr(pos_l, pos_r-pos_l+1);        
    }
};

// 双指针滑动窗口，当前窗口不包含t时r++，包含时l++。每次包含的判断遍历字符全集56个，每个位置都要判断一次，复杂度O(56*|s|) 
