#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int temp = 12;
    int m = temp / 1000;
    temp = (temp % 1000) * 10 + m;

    cout << m << endl;
    cout << temp << endl;

    int temp2 = 1;
    int m2 = (temp2 % 10) * 1000;
    temp2 = (temp2 / 10) + m2;

    cout << m2 << endl;
    cout << temp2 << endl;   
}

/*
int L(int a) {
	int m = a/1000;
	a = (a % 1000) * 10 + m;
	return a;
}
int R(int a) {
	int m = (a % 10) * 1000;
	a = (a / 10) + m;
	return a;
}
*/