#include<bits/stdc++.h>
using namespace std;
#define M 1010

vector<int>v[M];
int visit[M];
int dist[M];

void bfs(int s){
    queue<int>q;
    q.push(s);
    visit[s]=1;
    dist[s]=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];

            if(visit[p]==0){
                visit[p]=1;
                dist[p]=dist[u]+1;
                q.push(p);
            }
        }
    }
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

    bfs(1);

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
