#include<bits/stdc++.h>
// #include <Eigen/Dense>
#define EPSILON 0.0001
#define E_VAL 2.71828
#define ALPHA 0.1
#define GAMMA 0.01
using namespace std;
// using namespace Eigen;
double func(double x)
{
    // return x*x*x - x*x + 2;
    return 3*exp((pow(x,5)- pow(x,4))) + pow(x, 2) - 20*x + log(x+25) - 10;
}
double derivFunc(double x)
{
    return 3*exp((x+1)*pow(x, 4))*(5*x - 4)*pow(x,3) + 2*x + 1/(x+25) - 20;
}
// Matrix2f nablaOf(double a, double funcOfa)
// {
//     Matrix2f hello;
//     Matrix2f temp;
//     Matrix2f temp2;
//     hello << a, funcOfa, 0, 0;
//     temp << 2, 1, 1, 20;
//     temp2 << 5, 3, 0, 0;
//     Matrix2f result;
//     result = hello*temp - temp2;

//     return result.transpose();
// }
void GradientDescent(double x, int n)
{
    double init = func(x);
    double h = GAMMA;
    double temp = x;
    for(int i =0; i<10000; i++)
    {
        // x = h*nablaOf(x, func(x));
        temp = temp - GAMMA*derivFunc(temp);
        init = func(temp);
        
        
    }
    double result = temp;

    cout << "Solution: x = " << result << "\n";
    cout << "Cost: " << init << "\n";
    cout << "Gradient: " << derivFunc(temp) << "\n";
}




int main(int argc, char const *argv[])
{
    /* code */
    double x0 = 0;
    int n = 10000;
    // cout << func(x0);
    GradientDescent(x0, n);
    return 0;
}
