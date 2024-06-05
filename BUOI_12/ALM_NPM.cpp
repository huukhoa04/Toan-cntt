#include <bits/stdc++.h>
using namespace std;
#define EPS 0.01
struct BigX
{
    double x1,x2;
};
#define BIG_X BigX
//hàm chính
double Func(BIG_X a)
{
    double term1 = 6 * a.x1 * a.x1;
    double term2 = 4 * a.x1 * a.x2;
    double term3 = 3 * a.x2 * a.x2;
    return term1 + term2 + term3;
}
//hàm h
double hFunc(BIG_X a)
{
    return a.x1 + a.x2 - 5;
}
double lagrangeFunc(BIG_X a, double lambda, double r)
{
    return 0;
}
BIG_X calcX(double lambda, double r)
{
    BIG_X temp;
    //tính x1
    double term1 = -90 * r * r + 9 * r * lambda - 6 * lambda + 60 * r;
    double term2 = (14 - 5 * r) * (12 + 2 * r);
    //tính x2
    temp.x1 = term1/term2;
    term1 = 20 * r - 2 * lambda;
    term2 = 14 - 5 * r;
    temp.x2 = term1/term2;
    return temp;
}
void ALM_NPM(BIG_X a, double lambda, double r)
{
    BIG_X input_X = a;
    double input_Lambda = lambda;
    double h = 0;
    cout << "lambda" << "\t\t\t" << "r" << "\t\t\t" << "x1(j)" << "\t\t\t" << "x2(j)" << "\t\t\t" << "h value" << "\n";

    do
    {
        input_X = calcX(input_Lambda, r);
        h = hFunc(input_X);
        input_Lambda += 2*r*h;
        cout << setprecision(6) << input_Lambda << "\t\t\t" << r << "\t\t" << input_X.x1 << "\t\t" << input_X.x2 << "\t\t" << h << "\n";
    }while(fabs(h) > 0.01);

}
int main(int argc, char const *argv[])
{
    BIG_X init;
    init.x1 = 0;
    init.x2 = 0;
    double r = 1;
    double init_lambda = 0;
    ALM_NPM(init, init_lambda, r);
    return 0;
}

