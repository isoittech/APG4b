#include <bits/stdc++.h>
using namespace std;

int main()
{
  // https://atcoder.jp/contests/abc085/tasks/abc085_b
  // ■ 問題文
  // X段重ねの鏡餅(X≥1)とは、X枚の円形の餅を縦に積み重ねたものであって、
  // どの餅もその真下の餅より直径が小さい（一番下の餅を除く）もののことです。
  // 例えば、直径10、8、6センチメートルの餅をこの順に下から積み重ねると
  // 3段重ねの鏡餅になり、餅を一枚だけ置くと1段重ねの鏡餅になります。
  // ダックスフンドのルンルンはN枚の円形の餅を持っていて、
  // そのうちi枚目の餅の直径はdiセンチメートルです。
  // これらの餅のうち一部または全部を使って鏡餅を作るとき、
  // 最大で何段重ねの鏡餅を作ることができるでしょうか。
  //
  // ■ 制約
  // 1≤N≤100
  // 1≤di≤100
  // 入力値はすべて整数である。
  //
  // ■ 入力
  // 入力は以下の形式で標準入力から与えられる。
  // N
  // d1
  // :
  // dN
  //
  // ■ 出力
  // 作ることのできる鏡餅の最大の段数を出力せよ。

  int N;
  vector<int> tsumareruMochi;

  cout << "餅の枚数：";
  cin >> N;
  vector<int> chokkeiDatas(N);

  cout << "餅の直径を" << N << "コ入力してください" << endl;
  for (int i = 0; i < N; i++)
  {
    cout << i + 1 << "個目：";
    cin >> chokkeiDatas.at(i);
  }

  for (int i = 0; i < N; i++)
  {
    bool tsumuFlg = true;
    for (int j = 0; j < tsumareruMochi.size(); j++)
    {
      if (chokkeiDatas.at(i) == tsumareruMochi.at(j))
      {
        tsumuFlg = false;
        break;
      }
    }
    if (tsumuFlg)
      tsumareruMochi.push_back(chokkeiDatas.at(i));
  }

  cout << "答え（餅の段数）:" << tsumareruMochi.size() << endl;
}