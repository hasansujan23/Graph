#include<bits/stdc++.h>
using namespace std;
#define M 110

int cell[M][M];
int dist[M][M];
int row=0,col=0;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

struct pr{
    int x,y;
    pr(int _x,int _y){
        x=_x;
        y=_y;
    }
    pr(){}
};

void initiat(int a[M][M],int val){
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            a[i][j]=val;
        }
    }
}

int distance(){
    int ck=INT_MAX;
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if((i==0) || (j==0) || (j==col-1) || (i==row-1)){
                ck=min(ck,dist[i][j]);
            }
        }
    }
    return ck;
}

bool valid(int x,int y){
    if(x>=0 && x<row && y>=0 && y<col && cell[x][y]==0){
        return true;
    }
    return false;
}

void bfs(int sx,int sy){
    queue<pr>q;
    dist[sx][sy]=0;
    q.push(pr(sx,sy));

    while(!q.empty()){
        pr top=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int tx=top.x+fx[i];
            int ty=top.y+fy[i];

            if(valid(tx,ty) && dist[tx][ty]>(dist[top.x][top.y]+1)){
                dist[tx][ty]=dist[top.x][top.y]+1;
                q.push(pr(tx,ty));
            }
        }
    }
}

int main()
{
    int r,c,sx=0,sy=0;
    cin>>r>>c;

    row=r;col=c;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>cell[i][j];
            if(cell[i][j]==2){
                sx=i;sy=j;
            }
        }
    }

    initiat(dist,INT_MAX);

    bfs(sx,sy);

    int len=distance();

    if(len<INT_MAX){
        cout<<len<<endl;
    }else{
        cout<<-1<<endl;
    }

    return 0;
}

