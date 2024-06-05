//bai 4
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Element
{
    ll value;
    int count;
};
ll modpow(ll x, ll n, ll m)
{
    if (n==0) return 1%m;
    ll u = modpow(x,n/2,m);
    u = (u*u)%m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}
void factorize(vector<Element> *A, ll n)
{
            int count = 0;
            ll temp = n;
                while (!(temp % 2)) 
                {
                    temp = temp/2; 
                    count++;
                }

                if (count)
                {
                    // cout << 2 << "^" << count;
                    struct Element B;
                    B.count = count;
                    B.value = 2;
                    A->push_back(B);
                }
                for (long long i = 3; i <= sqrt(n); i += 2)
                {
                    count = 0;
                    while (temp % i == 0) {
                        count++;
                        temp = temp / i;
                    }
                    if (count){
                        struct Element B;
                        B.count = count;
                        B.value = i;
                        A->push_back(B);
                            // cout << "*" << i << "^" << count << endl;
                    }
                
                }
}
ll ETF(ll n)
{
    vector<Element> temp;
    factorize(&temp, n);
    // for (int i = 0; i < temp.size(); i++)
    // {
    //     cout << temp.at(i).value << " " << temp.at(i).count << "\n";
    //     // A*= pow(temp.at(i).value, temp.at(i).count-1)*(temp.at(i).value - 1);
    // }
    ll A = 1;
    for (int i = 0; i < temp.size(); i++)
    {
        // cout << temp.at(i).value << " " << temp.at(i).count;
        A*= (ll)pow(temp.at(i).value, temp.at(i).count-1)*(ll)(temp.at(i).value - 1);
    }
    return A;
}
void FermatCheck(ll x, ll m)
{
    ll a = modpow(x, m-1, m);
    if (a == 1)
    {
        cout << m <<" is prime and " << x << " and " << m << " are coprime ";
    }
    else cout << m <<" is not prime or " << x << " and " << m << " are not coprime ";
}
void EulerCheck(ll x, ll m)
{
    ll temp = ETF(m);
    // cout << "ETF = " <<  temp << "\n";
    ll result = modpow(x, temp, m);
    if (result == 1)
    {
        cout << x << " and " << m << " are coprime ";
    } else cout << x << " and " << m << " are not coprime " ; 
    if (result == (m-1))
    {
        cout << m << " is prime ";
    } else cout << m << " is not prime ";
}
int main()
{
    cout << "nhap x, m: ";
    ll x,m;
    cin >> x >> m;
    char choice = '0';
    while (choice != '3')
    {
        cout << "\n";
        cout << "1. Fermat check\n";
        cout << "2. Euler check\n";
        cout << "3. Quit\n";
        cin >> choice;
        switch (choice)
        {
        case('1'):{
            FermatCheck(x,m);
            break;
        }
        case('2'):{
            EulerCheck(x,m);
            break;
        }
        case('3'): continue;
        default:
            break;
        }
    }
}