#include <bits/stdc++.h>
using namespace std;

int main()
{

  // 問題文
  // 5つの要素からなる配列が与えられます。
  // 同じ値の要素が隣り合っているような箇所が存在するかどうかを判定してください。
  // 存在するなら"YES"を、存在しなければ"NO"を出力してください。

  vector<int> data(5);
  for (int i = 0; i < 5; i++)
  {
    cin >> data.at(i);
  }

  // dataの中で隣り合う等しい要素が存在するなら"YES"を出力し、そうでなければ"NO"を出力する
  // ここにプログラムを追記

  bool result = false;
  for (int i = 1; i < 5; i++)
  {
    if (data.at(i) == data.at(i - 1))
    {
      result = true;
      break;
    }
  }

  if (result)
    cout << "YES!" << endl;
  else
    cout << "NOOOOO" << endl;
}