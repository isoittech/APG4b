#include <bits/stdc++.h>
using namespace std;

int main()
{
  // https://atcoder.jp/contests/abc081/tasks/abc081_b
  // 問題文
  // 黒板にN個の正の整数A1,...,ANが書かれています．
  // すぬけ君は，黒板に書かれている整数がすべて偶数であるとき，次の操作を行うことができます．
  // ・黒板に書かれている整数すべてを，2で割ったものに置き換える．
  // すぬけ君は最大で何回操作を行うことができるかを求めてください．
  //
  // 制約
  // 1≤N≤200
  // 1≤Ai≤10^9
  //
  // 入力
  // 入力は以下の形式で標準入力から与えられる。
  // N
  // A1 A2 ... AN
  //
  // 出力
  // すぬけ君は最大で何回操作を行うことができるかを出力せよ．

  int N, count = 0;
  int *vals;
  bool stopFlg;

  cout << "整数の個数：";
  cin >> N;
  vals = new int[N];

  cout << "整数を" << N << "コ入力してください" << endl;
  for (int i = 0; i < N; i++)
  {
    cout << i + 1 << "個目：";
    cin >> vals[i];
  }

  while (true)
  {
    if (stopFlg)
      break;

    cout << "[" << count + 1 << "] ";
    for (int i = 0; i < N; i++)
    {
      if (vals[i] % 2 != 0)
      {
        stopFlg = true;
      }
      cout << vals[i] << " ";
      vals[i] /= 2; // 次のループで処理する値準備
    }
    cout << endl;

    if (!stopFlg)
      count++;
  }

  cout << "答え:" << count << endl;

  delete[] vals;
}