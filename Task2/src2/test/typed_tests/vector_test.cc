#include <gtest/gtest.h>
#include <vector>
#include <fstream>

typedef float type1;
typedef std::string type2;
typedef std::ofstream type3;

template<typename T>
struct PushBack: public ::testing::Test {
};

template<typename T>
struct PushBackOfstream: public ::testing::Test {
};

template<typename T> T random_address() {};

template<> float random_address<float>() {
	return float(100.2);
}

template<> std::string random_address<std::string>() {
    return "abacaba";
}

template<> std::ofstream random_address<std::ofstream>() {
    std::ofstream out("test.txt");
    return out;
}

using test_types1 = ::testing::Types<type1, type2>;
using test_types2 = ::testing::Types<type3>;

//bool operator==(const type3& lhs, const type3& rhs) {
//  return lhs.is_open() && rhs.is_open();
//}

TYPED_TEST_CASE(PushBack, test_types1);

TYPED_TEST(PushBack, _){
TypeParam obj = random_address<TypeParam>();
std::vector<TypeParam> vv;
vv.push_back(obj);
EXPECT_EQ(vv[0], obj);
}

TYPED_TEST_CASE(PushBackOfstream, test_types2);

TYPED_TEST(PushBackOfstream, ofstream){
TypeParam obj = random_address<TypeParam>();
std::vector<TypeParam> vv;
// используется вариант с void push_back( T&& value ),
//т.к конструктор копирования для ofstream явно удалён:
//ofstream (const ofstream&) = delete;
vv.push_back(std::move(obj));
EXPECT_EQ(vv[0].is_open(), true);
}
