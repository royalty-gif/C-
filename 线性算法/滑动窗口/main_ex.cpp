/*
 *  问题：有一个整型数组a[n]和一个大小为w的窗口，窗口每次向右滑动一个位置，求窗口中位数数组
 *  注意点：中位数是有序序列最中间的那个数，如果序列的大小是偶数，中位数是最中间的两个数的平均数
 *  [2,3,4]，中位数是 3
 *  [2,3]，中位数是 (2 + 3) / 2 = 2.5
 */

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <memory>

class Suppose {
public:
    explicit Suppose() : smallSize_(0), largeSize_(0) {}

    void insert(int num) {
        if(small_.empty() || num <= small_.top()) {
            small_.push(num);
            ++smallSize_;
        } else {
            large_.push(num);
            ++largeSize_;
        }

        makeBalance();
    }

    void erase(int num) {
        ++delayed_[num];
        if(num <= small_.top()) {
            --smallSize_;
            if(num == small_.top()) {
                prune(small_);
            }
        } else {
            --largeSize_;
            if(num == large_.top()) {
                prune(large_);
            }
        }

        makeBalance();
    }

    int size() const {
        return largeSize_ + smallSize_;
    }

    double getMedian() {
        return size() & 1 ? small_.top() : ((double)small_.top() + large_.top()) / 2.0;
    }
private:
    template<typename T>
    void prune(T& heap) {
        while(!heap.empty()) {
            int num = heap.top();
            if(delayed_.count(num)) {
                --delayed_[num];
                if(!delayed_[num]) {
                    delayed_.erase(num);
                }

                heap.pop();
            } else {
                break;
            }

        }
    }

    void makeBalance() {
        if( smallSize_ > largeSize_ + 1 ) {
            large_.push(small_.top());
            small_.pop();
            --smallSize_;
            ++largeSize_;

            prune(small_);

        } else if( smallSize_ < largeSize_ ) {
            small_.push(large_.top());
            large_.pop();
            ++smallSize_;
            --largeSize_;

            prune(large_);
        }
    }
private:
    std::priority_queue<int> small_; // 大顶堆存较小值
    std::priority_queue<int, std::vector<int>, std::greater<>> large_; // 小顶堆存较大值
    std::unordered_map<int, int> delayed_; // 延迟删除记录删除的值和次数
    int smallSize_, largeSize_;
};

std::shared_ptr<double[]> getWinMedia(int arr[], int len, int w) {
    std::shared_ptr<double[]> ret(new double[len - w + 1]);
    Suppose s;
    int index = 0;

    for(int i = 0; i < len; i++) {
        s.insert(arr[i]);

        if(s.size() == w) {
            ret[index++] = s.getMedian();
            s.erase(arr[i - w + 1]);
        }
    }

    return ret;
}

int main() {
    int arr[] = {4, 3, 5, 4, 3, 3, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    int w = 3;

    std::shared_ptr<double[]> r = getWinMedia(arr, len, w);

    for(int i = 0; i < len - w + 1; i++) {
        std::cout << i << " : " << r[i] << std::endl;
    }

    return 0;
}