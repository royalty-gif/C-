// @Func: SubSet输出一个集合中的所有子集
// @Example: 集合{a,b,c}的所有子集是：{},{a},{b},{c},{a,b},{b,c},{a,c},{a,b,c}

#include <iostream>
#include <vector>

using namespace std;

vector<string> SubSet(const string& set) {
    vector<string> ret;

    if(set.empty()) {
        ret.emplace_back("");
    } else if(set.length() == 1) {
        ret.emplace_back("");
        ret.emplace_back(set);
    } else {
        ret = SubSet(set.substr(1));

        int size = ret.size();
        for(int i = 0; i < size; i++) {
            ret.emplace_back(set[0] + ret[i]);
        }
    }

    return ret;
}

int main() {
    vector<string> sub = SubSet("ab");

    for(const auto & i : sub) {
        cout << "\"" << i << "\"" << endl;
    }
}