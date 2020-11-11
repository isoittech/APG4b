#include <bits/stdc++.h>
using namespace std;

int main()
{
  // https://atcoder.jp/contests/abc084/tasks/abc084_a
  // 12月30日のM時から次の年になるまでは何時間か、求めてください。
  // 制約：1≦M≦23。入力は全て整数
  int M = 0;
  cout << "M= ";
  cin >> M;
  cout << (24 - M) + 24 << endl;
}