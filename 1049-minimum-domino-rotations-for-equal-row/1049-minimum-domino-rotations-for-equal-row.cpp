class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int n=tops.size();
        vector<int> countA(7),countB(7),countSame(7);
        for(int i=0;i<n;i++)
        {
       int a=tops[i];
       int b=bottoms[i];
       if(a==b)
       {
        countSame[a]++;
       }
       countA[a]++;
       countB[b]++;
        }

        int ans=n;
        for(int v=1;v<=6;v++)
        {
            if(countA[v] + countB[v]-countSame[v]==n)
            {
                int swap=min(countA[v],countB[v])-countSame[v];
                ans=min(ans,swap);

            }
            
        }
           return ans==n ? -1: ans;

    }
};