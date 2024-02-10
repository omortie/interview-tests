// this is a solution to the problem described here:
// https://www.hackerrank.com/challenges/sock-merchant?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup

#include <bits/stdc++.h>

#include <catch2/catch_test_macros.hpp>

using namespace std;

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, const vector<int>& ar) {
    // first we declare a map for each color to find their match
    map<int, bool> pair_counters;

    int pairs = 0;

    // traverse through the provided color array
    for (const int color : ar) {
        // initialize each color by false (no match found yet)
        if (!pair_counters.contains(color)) {
            pair_counters.insert(pair<int, int>(color, false));
        }
        // check if a previous state is found (true means another match found)
        if (pair_counters[color]) {
            // increase pairs number
            pairs++;
            // return the state to find another color match
            pair_counters[color] = false;
        } else {
            // set a flag if a color has been found for next item to be matched
            pair_counters[color] = true;
        }
    }

    return pairs;
}

TEST_CASE("Sock Merchant Question") {
    vector<int> ar{10, 20, 20, 10, 10, 30, 50, 10, 20};
    REQUIRE(sockMerchant(9, ar) == 3);
}