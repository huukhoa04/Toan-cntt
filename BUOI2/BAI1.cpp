//bai 1
#include<bits/stdc++.h> 
using namespace std;
#define ll long long
ll GCD(ll a, ll b)
{
    if (b == 0) return a;
    else return GCD(b, a % b);
}

ll LCM(ll a, ll b)
{
            return (a*b)/GCD(a,b);
}
int main()
{
    ll a,b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "UOC CHUNG: " << GCD(a,b) << "\n";
    cout << "BOI CHUNG: " << LCM(a,b);

}