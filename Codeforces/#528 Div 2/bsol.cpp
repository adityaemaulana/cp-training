#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,i,ta,tb,D[101010],X;
double has;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(i=1;i<n;i++)
    {
        cin>>ta>>tb;
        D[ta]++;
        D[tb]++;
    }
    for(i=1;i<=n;i++)
        if(D[i]==1)X++;
    has=(double)k/(double)X;
    has=has*(double)2.0;
    cout<<fixed<<setprecision(12)<<has<<"\n";

}