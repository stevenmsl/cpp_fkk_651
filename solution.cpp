#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol651;
using namespace std;

/*takeaways
  - We have a benchmark by pressing 'A' n consecutive times to
    produce n A's.

  - we then exhaust all combinations to see if any combination
    can produce more A's than the benchmark
    - we start from 1 A's and build it up all the way to n-3 A's
      - why n-3? You need to reserve at least 3 key strokes
        for Ctrl-A, Ctrl-C, and Ctrl-V to produce additional A's
      - 1 A's -> dp[1] + dp[1] * (n-1-2)
        ...
      - k A's -> dp[k] + dp[k] * (n-k-2)
        - n-k-2 is the number of times you press Ctrl-V
        - k steps used to produce dp[k], and 2 steps used for Ctrl-A
          and Ctrl-C. So only n-k-2
        - don't forget to add dp[k] to it - this can be missed easily

  - example: n = 5
    - you can produce at least 5 A's by just pressing 'A'
      5 times. So other options need to do better than
      this
    - whenever you press Ctrl-A and Ctrl-C, you are losing
      two A's and also using up two steps
    - press A, Ctrl-A, Ctrl-C, Ctrl-V, Ctrl-V
      AAA <- you can only produce 3 A's
    - press A, A, Ctrl-A, Ctrl-C, Ctrl-V
      AAAA <- you can only produce 4 A's
    - press A, A, A, Ctrl-A, Ctrl-C
      AAA
      - you just wasted two steps and not producing any
        more A's
      - so you at most can press A up to n-3 times to
        have a chance to produce more A's as you need
        (Ctrl-A, Ctrl-C, and at least one Ctrl-V)

*/
int Solution::maxA(int n)
{
  /*
    - use 1-based for easier coding
    - dp[i] is the max A's i steps
      can produce exhausting all
      combinations
  */
  auto dp = vector<int>(n + 1, 0);

  for (auto i = 1; i <= n; i++)
  {
    /*benchmark
      - you can produce at least i A's
        in i steps
    */
    dp[i] = i;
    /* check other alternatives
       - you can only go up to i - 3 as you need at
         least Ctrl-A, Ctrl-C, and Ctrl-V to have
         a chance to produce more A's
    */
    for (auto j = 1; j <= i - 3; j++)
      /* you can press Ctrl-V for i-j-2 times
         so it's dp[j] * (i-j-2), plus what dp[j]
         already has.
      */
      dp[i] = max(dp[i], dp[j] + dp[j] * (i - j - 2));
  }

  return dp[n];
}