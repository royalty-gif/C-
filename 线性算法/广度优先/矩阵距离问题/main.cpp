/*
 *  矩阵距离问题:
 *  1. 一个矩阵M只由0和1组成，计算一个大小相同的矩阵距离D
 *  2. D中的元素是M中对应元素最近的0元素的距离
 *  3. 水平或垂直方向相邻的两个矩阵元素距离为1
 */

#include <iostream>
#include <memory>
#include <queue>
#include <vector>

static const int kRow = 4;
static const int kCol = 4;

struct Pos {
    int x;
    int y;

    explicit Pos(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
};

std::vector<Pos> makeNeighbor(const Pos& pos) {
    static const Pos dir[] = {Pos(1, 0), Pos(0, 1), Pos(-1, 0), Pos(0, -1)};
    std::vector<Pos> ret{};

    for(const auto& d : dir) {
        Pos np;

        np.x = pos.x + d.x;
        np.y = pos.y + d.y;

        if((0 <= np.x) && (np.x <= kRow) && (0 <= np.y) && (np.y <= kCol)) {
            ret.emplace_back(np);
        }
    }

    return ret;
}

int minDistance(const Pos& pos, int matrix[kRow][kCol]) {
    int ret = 0;
    int mask[kRow][kCol] = {0};
    std::queue<Pos> queue{};

    queue.emplace(pos);

    while( !queue.empty() ) {
        size_t len = queue.size();

        for(int i = 0; i < len; i++) {
            Pos node = queue.front();

            queue.pop();

            mask[node.x][node.y] = 1;

            if( !matrix[node.x][node.y] ) {
                return ret;
            } else {
                std::vector<Pos> neighbor = makeNeighbor(node);

                for(const auto& j : neighbor) {
                    if( !mask[j.x][j.y] ) {
                        queue.emplace(j);
                    }
                }
            }
        }

        ret++;
    }

    return -1;
}

void matrixMinDistance(int matrix[kRow][kCol], int result[kRow][kCol]) {
    for(int i = 0; i < kRow; i++) {
        for(int j = 0; j < kCol; j++) {
            result[i][j] = minDistance(Pos(i, j), matrix);
        }
    }
}

void matrixMinDistance() {
    int matrix[kRow][kCol] = {
            {1, 0, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 1, 1, 1},
    };
    int result[kRow][kCol] = {0};

    matrixMinDistance(matrix, result);

    for(int i=0; i<kRow; i++) {
        for(int j=0; j<kCol; j++) {
            std::cout << result[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

int main() {
    matrixMinDistance();
}
