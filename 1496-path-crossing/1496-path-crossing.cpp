class Solution {
public:
    bool isPathCrossing(string path) {

   int nn=path.size();
    
    

    int x=0,y=0;
    unordered_set<string> st;
    string key=to_string(x)+ " "+ to_string(y);
    st.insert(key);
    for(int i=0;i<nn;i++)
    {

       if(path[i]=='S')
          y--;
        else if(path[i]=='N')
           y++;
       else  if(path[i]=='E')
           x++;
        else
           x--;

        key=to_string(x)+ " "+ to_string(y);

        if(st.find(key)!=st.end())
        {
            return true;
        }else
        {

            st.insert(key);
        }
        


    }

  return false;
    }
};