#include<bits/stdc++.h>
using namespace std;

#define M 200

vector<int>v[M];
int visit[M];
int color[M];


bool dfs(int s,int c){
    //visit[s]=1;
    color[s]=c;

    for(int i=0;i<v[s].size();i++){
        if(color[v[s][i]]==-1 && !dfs(v[s][i],1-c)){
            return false;
        }
        else if(color[s]==color[v[s][i]]){
                return false;
            }
    }
    return true;
}

int main()
{
    while(1){
        int n,e;
        cin>>n;
        if(n==0)
            break;
        cin>>e;
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;

            v[x].push_back(y);
            v[y].push_back(x);
        }

        //memset(visit,0,sizeof(visit));
        memset(color,-1,sizeof(color));

        if(dfs(0,0)){
            cout<<"BICOLORABLE."<<endl;
        }
        else{
            cout<<"NOT BICOLORABLE."<<endl;
        }

        for(int i=0;i<M;i++){
            v[i].clear();
        }
    }
    return 0;
}
