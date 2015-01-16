#include <iostream>
using namespace std;

bool reverse(char* s, int start, int end)
{
    char tmp = '0';
    int mid = start + (end - start) /2;
    while (start < end)
    {
        tmp = s[start];
        s[start++] = s[end];
        s[end--] = tmp;
    }
    return true;
}


int main()
{
    char s[] = "abcd";
    reverse(s);
    cout << s <<endl;
}