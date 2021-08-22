// https://codingcompetitions.withgoogle.com/kickstart/round/000000000043585c/0000000000859dcd#problem

#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
const int N=1000;
int xa[N][N], ya[N][N];
int xb[N][N], yb[N][N];

char grid[N][N];
int equiv[N][N];
char tag[N*N];

void goRight(int x, int y)
{
    while(y<m and grid[x][y]=='#')
        y++;
    if(y==m) return;

    int ys= y;
    while(y<m and grid[x][y]!='#')
        y++;

    for(int j=ys; j<y; j++)
    {
        xa[x][j]= x;
        ya[x][j]= y+ys-1-j;
    }

    goRight(x, y);
}

void goDown(int x, int y)
{
    while(x<n and grid[x][y]=='#')
        x++;
    if(x==n) return;

    int xs= x;
    while(x<n and grid[x][y]!='#')
        x++;

    for(int i=xs; i<x; i++)
    {
        xb[i][y]= x+xs-1-i;
        yb[i][y]= y;
    }

    goDown(x, y);
}

void dfs(int x, int y, int t)
{
    if(equiv[x][y]!=-1)
        return;
    
    if(grid[x][y]!='.')
        tag[t]= grid[x][y];

    equiv[x][y]= t;
    dfs(xa[x][y], ya[x][y], t);
    dfs(xb[x][y], yb[x][y], t);
}

void test()
{
    memset(equiv, -1, sizeof(equiv));
    for(int i=0; i<N*N; i++)
        tag[i]= '.';

    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];

    for(int i=0; i<n; i++)
        goRight(i, 0);
    for(int j=0; j<m; j++)
        goDown(0, j);

    int t=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[i][j]!='#' and equiv[i][j]==-1)
                dfs(i, j, t++);

    int ans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j]=='#') continue;
            if(grid[i][j]!='.')
            {
                assert(grid[i][j]=tag[equiv[i][j]]);
                continue;
            }
            if(tag[equiv[i][j]]=='.') continue;
            ans++;
            grid[i][j]= tag[equiv[i][j]];
        }
    }

    cout<<ans<<'\n';
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<grid[i][j];
        cout<<'\n';
    }
}

signed main()
{
    iostream::sync_with_stdio(false);
    int q; cin>>q;
    for(int t=1; t<=q; t++)
    {
        cout<<"Case #"<<t<<": ";
        test();
    }
}
