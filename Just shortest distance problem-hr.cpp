#include<bits/stdc++.h>
using namespace std;
#define M 1010
#define Mx 1101010

vector<int>v[M];
bool mark[M][M];
int dist[M];

void init()
{
    for(int i=0;i<M;i++)
        dist[i]=Mx;
    dist[1]=0;
}
void bfs(int s){
    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        int sz = v[u].size();
        for(int i=0;i<sz;i++){
            int p=v[u][i];

            if(dist[u]+1<dist[p]){
                dist[p]=dist[u]+1;
                q.push(p);
            }
        }
    }
}

int main()
{
    init();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int q;
        scanf("%d",&q);

        if(q==1){
            int d;
            scanf("%d",&d);

            if(dist[d]<Mx){
                printf("%d\n",dist[d]);
            }
            else{
                printf("-1\n");
            }
        }
        else{
            int x,y;
            scanf("%d%d",&x,&y);
            if(!mark[x][y])
            {
                v[x].push_back(y);
                mark[x][y]=1;
                bfs(x);
            }
        }
    }
    return 0;
}
