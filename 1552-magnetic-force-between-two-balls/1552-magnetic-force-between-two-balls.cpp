class Solution {
public:
    int maxDistance(vector<int>& p, int m) {
        

        int n=p.size();
        int s=1;
        sort(p.begin(),p.end());
        int e=p[n-1]-p[0];
      int ans;
        while(s<=e)
        {  
            int mid=s+(e-s)/2;
            int c=1;
           int sum=p[0];

           for(int i=1;i<n;i++)
           {
              if(sum+mid<=p[i])
              {
                c++;
                sum=p[i];
              }
           }
           if(c>=m)
           {
            s=mid+1;
            ans=mid;
           }else
           {
            e=mid-1;
           }

        }
        return ans;
    }
};