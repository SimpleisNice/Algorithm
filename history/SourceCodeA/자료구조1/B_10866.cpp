#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int count = 0;
  deque<int> tempQ;
  cin >> count;
  cin.ignore();

  while(count--) {
    string order;
    getline(cin, order);

    switch(order[0]) {
      case 'p':
        if(order[1] == 'u') {
          int num = stoi(order.substr(10));
          if (order[5] == 'f') {
            tempQ.push_front(num);
          } else {
            tempQ.push_back(num);
          }
        } else {
          if (!tempQ.empty()) {
            if (order[4] == 'f') {
              cout << tempQ.front() << '\n';
              tempQ.pop_front();
            } else {
              cout << tempQ.back() << '\n';
              tempQ.pop_back();
            }
          } else {
            cout << -1 << '\n';
          }
        }
        break;
      case 's':
        cout << tempQ.size() << '\n';
        break;
      case 'e':
        if (tempQ.empty()) {
          cout << 1 << '\n';
        } else {
          cout << 0 << '\n';
        }
        break;
      case 'f':
        if (!tempQ.empty()) {
          cout << tempQ.front() << '\n';
        } else {
          cout << -1 << '\n';
        }
        break;
      case 'b':
        if (!tempQ.empty()) {
          cout << tempQ.back() << '\n';
        } else {
          cout << -1 << '\n';
        }
        break;
    }
  }
  return 0;
}