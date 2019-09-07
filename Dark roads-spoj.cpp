#include<bits/stdc++.h>
using namespace std;
#define M 200010


int parent[M];
int ranks[M];

struct node{
    int x,y,c;
    node(int _x,int _y,int _c){
        x=_x;
        y=_y;
        c=_c;
    }
};

bool operator < (node a,node b)
{
    return a.c<b.c;
}

void init(int n){
    for(int i=0;i<=n;i++){
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

void setUnion(int x,int y){
    int px=findParent(x);
    int py=findParent(y);

    if(px==py)
        return;

    if(ranks[px]>ranks[py]){
        parent[py]=px;
    }
    else if(ranks[py]>ranks[px]){
        parent[px]=py;
    }
    else{
        parent[py]=px;
        ranks[px]++;
    }
}

int krushkal(vector<node>v,int n){
    int mst=0;
    init(n);
    sort(v.begin(),v.end());
    int sz=v.size();
    for(int i=0;i<sz;i++){
        int px=v[i].x;
        int py=v[i].y;

        if(findParent(px)!=findParent(py)){
            setUnion(v[i].x,v[i].y);
            mst+=v[i].c;
        }
    }

    return mst;
}

int main()
{
    while(1){
        int m,n;
        //cin>>m>>n;
        scanf("%d%d",&m,&n);

        if(m==0 && n==0){
            break;
        }

        vector<node>v;
        int sum=0;

        for(int i=0;i<n;i++){
            int x,y,c;

            cin>>x>>y>>c;
            sum+=c;

            v.push_back(node(x,y,c));
        }

        int mst=krushkal(v,n);

        printf("%d\n",sum-mst);
    }
    return 0;
}
