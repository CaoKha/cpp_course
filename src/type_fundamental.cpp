#include <iostream>
using namespace std;

int main()
{
    char c = 'c'; // 1octet = 8bits
    wchar_t wc = 'c';
    short s = 4; //16bits
    int i = 5;
    long l = 6;
    long long ll = 7;
    float f = 6.7;
    double d = 6.7;
    long double ld = 6.7;
    bool b = true;

    /* 
    1 <= sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)
    1 <= sizeof(bool) <= sizeof(long)
    1 <= sizeof(char) <= sizeof(wchar_t) <= sizeof(long)
    1 <= sizeof(N) = sizeof(signed N) = sizeof(unsigned N)
 */
    //errors appear before warning
    cout << "Size of char : " << sizeof(char) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
    cout << "Size of short : " << sizeof(short) << endl;
    cout << "Size of long : " << sizeof(long) << endl;
    cout << "Size of long long: " << sizeof(long long) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of long double : " << sizeof(long double) << endl;
    cout << "Size of bool : " << sizeof(bool) << endl;
}