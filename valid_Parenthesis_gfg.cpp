class Solution
{
public:
    bool ispar(string x)
    {
        stack <char> s;
        int n = x.length();
        
        for (int i=0;i<n;++i){
            if(x[i]=='(' || x[i]=='[' || x[i]=='{'){
                s.push(x[i]);
            }
            else{
                if(!s.empty()){
                    if((s.top()=='(' && x[i]==')') || 
                    (s.top()=='[' && x[i]==']') || 
                    (s.top()=='{' && x[i]=='}')){
                        s.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(s.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
