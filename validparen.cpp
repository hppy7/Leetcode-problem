#include<stdio.h>
#include<string>
using namespace std ;

bool isvalid(string s){
    int n = s.length();

    stack <char> st;
    bool ans=true;
    for(int i=0;i<n;i++)
{
    if
}


}
int main(){
    string s ="{[()]}";
    if(isvalid(s)){
        cout<<"valid string ";
    }
    else{
        cout<<"invalid string";
    }
    return 0;
}