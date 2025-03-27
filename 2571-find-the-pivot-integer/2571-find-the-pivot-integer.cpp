class Solution {
public:
    int pivotInteger(int n) {
     int i;
     int sum=0;/// we calcute by formula of n nature numnder
     for(i=1;i<=n;i++)   
     {
        sum+=i;
     }
     int presum=0;
     int suxsum=0;
     if(n==1)
     return 1;
     for(i=1;i<=n;i++)   
     {
         presum+=i;
        // suxsum=sum-presum;
        if(presum==suxsum)
        {
            return i;
        }
        suxsum=sum-presum;
     }
     return -1;
    }
};