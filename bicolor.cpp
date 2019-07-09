#include<bits/stdc++.h>
using namespace std;
#define M 200


int bfs(int s,vector<int>v[]){
    queue<int>q;
    int visit[M];
    int color[M];
    memset(visit,0,sizeof(visit));
    memset(color,-1,sizeof(color));

    q.push(s);
    visit[s]=1;
    color[s]=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];

            if(visit[p]==0){
                visit[p]=1;
                if(color[u]==0){
                    color[p]=1;
                }else{
                    color[p]=0;
                }

                q.push(p);
            }
            else{
                if(color[u]==color[p]){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int n;

    while(1){
        cin>>n;
        if(n==0)
            break;

        int e;
        cin>>e;
        vector<int>v[M];
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        if(bfs(0,v)){
            cout<<"BICOLORABLE."<<endl;
        }
        else{
            cout<<"NOT BICOLORABLE."<<endl;
        }
    }
    return 0;
}
