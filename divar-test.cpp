#include <vector>

#include <catch2/catch_test_macros.hpp>

using namespace std;

int find_eye_contacts(vector<int> leftRow, vector<int> rightRow) {
    int eye_contact = 0;
    for (int i = 0; i < leftRow.size(); ++i) {
        if (leftRow.at(i) == 1 && leftRow.at(i) == rightRow.at(i)) {
            eye_contact++;
        }
    }

    return eye_contact;
}

TEST_CASE("Eye contact detector") {
    REQUIRE(find_eye_contacts({1, 1, 0, 1, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 1, 0, 1}) == 3);
    REQUIRE(find_eye_contacts({0, 0, 0, 1, 1, 1, 0, 1}, {0, 0, 1, 0, 1, 1, 0, 0}) == 2);
}
