#include <gtest/gtest.h>
#include <vector>

using namespace std;

TEST(vector, PushBack) {
        vector<int> vv = {1, 2, 3};
        vv.push_back(4);
        vector<int> ans = {1, 2, 3, 4};
        EXPECT_EQ(vv, ans);
}

TEST(vector, PopBack) {
	vector<int> vv = {1, 2, 3};
        vv.pop_back();
        vector<int> ans = {1, 2};
        EXPECT_EQ(vv, ans);
}

TEST(vector, Erase) {
	vector<string> vv = {"Moscow", "Munchen", "Glasgow"};
	vv.erase(find(vv.begin(), vv.end(), "Munchen"));
	vector<string> ans = {"Moscow", "Glasgow"};
	EXPECT_EQ(vv, ans);
}

TEST(vector, Begin) {
	vector<float> vv = {0.1, 0.2};
	float ans = 0.1;
	EXPECT_EQ(*vv.begin(), ans);
}

TEST(vector, End) {
        vector<float> vv = {0.1, 0.2};
        float ans = 0.2;
	auto it = prev(vv.end());
        EXPECT_EQ(*it, ans);
}

TEST(vector, Size) {
	vector<long long> vv = {1ll, 1000000000000ll, 8ll};
	EXPECT_EQ(3u, vv.size());
	vv.pop_back();
	vv.push_back(1ll << 32);
	EXPECT_EQ(3u, vv.size());
}

TEST(vector, constructor) {
	vector<int> v1 = {1, 2, 3, 4, 5};
	vector<int> v2(v1);
	EXPECT_EQ(v1, v2);
}

TEST(vector, move_constructor) {
	vector<int> v1({1, 2, 3});
	vector<int> ans = {1, 2, 3};
	EXPECT_EQ(v1, ans);
	vector<int> v2 = move(v1);
	EXPECT_EQ(v2, ans);
	EXPECT_EQ(1, v1.empty());
}

TEST(vector, assignment) {
	vector<int> v1 = {1, 2, 3};
	vector<int> v2 = v1;
	int sum = 0;
	for(int x: v2)
		sum += x;
	EXPECT_EQ(6, sum);
}

TEST(vector, move_assignment) {
	vector<int> v1 = {4, 5, 6, 7};
	vector<int> v2 = move(v1);
	EXPECT_EQ(4, v2.size());
	EXPECT_EQ(0, v1.size());
}
