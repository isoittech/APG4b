#include <bits/stdc++.h>
using namespace std;

int main()
{
  // https://atcoder.jp/contests/abc079/tasks/abc079_a
  // Good Integer
  // 問題文
  // 1118 のような、 3 つ以上の同じ数字が連続して並んだ 4 桁の整数を 良い整数 とします。
  // 4 桁の整数 N が与えられるので、 N が 良い整数 かどうかを答えてください。
  //
  // 制約
  // 1000 ≦ N ≦ 9999
  // 入力は整数からなる
  //
  // 入力
  //   入力は以下の形式で標準入力から与えられる。
  // N
  //
  // 出力
  // N が 良い整数 ならば Yes を、そうでなければ No を出力せよ。

  string N, result = "No";
  cout << "4桁の整数を入力せよ:";
  cin >> N;

  if (N[0] == N[1])
  {
    if (N[1] == N[2])
    {
      result = "Yes";
    }
  }
  else
  {
    if (N[1] == N[2])
    {
      if (N[2] == N[3])
      {
        result = "Yes";
      }
    }
  }

  cout << result << endl;
}