class Solution {
public:
    int strStr(string h, string n) {
        
 if(n.empty()) return 0;                 // empty needle case
        if(h.size() < n.size()) return -1;

        for(int i=0;i<=(h.length()-n.length());i++)
        {
            if(h.substr(i,n.length())==n)
            return i;
        }
        return -1;
    }
};