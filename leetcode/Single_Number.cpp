class Solution {
public:
  int singleNumber(int A[], int n) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    int result = 0;
    for(int i = 0; i < n; i++) {
      result ^= A[i];
    }

    return result;
  }
};
