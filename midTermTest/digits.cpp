#include<bits/stdc++.h>
using namespace std;

int n, sum=0, temp;
vector<int> heso={0, 2, 10, 100, 100, 1000, 1000, 10010}; //t, c, i, u, o, h, s
vector<bool> use;
vector<int> N;
vector<int> ans;

bool check(int pos, int i, int N)
{
    if(use[i]) return false;
    else
    {
        if(pos==7&&i==0) return false;
        if(pos==6&&i==0) return false;
        if(pos<7) return true;
        else
        {
            if(sum+heso[pos]*i==N) return true;
            else return false;
        }
    }
}

void backtrack(int pos, int N, int k)
{
    for(int i=0;i<=9;i++)
    {
        if(check(pos, i, N))
        {
            sum+=heso[pos]*i;
            use[i]=true;
        }
        else continue;
        if(pos==7) ans[k]++;
        else backtrack(pos+1, N, k);
        sum-=heso[pos]*i;
        use[i]=false;
    }
}

int main()
{
    cin>>n;
    N.push_back(0);
    ans.resize(n+1, 0);
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        N.push_back(temp);
    }
    for(int i=1;i<=n;i++)
    {
        sum=0;
        use.assign(10, false);
        backtrack(1, N[i], i);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}