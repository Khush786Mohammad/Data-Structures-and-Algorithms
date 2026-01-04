#include<bits/stdc++.h>
using namespace std;

vector<int> divisors(int num)
{
    vector<int> ans;

    int sqrtN = sqrt(num);

    for(int i = 1 ; i<= sqrtN ; i++)
    {
        if(num%i == 0)
        {
            ans.push_back(i);
            if(i != num/i)
            {
                ans.push_back(num/i);
            }
        }
    }
    return ans;
}

int main()
{
    int num = 36;
    vector<int> div = divisors(num);
    sort(div.begin(), div.end());
    for(int d: div)
    {
        cout<<d<<" ";
    }
    return 0;
}