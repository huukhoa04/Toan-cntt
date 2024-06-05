#include <bits/stdc++.h>
//bai 2
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
struct Element
{
    ll value;
    int count;
};
ll GCD(ll a, ll b)
{
    if (b == 0) return a;
    else return GCD(b, a % b);
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
void ETF(ll number)
{
    int S;
    cout << "list: \n";
    for (int i = 1; i<number; i++)
    {
        ll a = GCD(i,number);
        if (a == 1){
            S+=i;
            cout << i << " ";
        }
    }
    cout << "\n";
    cout << "sum:  " << S << "\n";
}
void ETFFORMULA(ll n)
{
    vector<Element> temp;
    factorize(&temp, n);
    // for (int i = 0; i < temp.size(); i++)
    // {
    //     cout << temp.at(i).value << " " << temp.at(i).count;
    //     // A*= pow(temp.at(i).value, temp.at(i).count-1)*(temp.at(i).value - 1);
    // }
    ll A = 1;
    for (int i = 0; i < temp.size(); i++)
    {
        // cout << temp.at(i).value << " " << temp.at(i).count;
        A*= pow(temp.at(i).value, temp.at(i).count-1)*(temp.at(i).value - 1);
    }
    cout << A;
}
long long nearest_prime(ll n){

    ll lower = n - 1;
    while (!is_prime(lower) && lower%3 != 0) {
        lower -= 1;
    }
    ll upper = n + 1;
        while (!is_prime(upper) && upper% 3 != 0) {
            upper += 1;
        }
    return abs(n - lower) < abs(n - upper) ? lower : upper;
}
int main()
{
    ll n;
    cout << "input the value of n: "; cin >> n;
    ETF(n);
    cout << "nearest prime of n and dividable to 3: ";
    cout << nearest_prime(n);
    // cout << "\n the number of coprime number using ETF formula: ";
    // ETFFORMULA(n);
}