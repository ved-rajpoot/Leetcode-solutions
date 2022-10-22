class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp1,mp2;
        int ans = INT_MAX;
        int n = s.length(), m = t.length();
        for(int i=0;i<m;i++) mp2[t[i]]++;
        string res;
        int st=-1,en=-1;
        for(int i=0,j=0;i<n && j<n;j++)
        {
            
            mp1[s[j]]++;
            while(mp1[s[i]]>mp2[s[i]])
            {
                mp1[s[i]]--;
                i++;
            }
            bool flag = 1;
            for(char c='a';c<='z';c++)
            {
                if(mp1[c]<mp2[c])
                {
                    flag = 0;
                }
            }
            for(char c='A';c<='Z';c++)
            {
                if(mp1[c]<mp2[c])
                {
                    flag = 0;
                }
            }
            if(flag)
            {
                if(ans>j-i+1)
                {
                    st=i,en=j;
                    ans = j-i+1;
                }
            }
        }
        if(st==-1 || en==-1) return res;
        res = s.substr(st,en-st+1);
        return res;
    }
};