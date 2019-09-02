#include<bits/stdc++.h>
using namespace std;
#define M 10010

int parent[M];
int ranks[M];

struct node{
    int u,v,w;
    node(int _u,int _v,int _w){
        u=_u;
        v=_v;
        w=_w;
    }
    node(){}
};

bool operator < (node a,node b){
    return a.w<b.w;
}

vector<node>v;

void initialize(int n){
    for(int i=0;i<n;i++){
        parent[i]=i;
        ranks[i]=0;
    }
}

int findParent(int x){
    if(x!=parent[x])
        return parent[x]=findParent(parent[x]);
    else
        return x;
}

void unionSet(int x,int y){
    int px=findParent(x);
    int py=findParent(y);

    if(px==py)
        return;

    if(ranks[px]>ranks[py]){
        parent[py]=px;
    }
    else if(ranks[px]<ranks[py]){
        parent[px]=py;
    }
    else{
        parent[py]=px;
        ranks[px]++;
    }
}

int krushkal(int n){
    initialize(n);
    sort(v.begin(),v.end());

    int sum=0;
    int sz=v.size();

    for(int i=0;i<sz;i++){
        if(findParent(v[i].u)!=findParent(v[i].v)){
            unionSet(v[i].u,v[i].v);
            sum+=v[i].w;
        }
    }

    return sum;
}

int main()
{


    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;

        v.push_back(node(x,y,z));
    }

    cout<<krushkal(n)<<endl;

    return 0;
}
