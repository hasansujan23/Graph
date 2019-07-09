#include<bits/stdc++.h>
using namespace std;

#define M 100005
vector<int>v[M];
queue<int>q;
int visit[M];
int dist[M];

void bfsDest(int s){
    q.push(s);
    visit[s]=1;
    dist[s]=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];
            if(visit[p]==0){
                q.push(p);
                dist[p]=dist[u]+1;
                visit[p]=1;
            }
        }
    }
}

int main()
{
    int a;
    cin>>a;
    for(int i=0;i<a;i++){
        int nod,edg;
        cin>>nod>>edg;
        for(int i=0;i<edg;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        bfsDest(1);
        cout<<dist[nod]<<endl;
        memset(visit,0,M);
        memset(dist,0,M);
        for(int i=0; i<=nod; i++)
            v[i].clear();
    }
    return 0;
}
