#include<bits/stdc++.h>
using namespace std;
#define M 100005
vector<int>v[M],cost[M];


int bfsDist(int s){
    queue<int>q;
    int visit[M],dist[M];
    memset(visit,0,M);
    memset(dist,0,M);

    q.push(s);
    visit[s]=1;
    dist[s]=0;
    int sum=0,ck=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];
            if(visit[p]==0){
                visit[p]=1;
                dist[p]=dist[u]^cost[u][i];
                q.push(p);
            }
        }

        if(v[u].size()==1){
            if(dist[u]%2==1)
                ck++;
        }
    }
    return ck;
}


int main()
{
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int n;
        cin>>n;
        for(int i=0;i<n-1;i++){
            int x,y,z;
            cin>>x>>y>>z;
            v[x].push_back(y);
            v[y].push_back(x);
            cost[x].push_back(z);
            cost[y].push_back(z);
        }
        cout<<bfsDist(1)<<endl;
        for(int i=0;i<M;i++){
            v[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
