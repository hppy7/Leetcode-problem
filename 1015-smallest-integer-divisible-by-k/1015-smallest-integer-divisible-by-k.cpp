class Solution {
public:
    int smallestRepunitDivByK(int k) {



 
        if(k==1)
        {
            return k;
        }
        int num=0;
        int ans=0;
        for(int i=0;i<k;i++)
        {



            num=(num * 10+1)%k;
                ans++;

          if(num%k==0)
          {

            
            return ans;

            
          }


    
           ;
        }

        return -1;
        
    }
};