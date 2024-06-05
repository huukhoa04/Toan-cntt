//nearest prime
#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_prime(long long n) {
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
void SieveOfEratosthenes(ll n)
{
    ll S;
    cout << "List of " << n << "'s Primes: ";
    bool prime[n + 1];
    memset(prime, true, sizeof(prime)); //set tat ca thanh true
        
    for (int p = 2; p * p <= n; p++) {
                
        if (prime[p] == true) {
                    
            for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
                }
    }
        
            // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p]){
            cout << p << " ";
            S+=p;
            }
    cout << "\nSUM OF ALL PRIMES IN THE RANGE [1, " << n << "]: " << S << "\n";
}
long long nearest_prime(ll n){

    ll lower = n - 1;
    while (!is_prime(lower)) {
        lower -= 1;
    }
    ll upper = n + 1;
        while (!is_prime(upper)) {
            upper += 1;
        }
    return abs(n - lower) < abs(n - upper) ? lower : upper;
}
int main()
{
    ll n;
    cout << "INSERT N: "; cin >> n;
    getchar();
    char choice = '0';
    do
    {
        cout << "1. Tim cac so nguyen to nho hon " << n << ", liet ke cac so va tinh tong cua chung\n";
        cout << "2. Tim so nguyen to gan " << n <<  " nhat\n";
        cout << "3. OUT\n";
        cout << "nhap lua chon: "; cin >> choice; getchar();
        switch (choice)
        {
        case('1'):
        {
            SieveOfEratosthenes(n);
            break;
        }
        case('2'):
        {
            cout << "SO NGUYEN TO GAN " << n << " NHAT: " <<  nearest_prime(n) << "\n";
            break;
        }
        default:{
            
            break;
        }
        }
    } while (choice != '3');
}
