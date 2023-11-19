/*
 *  问题：解开密码锁的最少次数
 *  描述: 1. 一个带有4个圆型拨轮的密码锁，每个拨轮都有0~9共10个数字
 *        2. 每个拨轮可以上下拨动
 *        3. 密码锁的初始值都是0，表示为字符串"0000"
 *  注意：存在禁止数字和目标数字
 *        1.禁止数字：一组数字字符串，密码锁上的数字不能与之相等
 *        2.目标数字：密码锁上最终呈现的数字
 *  思考：不能用回溯，因为穷举太耗时
 */

#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <array>

char toAdd(char c, int d) {
    char ret = c;

    if( ('0' <= c) && (c <= '9') ) {
        ret = ((c - '0') + 10 + d % 10) % 10 + '0';
    }

    return ret;
}

// 一个拨码，相邻的数有8个
std::array<std::string, 8> makeNeighbor(const std::string& current) {
    std::array<std::string, 8> ret{};

    for(int i = 0, j = 0; i < 4; i++) {
        char ch = current[i];

        // 拨上一个
        ret[j] = current;
        ret[j][i] = toAdd(ch, 1);

        j++;
        // 拨下一个
        ret[j] = current;
        ret[j][i] = toAdd(ch, -1);

        j++;
    }

    return ret;
}

int lockNum(const std::string& target, const std::unordered_set<std::string>& forbidden) {
    int ret = 0;
    std::unordered_set<std::string> visit{};
    std::queue<std::string> queue;

    if(forbidden.find(target) == forbidden.end()) {
        queue.emplace("0000");
    }

    while(!queue.empty()) {
        size_t len = queue.size();

        for(int i = 0; i <len; i++) {
            std::string s = queue.front();
            queue.pop();
            
            if( (forbidden.find(s) == forbidden.end()) && visit.find(s) == visit.end() ) {
                std::array<std::string, 8> neighbor = makeNeighbor(s);
                visit.emplace(s);

                if( s == target ) {
                    return ret;
                }

                for(auto & ns : neighbor) {
                    queue.emplace(ns);
                }
            }
        }

        ret++;
    }

    return -1;
}

void lockNum() {
    const char* target = "1110";
    const char* fb[] = {"8887", "8888"};
    std::unordered_set<std::string> forbidden{};

    for(auto & s : fb) {
        forbidden.emplace(s);
    }

    std::cout << "min count: " << lockNum(target, forbidden) << std::endl;
}

int main() {
    lockNum();
}
