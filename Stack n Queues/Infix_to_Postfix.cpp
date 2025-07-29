#include<bits/stdc++.h>
using namespace std;

int prec(char ss)
{
    if(ss == '^')
        return 3;
    else if(ss == '*' || ss == '/')
        return 2;
    else if(ss == '+' || ss == '-')
        return 1;
    else
        return 0;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string postfix = "";
    int n = s.length();

    for(int i = 0 ; i<n ; i++)
    {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            postfix.push_back(s[i]);
        else
        {
            if(s[i] == '(')
                st.push('(');
            else if(s[i] == ')')
            {
                while(st.size() && st.top() != '(')
                {
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(st.size() && prec(s[i]) <= prec(st.top()))
                {
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while(st.size())
    {
        postfix.push_back(st.top());
        st.pop();
    }
    return postfix;
}

int main()
{
    string infix = "a+b*(c^d-)";
    string postfix = infixToPostfix(infix);
    cout<<postfix<<"\n";
    return 0;
}