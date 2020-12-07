#include <gtest/gtest.h>
#include <vector>
#include <string>

template <class T>
struct Erase_params {
// исходные элементы
std::vector<T> elements;
// начальный индекс, с которого начинается удаление элементов
size_t start_index;
// конечный индекс, на котором заканчивается удаление элементов
size_t end_index;
// элементы, которые останутся в векторе после удаления
std::vector<T> result;
};

class param_test: public ::testing::TestWithParam<Erase_params<int>> {};


TEST_P(param_test, _) {
const Erase_params<int>& param = GetParam();
/*for (const auto& x: param.elements)
	std::cout << x << " ";
std::cout << std::endl;
std::cout << param.start_index << std::endl;
std::cout << param.end_index << std::endl;
for (const auto& x: param.result)
        std::cout << x << " ";
std::cout << std::endl;*/
std::vector<int> tst = param.elements;
std::vector<int> expected = param.result;
tst.erase(tst.begin() + param.start_index, tst.begin() + param.end_index);
EXPECT_EQ(tst, expected);
}

INSTANTIATE_TEST_CASE_P(
	_,
	param_test,
	::testing::Values(
		Erase_params<int>{
			{1, 2, 3, 4, 5},
			1,
			3,
			{1, 4, 5}
		},
		Erase_params<int>{
			{1, 2, 3, 4, 5},
			0,
			5,
			{}
		},

		Erase_params<int>{
                        {1, 2, 3, 4, 5},
                        4,
                        5,
                        {1, 2, 3, 4}
                }
	)
);









