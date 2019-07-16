#include<bits/stdc++.h>
using namespace std;
#define M 50

vector<int>v[M];
int visit[M];
int dist[M];
int len=0;
int mat[M][M];

void initiat(int a[],int c){
    for(int i=0;i<M;i++){
        a[i]=0;
    }
}

void initMat(int a[M][M],int c){
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            a[i][j]=c;
        }
    }
}

void dfs(int s,int c){
    dist[s]=c;
    for(int i=v[s].size()-1;i>=0;i--){
        if(mat[s][v[s][i]]==0 && mat[v[s][i]][s]==0){
            len++;
            mat[s][v[s][i]]=1;
            mat[v[s][i]][s]=1;
            dfs(v[s][i],dist[s]+1);
        }
    }
}


int maxLength(int n){
    int mx=0;
    for(int i=0;i<n;i++){
        mx=max(mx,dist[i]);
    }
    return mx;
}

int main()
{
    while(1){
        int n,m;
        cin>>n>>m;
        if(n==0 && m==0){
            break;
        }

        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        int mx=0;
        for(int i=0;i<n;i++){
            initMat(mat,0);
            initiat(dist,0);
            dfs(i,0);
            mx=max(mx,maxLength(n));
        }
        cout<<mx<<endl;

        for(int i=0;i<M;i++){
            v[i].clear();
        }
    }
    return 0;
}
