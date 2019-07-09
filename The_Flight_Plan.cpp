#include<bits/stdc++.h>
using namespace std;

#define M 1005
vector<int>v[M];
vector<int>pt;
queue<int>q;
int visit[1005];
int dist[1005];
int path[1005];

int t;

void bfsPath(int s){
    q.push(s);
    visit[s]=1;
    dist[s]=0;
    path[s]=s;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];
            if(visit[p]==0){
                visit[p]=1;
                dist[p]=dist[u]+1;
                path[p]=u;
                q.push(p);
            }
        }
    }

    if(visit[t]==0){
        return;
    }

    pt.push_back(t);
    int now=t;
    while(now!=s){
        now=path[now];
        pt.push_back(now);
    }
}

int main()
{
    int n,e,T,C;
    cin>>n>>e>>T>>C;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        sort(v[x].begin(),v[x].end());
        sort(v[y].begin(),v[y].end());
    }

    int s;
    cin>>s>>t;
    bfsPath(s);

    cout<<pt.size()<<endl;

    for(int i=pt.size()-1;i>=0;i--){
        cout<<pt[i];
        if(i>0)
            cout<<" ";
    }

    return 0;
}

