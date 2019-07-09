#include<bits/stdc++.h>
using namespace std;
#define M 1020

int cell[M][M];
int dist[M][M];
int row,col;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

void initiat(int a[M][M],int c){
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            a[i][j]=c;
        }
    }
}

struct pr{
    int x,y;
    pr(int _x,int _y){
        x=_x;
        y=_y;
    }
    pr(){}
};

int valid(int x,int y){
   if(x>=0 && x<row && y>=0 && y<col && cell[x][y]!=-1){
        return 1;
   }
   return 0;
}

void bfs(int sx,int sy){
    initiat(dist,INT_MAX);
    dist[sx][sy]=0;
    queue<pr>q;
    q.push(pr(sx,sy));

    while(!q.empty()){
        pr top=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int tx=top.x+fx[i];
            int ty=top.y+fy[i];

            if(valid(tx,ty) && (dist[top.x][top.y]+1)<dist[tx][ty]){
                dist[tx][ty]=dist[top.x][top.y]+1;
                q.push(pr(tx,ty));
            }
        }
    }

}

int main()
{
    while(1){
        cin>>row>>col;
        if(row==0 && col==0)
            break;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int r,m;
            cin>>r>>m;
            for(int j=0;j<m;j++){
                int loc;
                cin>>loc;
                cell[r][loc]=-1;
            }
        }

        int srcx,srcy;
        cin>>srcx>>srcy;
        int desx,desy;
        cin>>desx>>desy;

        bfs(srcx,srcy);

        cout<<dist[desx][desy]<<endl;

        initiat(cell,0);
    }
    return 0;
}
