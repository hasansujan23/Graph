#include<bits/stdc++.h>
using namespace std;
#define M 100010

int parent[M];
int ranks[M];
int node[M];

void initialize(int n){
    for(int i=0;i<=n;i++){
        parent[i]=i;
        ranks[i]=0;
        node[i]=1;
    }
}

int findParent(int x){
    if(x!=parent[x])
        return parent[x]=findParent(parent[x]);
    else
        return x;
}

void setUnion(int x,int y){
    int px=findParent(x);
    int py=findParent(y);

    if(px==py)
        return;

    if(ranks[px]>ranks[py]){
        parent[py]=px;
        node[px]+=node[py];
    }
    else if(ranks[py]>ranks[px]){
        parent[px]=py;
        node[py]+=node[px];
    }

    else{
        parent[py]=px;
        ranks[px]++;
        node[px]+=node[py];
    }
}


int main()
{
    int n,q;
    cin>>n>>q;
    initialize(n);

    for(int i=0;i<q;i++){
        char c;
        cin>>c;

        if(c=='M'){
            int x,y;
            cin>>x>>y;
            setUnion(x,y);
        }
        else{
            int u;
            cin>>u;

            int tmp=findParent(u);

            cout<<node[tmp]<<endl;
        }

    }

    return 0;
}
