class Solution {
public:
    int countPoints(string rings) {
    int n=rings.size();
  

  vector<vector<int>> ans(3, vector<int>(10, 0));
 for(int i=0;i<n;i=i+2)
 {
char ch=rings[i];
int nu=rings[i+1]-'0';
if(ch=='B')
ans[0][nu]++;
if(ch=='R')
ans[1][nu]++;
if(ch=='G')
ans[2][nu]++;
 }
 int an=0;
 for(int i=0;i<10;i++)
 {  int c=0;
    for(int j=0;j<3;j++)
    {
    if(ans[j][i]>=1)
    c++;
    }
    if(c==3)
    an++;
 }
return an;
    }
};