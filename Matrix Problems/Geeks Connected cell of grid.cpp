// connected cell in a grid

#include <iostream>
#include <vector>
using namespace std;
int ans;
int px[8]={0,0,1,-1,1,-1,1,-1};
int py[8]={1,-1,0,0,1,-1,-1,1};
int num;
void rec(vector<vector<int>>& a,int x, int y)
{
 
	ans=max(ans,num);
	for(int i=0;i<8;++i)
	{
		if( a[x+px[i]][y+py[i]]==1)
		{
			a[x+px[i]][y+py[i]]=0;
			++num;
			rec(a,x+px[i],y+py[i]);
		}
	}
 
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector< vector<int>> a( n+10, vector<int>(m+10,0));
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
	ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i][j]==1)
			{
				a[i][j]=0;
				num=1;
				rec(a,i,j);
			}
	cout<<ans;
	return 0;
}

