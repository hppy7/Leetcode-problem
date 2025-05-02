class Solution {
public:
    string pushDominoes(string str) {
     
  int n=str.length();
  char* arr=new char[n+2];
  arr[0]='L';
  arr[n+1]='R';
  for(int i=1;i<=n;i++){
  arr[i]=str[i-1];


    }



    int i=0;
    int j=1;
    while(j<n+2)
    {

        while(arr[j]=='.')
        {
            j++;
        }
         if((j-i )>0)
         {

        if(arr[i]=='L' && arr[j]=='L')
        {
            for(int k=i+1;k<j;k++)
            {
                arr[k]='L';
            }
        }else if(arr[i]== 'R' && arr[j]== 'R')
        {
            for(int k=i+1;k<j;k++)
            {
                arr[k]='R';
            }
        }else if(arr[i]== 'L' && arr[j]== 'R')
        {
            
        }else 
        {

          int diff=j-i;
          int mid=(j+i)/2;
          if(diff%2==0)  
          {
            for(int k=i+1;k<mid;k++)
            {
                arr[k]='R';
            }
            for(int k=mid+1;k<j;k++)
            {
                arr[k]='L';
            }
          }else
          {
          for(int k=i+1;k<=mid;k++)
            {
                arr[k]='R';
            }
            for(int k=mid+1;k<j;k++)
            {
                arr[k]='L';
            }

          }

    
        }

        


           }
             i=j;
        j++;

        //  String ans="";
        //  for(int i=1;i<arr.length-1;i++)
        //  {

        //     res+=arr[i];
        //  }
       //  return ans;
    }

    string ans="";
         for(int i=1;i<=n;i++)
         {

            ans+=arr[i];
         }
     return ans;
    }
};


// class Solution {
// public:
//     string pushDominoes(string str) {
//         int n = str.length();
//         string arr = "L" + str + "R"; // Adding sentinels

//         int i = 0;
//         for (int j = 1; j < arr.size(); ++j) {
//             if (arr[j] == '.') continue;

//             if (arr[i] == arr[j]) {
//                 // Fill same direction
//                 for (int k = i + 1; k < j; ++k)
//                     arr[k] = arr[i];
//             } else if (arr[i] == 'R' && arr[j] == 'L') {
//                 // Fill opposing directions
//                 int l = i + 1, r = j - 1;
//                 while (l < r) {
//                     arr[l++] = 'R';
//                     arr[r--] = 'L';
//                 }
//                 // If l == r, middle stays '.'
//             }
//             i = j;
//         }

//         // Return without the sentinels
//         return arr.substr(1, n);
//     }
// };
