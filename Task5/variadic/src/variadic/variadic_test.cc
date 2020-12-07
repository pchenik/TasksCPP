#include <gtest/gtest.h>
#include <variadic/variadic.hh>

TEST(Tie, _) {
    std::array<float,9> r{11.0f,12.0f,13.0f,14.0f,15.0f,16.0f,17.0f,18.0f,19.0f};
    std::array<float,3> vec1, vec2, vec3;
    std::array<float,3> v1{11.0f,12.0f,13.0f}, v2{14.0f,15.0f,16.0f}, v3{17.0f,18.0f,19.0f};
    my_tie(vec1, vec2, vec3) = r;
    EXPECT_EQ(vec1, v1);
    EXPECT_EQ(vec2, v2);
    EXPECT_EQ(vec3, v3);
}

TEST(Cat, _) {
    std::array<float,3> vec1{1.0f,2.0f,3.0f};
    std::array<float,3> vec2{4.0f,5.0f,6.0f};
    std::array<float,3> vec3{7.0f,8.0f,9.0f};
    std::array<float,9> ans{1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
    std::array<float,9> r = cat(vec1, vec2, vec3);
    EXPECT_EQ(r, ans);
}

TEST(Message, _) {
    std::stringstream ss;
    message(ss, "% is the absolute %head warlord%\n", "xQcL", 5, 777.777);
    EXPECT_EQ(ss.str(),
	std::string("xQcL is the absolute 5head warlord777.777\n"));
}

TEST(Message, InvalidArgument_1) {
    std::stringstream ss;
    EXPECT_THROW(message(ss, "% is the absolute head warlord%\n", "xQcL", 5, 777.777), 
		std::invalid_argument);
}

TEST(Message, InvalidArgument_2) {
    std::stringstream ss;
    EXPECT_THROW(message(ss, "% is the %absolute %head warlord%\n", "xQcL", 5, 777.777), 
                std::invalid_argument);
}
