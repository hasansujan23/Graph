#include<bits/stdc++.h>
using namespace std;
#define M 100010

vector<int>v[M];
queue<int>q;

int visit[M];
int node[M];
int par[M];

void dfs(int s,int p){
    visit[s]=1;
    par[s]=p;

    for(int i=0;i<v[s].size();i++){
        if(visit[v[s][i]]==0){
            node[s]++;
            dfs(v[s][i],s);
        }
    }
}

int happyVertice(int n){
    int mx=0;
    for(int i=1;i<=n;i++){
        if(node[i]>node[par[i]]){
            mx++;
        }
    }

    return mx;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    int mn=INT_MAX;

    for(int i=1;i<=n;i++){
        if(mn>v[i].size()){
            mn=i;
        }
    }

    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            dfs(i,i);
        }
    }

    cout<<happyVertice(n)<<endl;

    return 0;
}

