#include <bits/stdc++.h>
using namespace std;

int main()
{
  int p;
  int price;
  string text;

  cin >> p;
  cout << "pattern:" << p << endl;

  // パターン1
  if (p == 1)
  {
    cin >> price;
  }

  // パターン2
  if (p == 2)
  {
    cin >> text >> price;
    cout << "text:" << text << endl;
  }

  cout << "price:" << price << endl;

  int N;
  cin >> N;

  // パターン2
  if (p == 2)
  {
    cout << text << "!" << endl;
  }

  cout << "set:" << N << endl;

  cout << price * N << endl;
}
