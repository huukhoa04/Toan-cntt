//bai 5
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define ll long long
#define fix cout << "a\n"
#define fix1 cout << "a1\n"
#define fix2 cout << "a2\n"
ll Mcalc(ll m[], int size)
{
    ll M = 1;
    for (int i = 0; i<size; i++)
    {
        M*=m[i];
    }
    return M;
}
ll X_of(ll m[], int index, int size)
{
    ll X = 1;
    int i = 0;
    while (i<size)
    {
        if (i == index)
        {
            i++;

        }
        else{
            X *= m[i];
            i++;
        }
    }
    return X;
}
ll index_invertOf(ll m[], int index, int size)
{
    ll temp = X_of(m,index,size);
    int k = 0;
    // double temp2 = (double)(k*m[index] + 1);
    while ((k*m[index] + 1) % temp != 0)
    {
        k++;
    }
    ll temp_equal = (k*m[index] + 1) / temp;
    return temp_equal;
}
void ChineseTheorem(int size, ll a[], ll m[])
{
    ll M_temp = Mcalc(m,size);
    // cout << "M = " << M_temp << endl;
    ll S = 0;
    for (int i = 0; i<size; i++)
    {
        ll temp_X = X_of(m, i, size);
        // cout << "tempX " << i << "= " << temp_X << endl;
        ll temp_Y = index_invertOf(m, i, size);
        // cout << "tempY " << i << "= " << temp_Y << endl;
        S += a[i]*temp_X*temp_Y;
    }
    S = S % M_temp;
    while(S % M_temp > M_temp)
    {
        S = S % M_temp;
    }
    cout << " X = " << S << " + " << "k*" << M_temp << endl;
}
int main()
{
    int size;
    cout << "ENTER Number of Equations: ";
    cin >> size; getchar();
    ll a[size];
    ll m[size];
    for (int i = 0; i<size; i++)
    {
        cout << "a[" << i << "] = "; cin >> a[i];
        cout << "m[" << i << "] = "; cin >> m[i];
    }
    cout << "ALL EQUATIONS: \n";
    for (int i = 0; i<size; i++)
    {
        cout << "x = " << a[i] << " mod " << m[i] << "\n";
    }
    ChineseTheorem(size,a,m);

}