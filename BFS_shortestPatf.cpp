#include<bits/stdc++.h>
using namespace std;

#define M 100
vector<int>v[M];
vector<int>pt;
queue<int>q;
int visit[100];
int dist[100];
int path[100];

int t;

void bfsPath(int s){
    q.push(s);
    visit[s]=1;

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
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int s;
    cin>>s>>t;
    bfsPath(s);

    cout<<"Minimum Cost: "<<dist[t]<<endl;

    for(int i=pt.size()-1;i>=0;i--){
        cout<<pt[i];
        if(i>0)
            cout<<"->";
    }

    return 0;
}
