//
// Created by Mortie on 2/12/2024.
//

#include <vector>

#include <catch2/catch_test_macros.hpp>

std::vector<int> parseInteger(int integer) {
    std::vector<int> digits;

    // check for negative integers
    if (integer < 0) {
        integer = abs(integer);
    }

    // divide by 10 and extract digits from the number
    do {
        int residual = integer % 10;
        digits.push_back(residual);
        integer /= 10;
    } while (integer >= 1);

    // reverse the vector to the initial correct order
    std::reverse(digits.begin(), digits.end());

    return digits;
}

bool isPalindrome(const int& number) {
    std::vector<int> digits = parseInteger(number);

    std::vector<int> reversed_digits = digits;
    std::reverse(reversed_digits.begin(), reversed_digits.end());

    return (digits == reversed_digits);
}

TEST_CASE("Integer parser") {
    REQUIRE(parseInteger(23681) == std::vector<int>{2, 3, 6, 8, 1});
    REQUIRE(parseInteger(239832) == std::vector<int>{2, 3, 9, 8, 3, 2});
    REQUIRE(parseInteger(1) == std::vector<int>{1});
    REQUIRE(parseInteger(-9012) == std::vector<int>{9, 0, 1, 2});
    REQUIRE(parseInteger(-4004) == std::vector<int>{4, 0, 0, 4});
    REQUIRE(parseInteger(11) == std::vector<int>{1, 1});
}

TEST_CASE("Palindrome detector") {
    REQUIRE(isPalindrome(23681) == false);
    REQUIRE(isPalindrome(234432) == true);
    REQUIRE(isPalindrome(1) == true);
    REQUIRE(isPalindrome(-9012) == false);
    REQUIRE(isPalindrome(-4004) == true);
    REQUIRE(isPalindrome(11) == true);
}
