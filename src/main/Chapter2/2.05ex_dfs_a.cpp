#include <bits/stdc++.h>
using namespace std;

// ■ 問題文
// 高橋君の住む街は長方形の形をしており、格子状の区画に区切られています。
// 長方形の各辺は東西及び南北に並行です。
// 各区画は道または塀のどちらかであり、高橋君は道を東西南北に移動できますが斜めには移動できません。
// また、塀の区画は通ることができません。
// 高橋君が、塀を壊したりすることなく道を通って魚屋にたどり着けるかどうか判定してください。
//
// ■ 入力
// 入力は以下の形式で標準入力から与えられる。
//   H W
//   c[0,0]   c[0,1]   ・・・ c[0,W−1]
//   c[1,0]   c[1,1]   ・・・ c[1,W−1]
//   :
//   c[H-1,0] c[H-1,1] ・・・ c[H-1,W−1]
//
// ・1 行目には、街の南北の長さとして整数 H ( 1 ≦ H ≦ 500 ) と
// 　東西の長さとして整数 W ( 1 ≦ W ≦ 500 ) が空白で区切られて与えられる。
// ・2 行目からの H 行には、格子状の街の各区画における状態 c[i,j] ( 0 ≦ i ≦ H − 1 , 0 ≦ j ≦ W − 1 ) が与えられる。
//  　・i 行目 j 文字目の文字 c i , j はそれぞれ s, g, ., # のいずれかで与えられ、座標 ( j , i ) が下記のような状態であることを表す。
//  　　・s : その区画が家であることを表す。
//  　　・g : その区画が魚屋であることを表す。
//  　　・. : その区画が道であることを表す。
//  　　・# : その区画が塀であることを表す。
// ・高橋君は家・魚屋・道は通ることができるが、塀は通ることができない。
// ・与えられた街の外を通ることはできない。
// ・s と g はそれぞれ 1 つずつ与えられる。
//
//  ■ 出力
//  塀を 1 回も壊さずに、家から魚屋まで辿り着くことができる場合は Yes、辿りつけない場合は No を標準出力に 1 行で出力せよ。

bool tansaku(vector<vector<char>> &machi, vector<vector<bool>> &machiVisited, int gx, int gy, int sx, int sy);

int main()
{
  int H, W;
  int sx, sy, gx, gy;
  cin >> H >> W;

  vector<vector<char>> machi(H, vector<char>(W));               // 街の区画配列
  vector<vector<bool>> machiVisited(H, vector<bool>(W, false)); // 街の区画探索済フラグ
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> machi.at(i).at(j);
    }
  }

  cout << endl;

  cout << "-----------------------" << endl;
  cout << "入力内容" << endl;
  cout << "-----------------------" << endl;
  for (int y = 0; y < H; y++)
  {
    for (int x = 0; x < W; x++)
    {
      cout << machi.at(y).at(x) << " ";
      if (machi.at(y).at(x) == 's')
      {
        sx = x;
        sy = y;
      }
      else if (machi.at(y).at(x) == 'g')
      {
        gx = x;
        gy = y;
      }
    }
    cout << endl;
  }
  cout << "-----------------------" << endl;
  cout << "SとGの座標" << endl;
  cout << "-----------------------" << endl;
  cout << "S:" << sx << ", " << sy << endl;
  cout << "G:" << gx << ", " << gy << endl;
  cout << endl;

  cout << "-----------------------" << endl;
  cout << "で、ゴールできるのか？" << endl;
  cout << "-----------------------" << endl;

  string result = "No...";
  if (tansaku(machi, machiVisited, gx, gy, sx, sy))
  {
    result = "YES!!";
  }
  cout << result << endl;
}

bool tansaku(vector<vector<char>> &machi, vector<vector<bool>> &machiVisited, int gx, int gy, int sx, int sy)
{
  // 終わる条件
  if (sx < 0 || sy < 0 || sy >= machi.size() || sx >= machi.at(0).size())
  {
    // ありえない座標だったら即終了
    return false;
  }
  else if (machiVisited.at(sy).at(sx))
  {
    // 調査済みだったら即終了
    return false;
  }
  else if (machi.at(sy).at(sx) == '#')
  {
    // 塀だったら即終了
    // 調査済フラグセット
    machiVisited.at(sy).at(sx) = true;
    return false;
  }
  else if (sx == gx && sy == gy)
  {
    // 目的地の座標と一致したらTrueを返却
    return true;
  }

  // 調査済フラグセット
  machiVisited.at(sy).at(sx) = true;

  // 現在の区画の四方の座標を再帰的に調べる。
  return tansaku(machi, machiVisited, gx, gy, sx - 1, sy)     //左方向
         || tansaku(machi, machiVisited, gx, gy, sx, sy - 1)  //上方向
         || tansaku(machi, machiVisited, gx, gy, sx + 1, sy)  //右方向
         || tansaku(machi, machiVisited, gx, gy, sx, sy + 1); //下方向
}