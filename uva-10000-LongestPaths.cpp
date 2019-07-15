#include<bits/stdc++.h>
using namespace std;
#define M 110

vector<int>v[M];
int dist[M];
int des=INT_MAX,mx=0;

void bfs(int s){
    dist[s]=0;
    queue<int>q;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];

            if(dist[p]<=dist[u]+1){
                dist[p]=dist[u]+1;
                mx=dist[p];
                q.push(p);
            }
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int k=1;
    while(1){
        int n;
        cin>>n;
        if(n==0)
            break;
        int src;
        cin>>src;

        while(1){
            int x,y;
            cin>>x>>y;
            if(x==0 && y==0)
                break;
            v[x].push_back(y);
        }

        bfs(src);

        for(int i=1;i<=n;i++){
            if(dist[i]==mx){
                des=i;
                break;
            }
        }

        if(v[src].size()==0){
            des=src;
        }

        cout<<"Case "<<k<<": The longest path from "<<src<<" has length "<<mx<<", finishing at "<<des<<"."<<endl;
        cout<<endl;

        k++;
        mx=0;
        des=INT_MAX;

        for(int i=0;i<M;i++){
            v[i].clear();
            dist[i]=0;
        }
    }
    return 0;
}
