class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& a, int t) {
        int cnt = 0;
        int n = a.size();
        vector<int> dec(n),inc(n);
        for(int i=1;i<n;i++)
        {
            if(a[i]<=a[i-1]) cnt++;
            else cnt = 0;
            dec[i] = cnt;
        }
        cnt = 0;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]<=a[i+1]) cnt++;
            else cnt = 0;
            inc[i] = cnt;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            // cout << dec[i] << " " << inc[i] << endl;
            if(dec[i]>=t && inc[i]>=t) ans.push_back(i);
        }
        return ans;
    }
};
