#include<bits/stdc++.h>
using namespace std;
#define M 30010

vector<int>v[M];
int vis[M];
int ck=0;

void initiat(){
    for(int i=0;i<M;i++){
        vis[i]=0;
    }
}

void dfs(int s){
    if(vis[s]==1)
        return;
    vis[s]=1;
    ck=ck+1;

    for(int i=0;i<v[s].size();i++){
        dfs(v[s][i]);
    }
}

int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n,m;
        cin>>n>>m;

        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        initiat();

        int mx=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                ck=0;
                dfs(i);
                mx=max(mx,ck);
            }
        }
        cout<<mx<<endl;

        for(int i=0;i<M;i++){
            v[i].clear();
        }
    }
    return 0;
}
