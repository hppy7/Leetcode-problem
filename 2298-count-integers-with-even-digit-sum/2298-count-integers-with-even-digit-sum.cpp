class Solution {
public:
    int countEven(int num) {
 int c=0;
       for(int i=2;i<=num;i++) 
       {
        int x = i;
            int sum = 0;

            // calculate digit sum (YOUR WAY: inside loop)
            while(x > 0)
            {
                sum += x % 10;
                x /= 10;
            }

            // YOUR STYLE: use if block + c++ 
            if(sum % 2 == 0)
            {
                c++;
            }
        }
       return c;
    }
};