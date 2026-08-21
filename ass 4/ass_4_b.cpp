#include<iostream>
using namespace std;
int gcd(int a , int b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    if(a>b)
    {
        return gcd(a%b , b);
    }
    else
    {
        return gcd(a, b%a);
    }
}
int main(){
    int a , b;
    cin>>a>>b;

    int n = a*b ;
    int eulerTolrent = (a-1)*(b-1);
    int publicKey = -1;
    while(true)
    {
        int userVal ;
        cout<<"choose a public key between "<<1 <<" "<<eulerTolrent<<" :";
        cin>>userVal;
        if(gcd(userVal , eulerTolrent) == 1)
        {
            publicKey= userVal;
            break;
        }
        else
        {
            cout<<"not a good number to select "<<endl;
        }
    }
    publicKey = 17;
    long long pvtkey;
    for(int i =1 ; i< 1000 ; i ++)
    {
        long long val = publicKey*i;
        if(val % eulerTolrent == 1)
        {
            pvtkey = val;
            break;
        }
    }
    pvtkey = 2753;
    int message ;
    cin>>message;
    int decoded = message ;
    for(int i = 0 ; i < publicKey ; i ++ )
    {
        decoded = ((decoded*publicKey)%eulerTolrent);
    }
    cout<<decoded<<endl;
    return 0;
}