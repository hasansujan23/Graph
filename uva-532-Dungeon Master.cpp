#include<bits/stdc++.h>
using namespace std;
#define M 31

int cell[M][M][M];
int visit[M][M][M];
int dist[M][M][M];

int fx[]={1,-1,0,0,0,0};
int fy[]={0,0,1,-1,0,0};
int fz[]={0,0,0,0,1,-1};

int row=0,col=0,level=0;

bool valid(int x,int y,int z){
    if(x>=0 && x<level && y>=0 && y<row && z>=0 && z<col && cell[x][y][z]!=0){
        return true;
    }
    return false;
}

struct pr{
    int x,y,z;
    pr(int _x,int _y,int _z){
        x=_x;
        y=_y;
        z=_z;
    }
    pr(){}
};

void bfs(int x,int y,int z){
    visit[x][y][z]=1;
    dist[x][y][z]=0;

    queue<pr>q;
    q.push(pr(x,y,z));

    while(!q.empty()){
        pr top=q.front();
        q.pop();

        int tx,ty,tz;

        for(int i=0;i<6;i++){
            tx=top.x+fx[i];
            ty=top.y+fy[i];
            tz=top.z+fz[i];

            if(valid(tx,ty,tz) && (dist[top.x][top.y][top.z]+1)<dist[tx][ty][tz]){
                dist[tx][ty][tz]=dist[top.x][top.y][top.z]+1;
                visit[tx][ty][tz]=1;
                q.push(pr(tx,ty,tz));
            }
        }
    }
}

int main()
{
    while(1){
        int l,r,c;
        cin>>l>>r>>c;
        row=r;col=c;level=l;
        if(l==0 && r==0 && c==0)
            break;

        int sx=0,sy=0,sz=0,dx=0,dy=0,dz=0;

        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                for(int k=0;k<M;k++){
                    dist[i][j][k]=INT_MAX;
                }
            }
        }

        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                string s;
                cin>>s;
                for(int k=0;k<c;k++){
                    if(s[k]=='.' || s[k]=='S' || s[k]=='E'){
                        cell[i][j][k]=1;
                    }
                    if(s[k]=='S'){
                        sx=i;
                        sy=j;
                        sz=k;
                    }
                    if(s[k]=='E'){
                        dx=i;
                        dy=j;
                        dz=k;
                    }
                }
            }
        }

        bfs(sx,sy,sz);
        if(visit[dx][dy][dz]==0){
            cout<<"Trapped!"<<endl;
        }else{
            cout<<"Escaped in "<<dist[dx][dy][dz]<<" minute(s)."<<endl;
        }

        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                for(int k=0;k<M;k++){
                    cell[i][j][k]=0;
                    visit[i][j][k]=0;
                    dist[i][j][k]=0;
                }
            }
        }
    }
    return 0;
}
