#include "gtest/gtest.h"
#include "gtest/gtest-spi.h"

#include "combine_vectors.h"
#include <vector>
#include <algorithm>

using namespace std;
using namespace combineVectors;


TEST(combineVectors_tests, equalElements_vec1_smaller)
{
    vector<int> vec_1{2,4};
    vector<int> vec_2{6,8};
    vector<int> exp{2,4,6,8};
    vector<int> res = combine_vectors(vec_1, vec_2);

    EXPECT_TRUE(res == exp);
}

TEST(combineVectors_tests, equalElements_vec1_bigger)
{
    vector<int> vec_1{9,11};
    vector<int> vec_2{1,8};
    vector<int> exp{1,8,9,11};
    vector<int> res = combine_vectors(vec_1, vec_2);

    EXPECT_TRUE(res == exp);
}

TEST(combineVectors_tests, vec1_empty)
{
    vector<int> vec_1{};
    vector<int> vec_2{1,8};
    vector<int> exp{1,8};
    vector<int> res = combine_vectors(vec_1, vec_2);

    EXPECT_TRUE(res == exp);
}

TEST(combineVectors_tests, vec2_empty)
{
    vector<int> vec_1{2,9};
    vector<int> vec_2{};
    vector<int> exp{2,9};
    vector<int> res = combine_vectors(vec_1, vec_2);

    EXPECT_TRUE(res == exp);
}

TEST(combineVectors_tests, vec1_and_vec2_empty)
{
    vector<int> vec_1{};
    vector<int> vec_2{};
    vector<int> exp{};
    vector<int> res = combine_vectors(vec_1, vec_2);

    EXPECT_TRUE(res == exp);
}

