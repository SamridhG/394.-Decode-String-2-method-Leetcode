class Solution {
public:
    string decodeString(string s) {
        vector<int>A;
        vector<char>B;
        for(int S=0;S<s.size();S++)
        {
            if(isdigit(s[S]))
            {
               if((S-1)>=0 && isdigit(s[S-1]))
               {
                   int Q=A.back()*10 + (s[S]-48);
                   A.pop_back();
                   A.push_back(Q);
               }
                else
                {int Q=(s[S]-48);
                 A.push_back(Q);
                }
            }
            
         else
            {
                if(s[S]=='[')
                {
                    B.push_back(s[S]);
                }
                else if(s[S]>='a' && s[S]<='z')
                {
                    B.push_back(s[S]);
                }
                else
                {
                    string p,q="";
                    while(B.back()!='[')
                    {
                        p=p+B.back();
                        B.pop_back();
                    }
                    B.pop_back();
                reverse(p.begin(),p.end());
                    
                    while(A.back())
                    {
                        q.append(p);
                        A.back()--;
                    }
                    A.pop_back();
                    for(auto n:q)
                    {
                        B.push_back(n);
                    }
                    q.clear();
                    p.clear();
                 }
                }
        }
        string result(B.begin(),B.end());
        return result;
          
    }
};
