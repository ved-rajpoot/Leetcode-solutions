class Solution {
public:
    int minCost(vector<int>& a, vector<int>& b, vector<int>& r, vector<int>& c) {
        int sr = a[0], sc = a[1];
        int er = b[0], ec = b[1];
        if(sr>er) 
        {
            sr--;
            er--;
            swap(sr,er);
        }
        if(sc>ec) 
        {
            sc--;
            ec--;
            swap(sc,ec);
        }
        int ans = 0;
        for(int i=sr+1;i<=er;i++)
        {
            ans += r[i];
        }
        for(int i=sc+1;i<=ec;i++)
        {
            ans += c[i];
        }
        return ans;
    }
};