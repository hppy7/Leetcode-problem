class Solution {
public:
typedef pair<char,int> P;
static bool comperator(const P &p1,const P &p2)
{
    return p1.second>p2.second;
}
    string frequencySort(string s) {
        string result="";
vector <P> vec(256);

for(auto ch:s)
{

    //frequency find keep in vector with fre
int fre=vec[ch].second;
vec[ch]={char(ch),fre+1};
}
sort(vec.begin(),vec.end(),comperator);
for(int i=0;i<256;i++)
{  if(vec[i].second>0)
{
    int fre=vec[i].second;
    char ch=vec[i].first;
    string temp=string(fre,ch);
    result+=temp;
}
}
    return result;  
    }
};