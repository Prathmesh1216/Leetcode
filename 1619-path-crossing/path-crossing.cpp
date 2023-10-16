class Solution {
public:
    bool isPathCrossing(string path) 
    {
    pair<int,int>move;
    
    move.first=0;
    move.second=0;
    
    set<pair<int,int>>st;
    
    for(int i=0;i<path.length();i++)
    {
        if(st.find(move)!=st.end())
        {
            return true;	
        }
        else if(st.find(move)==st.end())
        {
            st.insert(move);
        }
        char ch = path[i];
        
        if(ch=='N')
        {
            move.first = move.first - 1;
        }
        else if(ch == 'E')
        {
            move.second = move.second + 1; 
        }
        else if(ch == 'S')
        {
            move.first = move.first + 1;
        }
        else if(ch == 'W')
        {
            move.second = move.second - 1;
        }
    }
    if(st.find(move)!=st.end())
        {
            return true;	
        }
        else if(st.find(move)==st.end())
        {
            st.insert(move);
        }
        return false;       
    }
};