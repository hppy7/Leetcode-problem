class Solution {
public:
    double myPow(double x, int n) {
  
   long long b=n;
   if(n<0)
   {
    x=1/x;
    b=-b;
   }
   double sum=1;
   while(b>0)
   {

    if(b%2==1)
    {
        sum*=x;
    }

    x=x*x;
    b=b/2;
   }
   return sum;














//   int a=n;
//   int b;
//   if(n<0)
//   { b=-n;}
//   else
//   {
//     b=n;
//   }
//        // if(n>=0)
//        // {
//      double sum=1;

//      for(int i=0;i<b;i++)   
//      {    
//         if(a>=0)
//      {
//         sum=sum*x;
//      }
//      else{
//         sum=sum*(1/x);
//      }
//      }
//      return sum;

//    /* }
//     else
//     {
//        double sum=1; 
//       for(int k=0;k>n;k--)
//       {
//      sum=sum*1/x;
//       }
//       return sum;
//     }*/
//    


 }
};