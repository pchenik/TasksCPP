#include <gtest/gtest.h>
#include <my_vector/my_vector.hh>

TEST(PushBack, rvalue) {
    Vector<int> vv = {1, 2, 3};
    vv.PushBack(4);
    Vector<int> ans = {1, 2, 3, 4};
    EXPECT_EQ(vv, ans);
}

TEST(PushBack, lvalue) {
    Vector<std::string> vv = {"Minsk", "Munchen", "Glasgow"};
    std::string ss = "Stockholm";
    vv.PushBack(ss);
    EXPECT_EQ(vv.Back(), ss);
}

TEST(PopBack, _) {
    Vector<int> vv = {1, 2, 3};
    vv.PopBack();
    Vector<int> ans = {1, 2};
    EXPECT_EQ(vv, ans);
}

TEST(Erase, _) {
    Vector<std::string> vv = {"Minsk", "Munchen", "Glasgow"};
    vv.Erase(std::find(vv.begin(), vv.end(), "Munchen"));
    Vector<std::string> ans = {"Minsk", "Glasgow"};
    EXPECT_EQ(vv, ans);
}

TEST(Begin, _) {
    Vector<float> vv = {0.1, 0.2};
    float ans = 0.1;
    EXPECT_EQ(*vv.begin(), ans);
}

TEST(End, _) {
    Vector<float> vv = {0.1, 0.2};
    float ans = 0.2;
    auto it = std::prev(vv.end());
    EXPECT_EQ(*it, ans);
}

TEST(Size, _) {
    Vector<long long> vv = {1ll, 1000000000000ll, 8ll};
    EXPECT_EQ(3u, vv.Size());
    vv.PopBack();
    vv.PushBack(1ll << 32);
    EXPECT_EQ(3u, vv.Size());
}

TEST(Constructor, _) {
    Vector<int> v1 = {1, 2, 3, 4, 5};
    Vector<int> v2(v1);
    EXPECT_EQ(v1, v2);
}

TEST(Move_constructor, _) {
    Vector<int> v1({1, 2, 3});
    Vector<int> ans = {1, 2, 3};
    EXPECT_EQ(v1, ans);
    Vector<int> v2 = std::move(v1);
    EXPECT_EQ(v2, ans);
    EXPECT_EQ(1, v1.Empty());
}

TEST(Assignment, _) {
    Vector<int> v1({1, 2, 3});
    Vector<int> v2;
    v2 = v1;
    int sum = 0;
    for(int x: v2)
    sum += x;
    EXPECT_EQ(6, sum);
}

TEST(_move_assignment, _) {
    Vector<int> v1 = {4, 5, 6, 7};
    Vector<int> v2;
    v2 = std::move(v1);
    EXPECT_EQ(4, v2.Size());
    EXPECT_EQ(0, v1.Size());
}
