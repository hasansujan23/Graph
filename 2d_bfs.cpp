#include<bits/stdc++.h>
using namespace std;

struct pr{
    int x,y;
    pr( int _x, int _y ) {
       x=_x;
       y=_y;
    }
    pr(){}
};


int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

int cell[100][100];
int visit[100][100];
int dist[100][100];

int row=5;
int col=5;

int valid(int x,int y){
    if(x>=0 && x<row && y>=0 && y<col && cell[x][y]!=-1){
      return 1;
    }
    return 0;
}

void bfs(int sx,int sy){
    for ( int i=0; i<100; i++ )
        for( int j=0;j<100; j++)
             dist[i][j]=INT_MAX;
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
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>cell[i][j];
        }
    }

    bfs(0,0);
    cout<<dist[row-1][0]<<endl;
    return 0;
}
