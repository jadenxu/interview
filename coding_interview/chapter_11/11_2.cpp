#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string sort(string s) {
  vector<int> count(128, 0);
  for (int i = 0; i < s.length(); i++) {
    count[s[i]]++;
  }
  string new_s;
  for (int i = 0; i < 128; i++) {
    new_s += string(count[i], char(i));
  }
  return new_s;
}

void sort(vector<string>& v) {
  unordered_map<string, vector<string> > mp;
  unordered_map<string, vector<string> >::iterator it;
  for (int i = 0; i < v.size(); i++) {
    string tmp = sort(v[i]);
    it = mp.find(tmp);
    if (it == mp.end()) {
      mp.insert(pair<string, vector<string> >(tmp, vector<string>(1, v[i])));
    } else {
      it->second.push_back(v[i]);
    }
  }
  v.clear();
  for (it = mp.begin(); it != mp.end(); it++) {
    vector<string> tmp_v = it->second;
    v.insert(v.end(), tmp_v.begin(), tmp_v.end());
  }
}

int main () {
  int n;
  cin>>n;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin>>v[i];
  }
  sort(v);
  for (int i = 0; i < v.size(); i++) {
    cout<<v[i]<<endl;
  }
  
  return 0;
}
