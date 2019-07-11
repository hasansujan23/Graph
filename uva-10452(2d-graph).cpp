#include<bits/stdc++.h>
using namespace std;
#define M 100

int a[M][M];
int visit[M][M];
int fy[]= {0,1,-1};
int fx[]= {-1,0,0};
int row=0,col=0;

bool valid(int x,int y)
{
    if(x>=0 && x<row && y>=0 && y<col && a[x][y]!=0)
    {
        return true;
    }
    return false;
}

void initiat(int arra[M][M],int val)
{
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<M; j++)
        {
            arra[i][j]=val;
        }
    }
}

struct pr
{
    int x,y;
    pr(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
    pr() {}
};

vector<pr>v;
int ck=0;

void bfs(int sx,int sy,int dx,int dy)
{
    int vis[M][M];
    initiat(vis,0);
    queue<pr>q;
    q.push(pr(sx,sy));
    vis[ sx ][ sy ] = 1 ;
    int c = 0 ;
    while(!q.empty())
    {
        pr u=q.front() ;
        q.pop();
        for(int i=0; i<3; i++)
        {
            int tx=u.x+fx[i];
            int ty=u.y+fy[i];

            if(valid(tx,ty) && !vis[ tx ][ ty ] )
            {
                vis[ tx ][ ty ] = 1 ;
                ck++;
                v.push_back(pr(tx,ty));
                if(tx==dx && ty==dy)
                    return;
                q.push(pr(tx,ty));
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int k=0; k<t; k++)
    {
        int m,n;
        int sx=0,sy=0,dx=0,dy=0;
        cin>>m>>n;
        row=m;
        col=n;
        for(int i=0; i<m; i++)
        {
            string s;
            cin>>s;
            for(int j=0; j<n; j++)
            {
                if(s[j]=='I' || s[j]=='E' || s[j]=='H' || s[j]=='O' || s[j]=='V' || s[j]=='A' || s[j]=='@' || s[j]=='#')
                {
                    a[i][j]=1;
                }
                if(s[j]=='@')
                {
                    sx=i;
                    sy=j;
                }
                if(s[j]=='#')
                {
                    dx=i;
                    dy=j;
                }
            }
        }

        bfs(sx,sy,dx,dy);
        for(int i=0;i<v.size();i++){
            int a=v[i].x;
            int b=v[i].y;

            if(a<sx)
                cout<<"forth";
            else if(b<sy)
                cout<<"left";
            else
                cout<<"right";

            sx=a;
            sy=b;
            if(i<v.size()-1)
                cout<<" ";
        }
        cout<<endl;
        sx=0;
        sy=0;
        initiat(a,0);
        v.clear();

    }

    return 0;
}
