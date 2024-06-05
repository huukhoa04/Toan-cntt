#include <bits/stdc++.h>
using namespace std;
#define MAX 100000000
struct Element
{
    long long value;
    int count;
};
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
class Number
{
    private:
        long long N_number;
        vector<Element> Memory;
        // long long sieve[MAX];
    public:
        Number(long long a): N_number(a), Memory(){};

        long long& getN_number()
        {
            return this->N_number;
        }

        void setN_number(long long& a)
        {
            N_number = a;
        }
        vector<Element>& getMemory()
        {
            return this->Memory;
        }
        void factorize()
        {
            Memory.clear();
            int count = 0;
            long long n;
            n = getN_number();
                while (!(n % 2)) 
                {
                    n = n/2; 
                    count++;
                }

                if (count)
                {
                    // cout << 2 << "^" << count;
                    struct Element A;
                    A.count = count;
                    A.value = 2;
                    Memory.push_back(A);
                }
                for (long long i = 3; i <= sqrt(n); i += 2)
                {
                    count = 0;
                    while (n % i == 0) {
                        count++;
                        n = n / i;
                    }
                    if (count){
                        struct Element A;
                        A.count = count;
                        A.value = i;
                        Memory.push_back(A);
                        // cout << "*" << i << "^" << count << endl;
                    }
                }

                if (n > 2)
                {
                    // cout << n << " " << 1 << endl;
                        struct Element A;
                        A.count = 1;
                        A.value = n;
                        Memory.push_back(A);
                }
        }
        int numberOfFactor()
        {
            factorize();
            int S = 1 ;
            for (int i = 0; i< Memory.size(); i++)
            {
                S *= (Memory.at(i).count + 1);
            }
            return S;
        }

        

        long long sumOfFactor()
        {
            factorize();
            long long S = 1;
            for (int i = 0; i< Memory.size(); i++)
            {
                struct Element temp = Memory.at(i);
                S *= (pow(temp.value, temp.count + 1) - 1) / (temp.value - 1);
            }
            return S;
        }

        long long productOfFactor()
        {
            return pow(this->N_number, numberOfFactor()/2);
        }

        bool isPerfect()
        {
            return this->N_number == sumOfFactor() - this->N_number;
        }

        double densityOfPrimes()
        {
            return (this->N_number/log(this->N_number));
        }
        void SieveOfEratosthenes(int selected)
        {
            cout << "List of " << this->N_number << "'s Primes: ";
            bool prime[this->N_number + 1];
            memset(prime, true, sizeof(prime));
        
            for (int p = 2; p * p <= this->N_number; p++) {
                // If prime[p] is not changed, then it is a prime
                if (prime[p] == true) {
                    // Update all multiples of p greater than or
                    // equal to the square of it numbers which are
                    // multiple of p and are less than p^2 are
                    // already been marked.
                    for (int i = p * p; i <= this->N_number; i += p)
                        prime[i] = false;
                }
            }
        
            // Print all prime numbers
            for (int p = selected; p <= this->N_number; p++)
                if (prime[p])
                    cout << p << " ";
        }
        long long nearest_prime(){

            if (is_prime(this->N_number)) {
            return this->getN_number();
            }
            long long lower = this->getN_number() - 1;
            while (!is_prime(lower)) {
            lower -= 1;
            }
            long long upper = this->getN_number() + 1;
            while (!is_prime(upper)) {
            upper += 1;
            }
            return abs(this->getN_number() - lower) < abs(this->getN_number() - upper) ? lower : upper;
        }


};
int main()
{
    long long a;
    cout << "Nhap n = "; cin >> a; getchar();

    Number A(a);
    char choice = '0';
    while(choice != '9')
    {
        cout << "\nOption for number: " << A.getN_number() << "\n";
        cout << "1. Factorize given number\n";
        cout << "2. Print number of factors of given number\n";
        cout << "3. Print summary of all factors of given number\n";
        cout << "4. Print Product of all factors of given number\n";
        cout << "5. Check if this number is perfect\n";
        cout << "6. Print Density o' prime of given number\n";
        cout << "7. Using Sieve Of Eratosthenes to find all prime factor between selected number and given number\n";
        cout << "8. Find nearest Prime number of given number\n";
        cout << "9. Quit\n";
        
        cout << "enter ur choice: "; cin >> choice; getchar();

        switch (choice)
        {
        case('1'): 
        {
            A.factorize();
            cout << A.getN_number() << " = ";
            for (int i = 0; i< A.getMemory().size(); i++)
            {                
                cout << A.getMemory().at(i).value << "^" << A.getMemory().at(i).count << " x ";
            }
            break;
        }
        case('2'): 
        {
            int a = A.numberOfFactor();
            cout << "number of factors: " << a << "\n";
            break;
        }
        case('3'): 
        {
            long long  a = A.sumOfFactor();
            cout << "sum of factors: " << a << "\n";
            break;
        }
        case('4'): 
        {
            long long a = A.productOfFactor();
            cout << "product of factors: " << a << "\n";
            break;
        }
        case('5'): 
        {
            cout << "This number is " << ((A.isPerfect() == 1)? "perfect" : "not perfect");
            break;
        }
        case('6'): 
        {
            cout << "density of prime: " << setprecision(0) << fixed << A.densityOfPrimes();
            break;
        }
        case('7'): 
        {
            long long select;
            cout << "input your desired starting number (2 <= x < n): "; cin >> select;
            A.SieveOfEratosthenes(select);
            break;
        }
        case('8'):
        {
            cout << "nearest prime number of " << A.getN_number() << ": " << A.nearest_prime();
            break;
        }
        case('9'):
        {
            cout << "Quitting...";
            continue;
        }
        
        default:
        {
            cout << "INVALID VALUE!\n";
            break;
        }
        }
    }
}