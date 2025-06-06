class Solution {
 public:
  int strongPasswordChecker(string password) {
    const int n = password.length();
    const int missing = getMissing(password);
    int replaces = 0;
    int oneSeq = 0;
    int twoSeq = 0;

    for (int i = 2; i < n;)
      if (password[i] == password[i - 1] &&
          password[i - 1] == password[i - 2]) {
        int length = 2; 
        while (i < n && password[i] == password[i - 1]) {
          ++length;
          ++i;
        }
        replaces += length / 3;  
        if (length % 3 == 0)
          ++oneSeq;
        if (length % 3 == 1)
          ++twoSeq;
      } else {
        ++i;
      }

    if (n < 6)
      return max(6 - n, missing);
    if (n <= 20)
      return max(replaces, missing);

    const int deletes = n - 20;
    replaces -= min(oneSeq, deletes);
    replaces -= min(max(deletes - oneSeq, 0), twoSeq * 2) / 2;
    replaces -= max(deletes - oneSeq - twoSeq * 2, 0) / 3;
    return deletes + max(replaces, missing);
  }

 private:
  int getMissing(const string& password) {
    return 3 -  //
           ranges::any_of(password, [](char c) { return isupper(c); }) -
           ranges::any_of(password, [](char c) { return islower(c); }) -
           ranges::any_of(password, [](char c) { return isdigit(c); });
  }
};


