#include<bits/stdc++.h>
using namespace std;
#define M 30010

vector<int>v[M];
vector<int>cost[M];
int visit[M];
int dist[M];

void initiat(int a[],int val){
    for(int i=0;i<M;i++){
       a[i]=val;
    }
}

int startNode(int s){
    queue<int>q;
    int temp=0;
    int mx=0;
    initiat(visit,0);
    initiat(dist,0);

    visit[s]=1;
    dist[s]=0;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];

            if(visit[p]==0){
                visit[p]=1;
                dist[p]=dist[u]+cost[u][i];
                if(dist[p]>mx){
                    mx=dist[p];
                    temp=p;
                }
                q.push(p);
            }
        }

    }
    return temp;
}

int bfs(int s){
    queue<int>q;
    int mx=0;
    initiat(visit,0);
    initiat(dist,0);

    visit[s]=1;
    dist[s]=0;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];

            if(visit[p]==0){
                visit[p]=1;
                dist[p]=dist[u]+cost[u][i];
                mx=max(mx,dist[p]);
                q.push(p);
            }
        }

    }
    return mx;
}

int main()
{
    int t;
    cin>>t;

    for(int k=0;k<t;k++){
        int e;
        cin>>e;
        for(int i=0;i<e-1;i++){
            int x,y,c;
            cin>>x>>y>>c;
            v[x].push_back(y);
            v[y].push_back(x);
            cost[x].push_back(c);
            cost[y].push_back(c);
        }

        int src=startNode(0);

        cout<<"Case "<<k+1<<": "<<bfs(src)<<endl;

        for(int i=0;i<M;i++){
            v[i].clear();
            cost[i].clear();
        }

    }
    return 0;
}
