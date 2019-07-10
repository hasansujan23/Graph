#include<bits/stdc++.h>
using namespace std;
#define M 1010

vector<int>v[M];
int color[M];

int dfsTime=0;
int dist[M];

void dfs(int u,int d){
    color[u]=1;
    dist[u]=d;

    for(int i=0;i<v[u].size();i++){
        int p=v[u][i];

        if(color[p]==0)
        {
            dfs(p,dist[u]+1);
        }
    }

    color[u]=2;
}

struct pr{
    int x,y;
};

bool compare(pr a,pr b){
    if(a.y<b.y) return 1;
    if(a.y>b.y) return 0;
    if(a.x<b.x) return 1;
    return 0;
}


int main()
{
    int node;
    cin>>node;
    for(int i=0;i<node-1;i++){
        int x,y;
        cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1,0);

    int q;
    cin>>q;
    pr a[q];
    for(int i=0;i<q;i++){
        int pos;
        cin>>pos;

        a[i].x=pos;
        a[i].y=dist[pos];
    }
    sort(a,a+q,compare);
    cout<<a[0].x<<endl;
    return 0;
}

