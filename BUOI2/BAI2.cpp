#include <bits/stdc++.h>
//bai 2
using namespace std;
#define ll long long
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
            S++;
            cout << i << endl;
        }
    }
    cout << "quantity: " << S;
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
int main()
{
    ll a;
    cout << "A = "; cin >> a;
    ETF(a);
    cout << "\n the number of coprime number using ETF formula: ";
    ETFFORMULA(a);
}
