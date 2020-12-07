#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(PushBack, Compare) {
	vector<int> vv = {1, 2, 3};
	vv.push_back(4);
	vector<int> ans = {1, 2, 3, 4};
	EXPECT_EQ(vv, ans);
}
