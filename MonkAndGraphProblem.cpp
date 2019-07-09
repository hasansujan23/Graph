#include<bits/stdc++.h>
using namespace std;
#define M 100010

vector<int>v[M];
int visit[M];

int bfs(int s){
    queue<int>q;
    q.push(s);
    visit[s]=1;
    int ck=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];
            ck++;
            if(visit[p]==0){
                visit[p]=1;
                q.push(p);
            }
        }
    }
    return (ck/2);
}

//void dfs(int s){
//    if(visit[s]==1)
//        return;
//    visit[s]=1;
//    for(int i=0;i<v[s].size();i++){
//        component[s]++;
//        dfs(v[s][i]);
//    }
//}

int main()
{
    int n,e,mx=0;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i=1;i<=n;i++){
        if(visit[i]==0){
            mx=max(mx,bfs(i));
            //cout<<bfs(i)<<endl;
        }
    }

    cout<<mx<<endl;

    return 0;
}

