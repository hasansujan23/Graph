#include<bits/stdc++.h>
using namespace std;
#define M 10010

vector<int>v[M];
stack<int>st;
int vis[M];

void initiat(){
    for(int i=0;i<M;i++){
        vis[i]=0;
    }
}

void topSort(int s){
    if(vis[s]==1)
        return;
    vis[s]=1;

    for(int i=0;i<v[s].size();i++){
        topSort(v[s][i]);
    }
    st.push(s);
}

void dfs(int s){
    if(vis[s]==1)
        return;
    vis[s]=1;

    for(int i=0;i<v[s].size();i++){
        dfs(v[s][i]);
    }
}

int main()
{
    int t;
    cin>>t;

    for(int k=0;k<t;k++){
        int n,e;
        cin>>n>>e;

        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
        }

        initiat();

        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                topSort(i);
            }
        }

        int ck=0;

        initiat();

        while(!st.empty()){
            int top=st.top();
            st.pop();

            if(vis[top]==0){
                dfs(top);
                ck++;
            }
        }

        cout<<"Case "<<k+1<<": "<<ck<<endl;

        for(int i=0;i<M;i++){
            v[i].clear();
        }
    }

    return 0;
}
