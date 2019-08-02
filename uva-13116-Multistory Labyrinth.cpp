#include<bits/stdc++.h>
using namespace std;
#define M 105

int cell[M][M][M];
int visit[M][M][M];
int dist[M][M][M];

int fx[]={-1,1,0,0,0,0};
int fy[]={0,0,-1,1,0,0};
int fz[]={0,0,0,0,-1,1};

int r=0,c=0,l=0;

struct pr{
    int z,x,y;
    pr(int _z,int _x,int _y){
        z=_z;
        x=_x;
        y=_y;
    }
    pr(){}
};

bool valid(int z,int x,int y){
    if(z>=0 && z<l && x>=0 && x<r && y>=0 && y<c && cell[z][x][y]!=0){
        return true;
    }
    return false;
}

bool zValid(int z,int x,int y){
    if(z>=0 && z<l && x>=0 && x<r && y>=0 && y<c && cell[z][x][y]==2){
        return true;
    }
    return false;
}


void bfs(int sz,int sx,int sy){

    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            for(int k=0;k<M;k++){
                dist[i][j][k]=INT_MAX;
            }
        }
    }

    visit[sz][sx][sy]=1;
    dist[sz][sx][sy]=0;

    queue<pr>q;

    q.push(pr(sz,sx,sy));

    while(!q.empty()){
        pr top=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int tx=top.x+fx[i];
            int ty=top.y+fy[i];
            int tz=top.z+fz[i];

            if(valid(tz,tx,ty) && (dist[top.z][top.x][top.y]+1)<dist[tz][tx][ty]){
                dist[tz][tx][ty]=dist[top.z][top.x][top.y]+1;
                visit[tz][tx][ty]=1;
                q.push(pr(tz,tx,ty));
            }
        }

        if(cell[top.z][top.x][top.y]==2){
                for(int i=4;i<6;i++){
                int tx=top.x+fx[i];
                int ty=top.y+fy[i];
                int tz=top.z+fz[i];

                if(zValid(tz,tx,ty) && (dist[top.z][top.x][top.y]+1)<dist[tz][tx][ty]){
                        dist[tz][tx][ty]=dist[top.z][top.x][top.y]+1;
                        visit[tz][tx][ty]=1;
                        q.push(pr(tz,tx,ty));
                    }
                }
            }
    }
}





int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while(1){
        int x,y,z;
        cin>>x>>y>>z;

        if(x==0 && y==0 && z==0)
            break;

        l=z;r=x;c=y;

        int sx=0,sy=0,sz=0,dx=0,dy=0,dz=0;

        for(int i=0;i<z;i++){
            for(int j=0;j<x;j++){
                string s;
                cin>>s;
                for(int k=0;k<y;k++){
                    if(s[k]=='S'){
                        cell[i][j][k]=1;
                        sz=i;
                        sx=j;
                        sy=k;
                    }
                    if(s[k]=='E'){
                        cell[i][j][k]=1;
                        dz=i;
                        dx=j;
                        dy=k;
                    }
                    if(s[k]=='.'){
                        cell[i][j][k]=1;
                    }
                    if(s[k]=='-'){
                        cell[i][j][k]=2;
                    }
                }
            }
        }

        bfs(sz,sx,sy);

        //cout<<"vis : "<<visit[dz][dx][dy]<<endl;
        if(visit[dz][dx][dy]==1){
            cout<<dist[dz][dx][dy]<<endl;
        }else{
            cout<<"-1"<<endl;
        }


        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                for(int k=0;k<M;k++){
                    visit[i][j][k]=0;
                    cell[i][j][k]=0;
                    dist[i][j][k]=0;
                }
            }
        }
    }
    return 0;
}

