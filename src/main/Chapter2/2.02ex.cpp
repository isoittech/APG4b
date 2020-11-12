#include <bits/stdc++.h>
using namespace std;

// 問題文
// ある果物屋では、リンゴ・パイナップルがそれぞれN個売られています。
// i個目のリンゴ、パイナップルはそれぞれAi円、Pi円です。
// リンゴ・パイナップルをそれぞれ1つずつ選んで購入しようとするとき、
// 合計金額が丁度S円になるような買い方が何通りあるか求めてください。
// ただし、同じ値段の同じ種類の商品でも区別します。
// たとえば同じ値段のリンゴが複数あった場合、それらを買う場合は別の買い方として数えます。
// パイナップルについても同様です。また、リンゴ・パイナップルを買う順番は考慮しないものとします。

int main()
{
  int N, S;
  cin >> N >> S;
  vector<int> A(N), P(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    cin >> P.at(i);
  }

  // リンゴ・パイナップルをそれぞれ1つずつ購入するとき合計S円になるような買い方が何通りあるか
  // ここにプログラムを追記
  int count = 0;
  for (int ringo : A)
  {
    for (int pinapple : P)
    {
      cout << ringo << " + " << pinapple << "--> ";
      if ((ringo + pinapple) == S)
      {
        cout << "YES!" << endl;
        count++;
      }
      else
      {
        cout << "NO!" << endl;
      }
    }
  }

  cout << "答え：" << count << "個" << endl;
}
