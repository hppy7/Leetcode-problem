class Solution {
public:
    string largestGoodInteger(string num) {

     char ans=' ';
        int n=num.size();
        for(int i=2;i<n;i++)
        {

            if(num[i]==num[i-1]  && num[i]==num[i-2])
            {
                ans=max(num[i],ans);
            }
        }
        

        if(ans==' ')
        return "";
        else
    return string(3,ans);
    }
};