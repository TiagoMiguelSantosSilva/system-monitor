#include "monitor/system_stats.hpp"

int main() {
    system_stats stats;
    std::cout << stats.update_stats();
    return 0;
}