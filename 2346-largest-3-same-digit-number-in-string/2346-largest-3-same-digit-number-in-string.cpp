class Solution {
public:
    string largestGoodInteger(string num) {
       char maxchar = ' ';
       int n=num.size();
       int l=0,r=l+2;
       while(r<n) 
       {
        if(num[r]==num[r-1] && num[r]==num[r-2])
        {
           maxchar=max(maxchar,num[r]); 
        }
        l++;
        r++;
       }
       
       if(maxchar==' ')
       return "";
       return string(3,maxchar);
    }
};
// class Solution {
// public:
//     string largestGoodInteger(string num) {
//         for (char d = '9'; d >= '0'; d--) {
//             string pattern(3, d); // "999", "888", etc.
//             if (num.find(pattern) != string::npos) {
//                 return pattern; // return immediately on first match
//             }
//         }
//         return "";
//     }
//};











