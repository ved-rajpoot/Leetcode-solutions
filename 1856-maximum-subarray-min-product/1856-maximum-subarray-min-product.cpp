class Solution {
public:
    long long mod = 1e9+7;
    int maxSumMinProduct(vector<int>& a) {
        stack<int> st;
        int n = a.size();
        vector<long long> next(n),prev(n);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && a[st.top()]>=a[i])
            {
                st.pop();
            }
            if(st.empty()) prev[i] = -1;
            else prev[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && a[st.top()]>=a[i])
            {
                st.pop();
            }
            if(st.empty()) next[i] = n;
            else next[i] = st.top();
            st.push(i);
        }
        vector<long long> pre(n+1);
        for(int i=1;i<=n;i++)
        {
            pre[i] = a[i-1] + pre[i-1];
        }
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            long long temp = ((pre[next[i]] - pre[prev[i]+1])) * ((long long)a[i]);
            // temp %= mod;
            // cout << next[i] << " " << prev[i] << " " << temp << endl;
            ans = max(ans,temp);
        }
        return ans%mod;
    }
};