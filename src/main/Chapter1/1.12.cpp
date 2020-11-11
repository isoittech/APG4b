#include <bits/stdc++.h>
using namespace std;

int main()
{
  string str = "Hello";
  cout << str.size() << endl; // 5
  // cout << "Hello"s.size() << endl; // 5（sを末尾につける） // 出来るらしいが出来ないじゃん。
  // cout << "Hello".size() << endl; // できない

  cout << "こんにちは\nAtCoder" << endl;

  string s, t;
  getline(cin, s); // 変数sで入力を一行受け取る
  getline(cin, t); // 変数tで入力を一行受け取る

  cout << "一行目 " << s << endl;
  cout << "二行目 " << t << endl;
}
