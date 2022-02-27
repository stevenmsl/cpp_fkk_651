#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol651;

/*
 Example 1:
 Input: N = 3
 Output: 3
 Explanation:
     We can at most get 3 A's on screen by pressing following key sequence:
     A, A, A
*/
tuple<int, int>
testFixture1()
{
  return make_tuple(3, 3);
}

/*
 Example 2:
 Input: N = 7
 Output: 9
 Explanation:
     We can at most get 9 A's on screen by pressing following key sequence:
     A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
*/

tuple<int, int>
testFixture2()
{
  return make_tuple(7, 9);
}
void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::maxA(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << to_string(get<1>(f)) << endl;
  auto result = Solution::maxA(get<0>(f));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}