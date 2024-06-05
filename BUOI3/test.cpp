#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_prime(ll n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
        }
    return true;
}
void FindAllUOC(ll n)
{
    cout << "danh sach cac uoc la so nguyen to cua " << n << ": ";
    ll count = 0;
    ll S = 0;
    ll count1 = 0;
    for (int i = 1; i<=n; i++)
    {
        if (n%i == 0){
            count++;
            cout << i << " ";
            
        }
    }
    
}
int main()
{
    ll n;
    cout << "INSERT N: "; cin >> n;
    FindAllUOC(n);
}