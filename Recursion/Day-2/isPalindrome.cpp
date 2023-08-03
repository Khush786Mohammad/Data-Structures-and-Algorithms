#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(string &str , int i,int j)
{
    if(i>=j)
    {
        return true;
    }
    if(str[i] != str[j])
    return false;
    else
    return isPalindrome(str,i+1,j-1);
}

bool isPalindrome2(string &str , int i)
{
    if(i >= str.length()/2)
    return true;

    if(str[i] != str[str.length()-1-i])
    return false;
    else
    return isPalindrome2(str,i+1);
}
int main()
{
    vector<string> v = {"abba" , "aba" , "a","abca" , "accaa","abcbc"};

    for(auto str : v)
    if(isPalindrome(str,0,str.length()-1))
    {
        cout<<"1";
        cout<<endl;
    }
    else
    {
        cout<<"0";
        cout<<endl;
    }

    for(auto str : v)
    if(isPalindrome2(str,0))
    {
        cout<<"1";
        cout<<endl;
    }
    else
    {
        cout<<"0";
        cout<<endl;
    }
    
    return 0;
}