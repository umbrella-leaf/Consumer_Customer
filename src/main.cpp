#include "head.h"

std::mutex mut{};
std::queue<int> queData{};
std::condition_variable cond{};
int nCnt = 0;

int main() {
    std::thread customers[2];
    std::thread productors[5];
    for (int i = 0; i < 2; ++i) customers[i] = std::thread(Customer);
    for (int i = 0; i < 5; ++i) productors[i] = std::thread(Product);

    for (int i = 0; i < 2; ++i) customers[i].join();
    for (int i = 0; i < 5; ++i) productors[i].join();
    return 0;
}