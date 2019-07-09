#include<bits/stdc++.h>
using namespace std;

#define M 100000

vector<int>v[M];

int bfs(int s,int t){
    queue<int>q;
    int visit[M];
    int level[M];
    int ck=0;

    memset(visit,0,sizeof(visit));
    memset(level,0,sizeof(level));

    q.push(s);
    visit[s]=1;
    level[s]=0;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int p=v[u][i];

            if(visit[p]==0){
                visit[p]=1;
                level[p]=level[u]+1;
                q.push(p);
            }
        }
    }

    for(int i=0;i<M;i++){
        if( level[i]<=t && visit[i]==1 ){
            ck++;
        }
    }
    return ck;
}

int main()
{
    int n;
    int t=1;
    while(1){
        cin>>n;
        if(n==0)
            break;
        set<int> st;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;

            v[x].push_back(y);
            v[y].push_back(x);
            st.insert(x);st.insert(y);
        }

        int a,b;
        while(1){
            cin>>a>>b;
            if(a==0 && b==0)
                break;

            int res=bfs(a,b);
            cout<<"Case "<<t<<": "<<st.size()-res<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
            t++;

        }

        for(int i=0;i<M;i++){
            v[i].clear();
        }
        //st.clear();
    }
    return 0;
}
