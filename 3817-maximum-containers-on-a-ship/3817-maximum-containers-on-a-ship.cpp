class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        
    //  int c=0;
    //  int sum=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<n;j++)
    //         {    sum+=w;
    //             if(sum>maxWeight)
    //             {
    //               return c;
    //             }
    //             c++;
    //         }
    //     }
   //return c;

   
        return min(n*n,maxWeight/w);
    }
};