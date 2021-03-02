#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int count = 0;
  deque<int> stack;

  cin >> count;
  cin.ignore();

  while(count--) {
    string order;
    getline(cin, order);
    
    switch(order[0]) {
      case 'p':
        if (order[1] == 'u') {
          int num = stoi(order.substr(5));
          stack.push_front(num);
        } else {
          if (!stack.empty()) {
            cout << stack.front() << "\n";
            stack.pop_front();
          } else {
            cout << -1 << "\n";
          }
        }
        break;
      case 's':
        cout << stack.size() << "\n";
        break;
      case 'e':
        if(!stack.empty()) {
          cout << "0\n";
        } else {
          cout << "1\n";
        }
        break;
      case 't':
        if(!stack.empty()) {
          cout << stack.front() << "\n";
        } else {
          cout << -1 << "\n";
        }
        break;
    }
  }
  return 0;
}