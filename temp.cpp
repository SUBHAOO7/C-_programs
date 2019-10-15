#include <iostream>
#define ll long long int
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int main()
{
    FASTIO;             //For fast I/O
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;               //I have defined long long type as ll above
        cin>>n;
        ll a[n][n],i,j;     //decalring matrix of size N*N
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            cin>>a[i][j];       //taking input from user of the matrix
        }
        ll f1=0,f2=0;           //these are flag variable
        ll cn1=0,cn2=0;         //to count the number of rows and column which have 0
    for(i=0;i<n;i++)
    {
        f1=0;
        for(j=0;j<n;j++)
        {
            if(a[i][j]==0)      //Traversing the matrix row by row and checking of there is any 0
            {
                f1=1;           //if 0 found stop at that row and give 0 tp f1
                break;
            }
        }
        if(f1==1)               //count that row
        cn1++;
    }
     for(i=0;i<n;i++)
    {
        f2=0;
        for(j=0;j<n;j++)
        {
            if(a[j][i]==0)      //Traversing the matrix column by column and checking of there is any 0
            {
                f2=1;
                break;
            }
        }
        if(f2==1)           //count that column
        cn2++;
    }
    if(cn1==n && cn2==n)    //check if those count are equal to the total number of row and column
    cout<<"YES\n";
    else
    cout<<"NO\n";
    }


  return 0;
}
