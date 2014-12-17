#include <iostream>
using namespace std;


//Solution of  the nonhomogeneous-linear equations by dichotomy
inline double func(double ans) //.. equation is 2*x*x*x - 4*x*x + 3*x - 6
{
    return 2 * ans * ans * ans - 4 * ans * ans + 3 * ans - 6;
}

inline double fabs(double res)
{
    return res > 0 ? res : -res;
}

double dichotomy(double low, double high)
{
    double mid = low + (high - low)/2.0;
    
    while ((high - low) > 1e-4 && fabs(func(mid)) > 1e-4)
    {
        mid = low + (high - low) /2;
        if (func(mid) > 0)
            high = mid;
        else
            low = mid;
    }
    return mid;
}
//...The end of solution


//Soution of the nohomogeneous-linear equations by Newton's method
inline double derFunc(double ans)
{
    return 6 * ans * ans - 8 * ans + 3;
}

double newtonMethod(double guess, double precision, int maxCycle)
{
    double initans = guess, ans = initans;
    for (int i = 0; i < maxCycle; i++)
    {
        if (derFunc(initans) == 0.0)
            return initans;
        ans = initans - func(initans) / derFunc(initans);
        if((fabs(ans-initans) < precision)||(fabs(func(ans)) < precision))
        {
            return ans;
        }
        else
            initans = ans;
    }
    printf("Cycles exceeds\n");
    return ans;
}
//..The end of solution


int main()
{
    cout << dichotomy(-10, 10)<<endl;
    cout << newtonMethod(3, 1e-4, 100)<<endl;
    return 0;
}