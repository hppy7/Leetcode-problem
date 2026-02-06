class Solution {
public:
bool isAlphaNum(char ch)
{
    ch= tolower(ch);
    if(ch>= 'a' && ch <= 'z')
      return true;
      if(ch>='0' && ch<='9')
      return true;

      return false;
}
    bool isPalindrome(string s) {


    int n=s.size();
 int i=0,j=n-1;
    while(i<j) 
    {
        
        while(i<j && !isAlphaNum(s[i]))
        i++;
        while(i<j && !isAlphaNum(s[j]))
        j--;
        if(tolower(s[i])!=tolower(s[j]))
        return false;
        i++,j--;
    }
    return true;
    }
};