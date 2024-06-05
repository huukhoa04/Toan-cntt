//uoc la prime
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Element
{
    long long value;
    int count;
};
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
            if (is_prime(i))
            {
                cout << i << " ";
                S+=i;
                count1++;
            }
        }
    }
    cout << "\n";
    cout << "so luong cac uoc so: " << count << "\n";
    cout << "so luong cac uoc so la so nguyen to: " << count1 << "\n";
    cout << "tong cac uoc so nguyen to: " << S << "\n";
}
void factorize(ll number, vector<Element>* Memory)
{
	int count = 0;
    Memory->clear();
	ll n = number;

	while (!(n % 2)) {
		n >>= 1; 
		count++;
	}

	if (count){
        struct Element A;
        A.count = count;
        A.value = 2;
        Memory->push_back(A);
    }
		// cout << 2 << " " << count << endl;

	for (long long i = 3; i <= sqrt(n); i += 2) {
		count = 0;
		while (n % i == 0) {
			count++;
			n = n / i;
		}
		if (count)
        {
            struct Element A;
            A.count = count;
            A.value = i;
            Memory->push_back(A);
        }
			// cout << i << " " << count << endl;
	}

	if (n > 2)
    {
        struct Element A;
        A.count = 1;
        A.value = n;
        Memory->push_back(A);
    }
		// cout << n << " " << 1 << endl;
}
long long sumOfFactor(ll n, vector<Element> Memory)
{
    // factorize(n, Memory);
    ll S = 1;
    for (int i = 0; i< Memory.size(); i++)
    {
        struct Element temp = Memory.at(i);
        S *= (pow(temp.value, temp.count + 1) - 1) / (temp.value - 1);
    }
    return S;
}
bool isPerfect(ll n, vector<Element> Memory)
{
    return n == sumOfFactor(n, Memory) - n;
}
void findPerfectAmount(ll n, vector<Element> Memory)
{
    ll S = 0;
    cout << "\nSO LUONG CAC SO HOAN HAO GIUA 1 va " << n << ": ";
    for (int i = 1; i <= n; i++)
    {
        factorize(i, &Memory);
        if (isPerfect(i, Memory)) {
            // cout << i << " ";
            S++;
        }
    }
    cout << S << "\n";
}
int main()
{ 
    vector<Element> Memory;
    ll n;
    cout << "INSERT N: "; cin >> n;
    // factorize(n, Memory);
    FindAllUOC(n);
    findPerfectAmount(n, Memory);
    return 0;
}