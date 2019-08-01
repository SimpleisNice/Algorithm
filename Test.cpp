#include <iostream>
using namespace std;


int main(void)
{
    bool check[1001];
    int check2[1001];
    cout << sizeof(check) << endl;

    cout << sizeof(check) / sizeof(check[0]) << endl;

    cout << sizeof(check2) << endl;

    cout << sizeof(check2) / sizeof(check2[0]) << endl;
    return 0;
}