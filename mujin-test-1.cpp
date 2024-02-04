#include <string>
#include <vector>
#include <algorithm>

#include <catch2/catch_test_macros.hpp>

using namespace std;

string rebuild_message(vector<string> parts) {
    string message;

    auto first_it = find_if(parts.begin(), parts.end(), [](string str) {
        return str.at(0) == 'A';
    });
    message.append(*first_it);
    parts.erase(first_it);

    for (const auto& part : parts) {
        auto next_sibling_it = find_if(parts.begin(), parts.end(), [message](const string& str) {
            return (message.at(message.size() - 1) == str.at(0));
        });

        next_sibling_it.base()->erase(0, 1);
        message.append(*next_sibling_it);
        parts.erase(next_sibling_it);
    }

    return message;
}

TEST_CASE( "Rebuild message test") {
REQUIRE( rebuild_message({"A hello","o radius", "mul tang", "samsung m", "go aZ"}) == "A hello radiusamsung mul tango aZ" );
}
