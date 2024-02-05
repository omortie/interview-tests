// clear explainnation and simple input and output template
// can help the readers understand the problem properly
// I assume this problem seeks for, corresponding elements should be counted!

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

//string register_user(string username) {
//
//}
//
//string add_advertise(string username, string title) {
//
//}
//
//string rem_advertise(string username, string title) {
//
//}
//
//string list_my_advertises(string username) {
//
//}
//
//string add_favorite(string username, string title) {
//
//}
//
//string remove_favorite(string username, string title) {
//
//}
//
//string list_favorite_advertises(string username) {
//
//}
//
//string list_my_advertises(string username, string title, string tag) {
//
//}
//
//string list_my_advertises(string username, string tag) {
//
//}
//
//string list_favorite_advertises(string username, string tag) {
//
//}
//
//TEST_CASE("My Divar") {
//    REQUIRE(register_user("user1") == "registered successfully");
//    REQUIRE(register_user("user2") == "registered successfully");
//    REQUIRE(add_advertise("user1", "car") == "posted successfully");
//    REQUIRE(add_advertise("user2", "laptop") == "posted successfully");
//    REQUIRE(add_advertise("user2", "laptop") == "invalid title");
//    REQUIRE(list_my_advertises("user1") == "car");
//    REQUIRE(list_my_advertises("user2") == "laptop");
//    REQUIRE(rem_advertise("user2", "phone") == "invalid title");
//    REQUIRE(list_my_advertises("user2") == "laptop");
//}