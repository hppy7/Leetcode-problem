class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {


 int n=t.size();
       vector<int> ans(n);
       ans[n-1]=0;
        
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
          
          while(!st.empty() && t[st.top()]<=t[i])
          {
           // ans[i]=st.top().second-i;
           st.pop();

          }
     if(st.empty())
     {
        ans[i]=0;
     }else
     {
        ans[i]=st.top()-i;
     }

        
        st.push(i);

        }
        return ans;
        
    }
};