#include "max_subsequence_sum.h"

#include "mylib/util.h"
#include "gtest/gtest.h"

struct Case {
    ElementType a[10];
    int n;
    ElementType expect;
};

TEST(TestMaxSubsequenceSum, simple) {
    Case cases[] = {{{},                        0, 0},
                    {{1},                       1, 1},
                    {{-1},                      1, 0},
                    {{1,  2},                   2, 3},
                    {{-1, 2},                   2, 2},
                    {{1,  -2},                  2, 1},
                    {{-1, -2},                  2, 0},
                    {{1,  2,  3},               3, 6},
                    {{-1, 2,  3},               3, 5},
                    {{1,  -2, 3},               3, 3},
                    {{1,  2,  -3},              3, 3},
                    {{1,  -2, -3},              3, 1},
                    {{-1, -2, 3},               3, 3},
                    {{-1, 3,  -1, -1, 2, 3, 4}, 7, 10}};

    int N = sizeof(cases) / sizeof(Case);

    for (int i = 0; i < N; i++) {
        const Case *c = &(cases[i]);
        EXPECT_EQ(MaxSubsequenceSum(c->a, c->n), c->expect)
                            << "a=" << mylib::stringify(c->a, c->n);;
    }
}
