//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        // code here
        vector<int> v;
        for(int i=0;i<N;i++)
        {
            int x = H[i];
            int t = lower_bound(v.begin(),v.end(),x) - v.begin();
            if(t==v.size())
            {
                v.push_back(x);
            }
            else
            {
                v[t] = x;
            }
        }
        int ans = N - v.size();
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends