class Solution {
public:
    int minimumCost(vector<int>& cost) {


    sort(cost.begin(), cost.end(), greater<int>()); // sort descending
        int am = 0;
        for (int i = 0; i < cost.size(); i++) {
            if ((i % 3) != 2) { // skip every 3rd candy (free one)
                am += cost[i];
            }
        }
   


return am;






//   int am=0;
//         int n=cost.size();
//         sort(cost.begin(),cost.end());
//         int k=0;
//         for(int i=n-1;i>=0;)
//         {
//             if(k<i){

//             if(i<0)
//             break;
        
//            am=am+cost[i];
//            i--;
//             if(i<0)
//             break;

//             am=am+cost[i];
//            int mn=cost[i];
//            i--;
//             if(i<0)
//             break;


//            int di=mn-cost[i];
//            i--;
            
//          if(k<i && di>0 && cost[k]<=di)
//          {
//             k++;
//          }
       
//             }
//         }
//         return am;
    }
};