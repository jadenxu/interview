#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > subset_1(vector<int> nums) {
  vector<vector<int> > v;
  for (int i = 0; i < (1 << nums.size()); i++) {
    vector<int> tmp_v;
    for (int j = 0; j < nums.size(); j++) {
      if (i & (1 << j)) {
        tmp_v.push_back(nums[j]);
      }
    }
    v.push_back(tmp_v);
  }

  return v;
}

void subset_help(
  vector<int>& nums, int index, 
  vector<int>& cur, vector<vector<int> >& total) {
  if (index == nums.size()) {
    total.push_back(cur);
    return;
  }
  
  cur.push_back(nums[index]);
  subset_help(nums, index + 1, cur, total);
  cur.pop_back();
  subset_help(nums, index + 1, cur, total);
}

vector<vector<int> > subset_2(vector<int> nums) {
  vector<vector<int> > total;
  vector<int> cur;
  subset_help(nums, 0, cur, total);

  return total;
}

int main() {
  int n;
  cin>>n;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin>>nums[i];
  }

  vector<vector<int> > v = subset_2(nums);
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].size(); j++) {
      cout<<v[i][j]<<" ";
    }
    cout<<endl;
  }
}
