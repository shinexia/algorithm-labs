//
// Created by Shine Xia on 2019/2/17.
//

#include "solution.h"

#include "mylib/util.h"
#include "gtest/gtest.h"

struct Case {
    int x;
    bool expect;
};


TEST(TestPalindromeNumber, simple) {
    Case cases[] = {
            {-1,         false},
            {0,          true},
            {1,          true},
            {10,         false},
            {121,        true},
            {-121,       false},
            {22,         true},
            {21,         false},
            {123,        false},
            {1073773701, true},
    };

    int N = sizeof(cases) / sizeof(Case);

    for (int i = 0; i < N; i++) {
        const Case *c = &cases[i];
        bool ret = isPalindrome(c->x);
        EXPECT_EQ(ret, c->expect) << "x=" << c->x << ", out=" << ret << ", expect=" << c->expect;
    }
}
