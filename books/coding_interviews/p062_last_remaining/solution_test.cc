#include "solution.h"
#include "glog/logging.h"
#include "gtest/gtest.h"
#include "mylib/util.h"

#if 0
TEST(codingInterviews, TestBruteForceLastRemaining) {
    uint32_t ms[] = {1, 2, 3, 5};
    int N = sizeof(ms) / sizeof(uint32_t);
    for (int i = 0; i < N; ++i) {
        uint32_t m = ms[i];
        std::vector<std::pair<int, int>> result;
        for (uint32_t n = 1; n < 50; ++n) {
            int expect = BruteForce_LastRemaining(n, m);
            result.emplace_back(std::make_pair(n, expect));
        }
        LOG(INFO) << "m=" << m << " " << result;
    }
}
#endif

TEST(codingInterviews, TestLastRemaining) {
    for (uint32_t m = 0; m < 10; ++m) {
        for (uint32_t n = 0; n < 100; ++n) {
            int expect = BruteForce_LastRemaining(n, m);
            int out = LastRemaining(n, m);
            if (out != expect) {
                EXPECT_EQ(out, expect)
                    << "n: " << n << ", m: " << m << ", out: " << out
                    << ", expect: " << expect;
                return;
            }
        }
    }
}

// 先用暴力算法列出结果, 找到公式: next = (prev + m) % n，再证明公式是正确的
// m=1;
// 1:0,2:1,3:2,4:3,5:4,6:5,7:6,8:7,9:8,10:9,11:10,12:11,13:12,14:13,15:14,16:15,17:16,18:17,19:18,20:19,21:20,22:21,23:22,24:23,25:24,26:25,27:26,28:27,29:28,30:29,31:30,32:31,33:32,34:33,35:34,36:35,37:36,38:37,39:38,40:39,41:40,42:41,43:42,44:43,45:44,46:45,47:46,48:47,49:48
// m=2;
// 1:0,2:0,3:2,4:0,5:2,6:4,7:6,8:0,9:2,10:4,11:6,12:8,13:10,14:12,15:14,16:0,17:2,18:4,19:6,20:8,21:10,22:12,23:14,24:16,25:18,26:20,27:22,28:24,29:26,30:28,31:30,32:0,33:2,34:4,35:6,36:8,37:10,38:12,39:14,40:16,41:18,42:20,43:22,44:24,45:26,46:28,47:30,48:32,49:34
// m=3;
// 1:0,2:1,3:1,4:0,5:3,6:0,7:3,8:6,9:0,10:3,11:6,12:9,13:12,14:1,15:4,16:7,17:10,18:13,19:16,20:19,21:1,22:4,23:7,24:10,25:13,26:16,27:19,28:22,29:25,30:28,31:0,32:3,33:6,34:9,35:12,36:15,37:18,38:21,39:24,40:27,41:30,42:33,43:36,44:39,45:42,46:45,47:1,48:4,49:7
// m= 5;
// 1:0,2:1,3:0,4:1,5:1,6:0,7:5,8:2,9:7,10:2,11:7,12:0,13:5,14:10,15:0,16:5,17:10,18:15,19:1,20:6,21:11,22:16,23:21,24:2,25:7,26:12,27:17,28:22,29:27,30:2,31:7,32:12,33:17,34:22,35:27,36:32,37:0,38:5,39:10,40:15,41:20,42:25,43:30,44:35,45:40,46:45,47:3,48:8,49:13