//
// Created by Mortie on 2/12/2024.
//

#include <vector>
#include <catch2/catch_test_macros.hpp>

using namespace std;

vector<int> sortTwoVectors(vector<int> &a, vector<int> &b) {
    vector<int> mix;
    mix.insert(mix.begin(), a.begin(), a.end());
    mix.insert(mix.begin(), b.begin(), b.end());

    for (auto& x : mix) {
        for (auto& it : mix) {
            if (it > x) {
                iter_swap(&it, &x);
            }
        }
    }

    return mix;
}

TEST_CASE("sort two vectors task") {
    vector<int> a{7, 4, 9};
    vector<int> b{9, 3, 6};
    vector<int> c{3, 4, 6, 7, 9, 9};
    REQUIRE(sortTwoVectors(a, b) == c);
}