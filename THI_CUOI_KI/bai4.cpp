#include <bits/stdc++.h>
#define EPSILON 0.00001
#define E_VAL 2.71828
#define ALPHA 0.1
#define GAMMA 0.001
using namespace std;

// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2  + 2
double func(double x)
{
    // return x*x*x - x*x + 2;
    // return 3*exp((pow(x,5)- pow(x,4))) + pow(x, 2) - 20*x + log(x+25) - 10;
    double term1 = exp(2 * x) + 3 * 2 * x * x + 8 * x;
    double term2 = 35 - x;
    double term3 = 5 * x;
    return (term1 / term2) - term3;
}

// Derivative of the above function which is 3*x^x - 2*x
double derivFunc(double x)
{
    // return 3*exp((x+1)*pow(x, 4))*(5*x - 4)*pow(x,3) + 2*x + 1/(x+25) - 20;
    double term1 = 71 * exp(2 * x) - 3 * x * x + 210 * x - 2 * x * exp(2 * x) + 280;
    double term2 = 35 * 35 - 2 * 35 * x + x * x;
    double term3 = -5;
    return (term1 / term2) - term3;
}
void GDwithMomentum(double x, int n)
{
    double velocity = 0;
    double theta = x;
    for (int i = 0; i < n; i++)
    {
        velocity = velocity * ALPHA + GAMMA * derivFunc(theta);
        
        theta -= velocity;
    }
    cout << "x = " << theta;
}
int main(int argc, char const *argv[])
{
    double x0 = 0;
    int n = 5000;
    GDwithMomentum(x0, n);
    return 0;
}
