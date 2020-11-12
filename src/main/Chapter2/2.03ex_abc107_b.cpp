#include <bits/stdc++.h>
using namespace std;

// https://atcoder.jp/contests/abc107/tasks/abc107_b
// B - Grid Compression

// ■ 問題文
// 縦 H 行、横 W 列のマス目があります。
// 上から i 行目、左から j 列目のマスを ( i , j ) と表します。
// 各マスは白または黒です。
// マス目の配色は、 H 行 W 列の行列 ( a i , j ) によって与えられます。
// a i , j が . ならばマス ( i , j ) は白であり、 a i , j が # ならばマス ( i , j ) は黒です。
// すぬけ君はこのマス目を圧縮しようとしています。
// そのために、白いマスのみからなる行または列が存在する間、次の操作を繰り返し行います。
// 　操作:
// 　・白いマスのみからなる行または列をひとつ任意に選び、その行または列を取り除いて空白を詰める。
// 各操作でどの行または列を選ぶかによらず、最終的なマス目は一意に定まることが示せます。
// 最終的なマス目を求めてください。

// ■ 制約
// 1 ≤ H , W ≤ 100
// a[i,j] は . または # である。
// マス目全体で少なくともひとつは黒いマスが存在する。

// ■ 入力
// 入力は以下の形式で標準入力から与えられる。
// H W
// a[1,1] . . . a[1,W]
// :
// a[H,1] . . . a[H,W]

// ■ 出力
// 最終的なマス目を、入力と同様のフォーマットで出力せよ。
// ただし、行数および列数は省くこと。 詳しくはサンプルを参照せよ。

int main()
{
  int H, W;

  cout << "マス目の縦と横のそれぞれの数をスペース区切りで入力してください：";
  cin >> H >> W;
  cout << "縦" << H << "個、横" << W << "個ですね。\n"
       << endl;

  vector<vector<char>> masume(H, vector<char>(W)); // 縦H x 横W の2次元配列

  cout << "次は横" << W << "個の#か.を、スペース区切りで入力してEnterし、それを縦" << H << "個分繰り返してください。"
       << endl;

  // int idx = 1;
  // for (vector<char> gyou : masume)
  for (int gyouIdx = 0; gyouIdx < H; gyouIdx++)
  {
    cout << gyouIdx << "行目：";
    // for (char mas : gyou)
    for (int colIdx = 0; colIdx < W; colIdx++)
      cin >> masume.at(gyouIdx).at(colIdx);
    // idx++;
  }
  cout << endl;

  cout << "-----------------------" << endl;
  cout << "入力内容" << endl;
  cout << "-----------------------" << endl;
  for (vector<char> gyou : masume)
  {
    for (char mas : gyou)
      cout << mas << " ";
    cout << endl;
  }

  cout << "-----------------------" << endl;
  cout << "行方向の処理後（空白行除去）" << endl;
  cout << "-----------------------" << endl;
  vector<vector<char>> tochuuKeika;
  for (vector<char> gyou : masume)
  {
    bool nokosuFlg = false;
    for (char mas : gyou)
    {
      if (mas == '#')
      {
        nokosuFlg = true;
        break;
      }
    }

    if (nokosuFlg)
      tochuuKeika.push_back(gyou);
  }

  for (vector<char> gyou : tochuuKeika)
  {
    for (char mas : gyou)
      cout << mas << " ";
    cout << endl;
  }

  cout << "-----------------------" << endl;
  cout << "最終的な答え" << endl;
  cout << "-----------------------" << endl;
  int chuukanGyou = tochuuKeika.size();
  int chuukanRetsu = tochuuKeika.at(0).size();

  vector<vector<char>> result(chuukanGyou); // この時点で行数は確定している

  for (int colIdx = 0; colIdx < chuukanRetsu; colIdx++)
  {

    bool retsuNokos = false;
    for (int rowIdx = 0; rowIdx < chuukanGyou; rowIdx++)
    {
      if (tochuuKeika.at(rowIdx).at(colIdx) == '#')
      {
        retsuNokos = true;
        break;
      }
    }

    if (retsuNokos)
    {
      for (int rowIdx = 0; rowIdx < chuukanGyou; rowIdx++)
      {
        result.at(rowIdx).push_back(tochuuKeika.at(rowIdx).at(colIdx));
      }
    }
  }

  for (vector<char> gyou : result)
  {
    for (char mas : gyou)
      cout << mas << " ";
    cout << endl;
  }
}
