#include<bits/stdc++.h>
using namespace std;
#define M 5000

vector<int>v[M];
int visit[M];

void dfs(int s){
    if(visit[s]==1)
        return;
    visit[s]=1;
    for(int i=0;i<v[s].size();i++){
        dfs(v[s][i]);
    }
}

int main()
{
    int n,e,ck=0;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            dfs(i);
            if(visit[i]==1)
                ck++;
        }
    }

    cout<<ck<<endl;

    return 0;
}
