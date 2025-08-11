#include <cctype>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

pair<int, string> returnVowels(string name) {
  string vow = "";
  int count = 0;
  for (char c : name) {
    c = tolower(c);

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      count++;
      vow += c;
    }
  }
  return {count, vow};
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  string name;
  getline(cin, name); // used to input more than 1 string

  auto result = returnVowels(name);
  cout << "Count: " << result.first << endl;
  cout << "Vowels: " << result.second << endl;
}