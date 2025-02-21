#include <iostream>

using namespace std;

unsigned long adler32(string &data)
{
    const unsigned long MOD_ADLER = 65521;
    unsigned long a = 1, b = 0;
    for (char c : data)
    {
        a = (a + c) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }
    return (b << 16) | a;
}
unsigned long hashDJB2(string str)
{
    unsigned long hash = 5381;
    for (char c : str)
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % 1000;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        cout << hashDJB2(s) << " ";
    }
}