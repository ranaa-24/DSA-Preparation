#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    std::vector<std::vector<int>> vec = {{3, 5, 1}, {2, 8, 4}, {7, 6, 9}};

    std::sort(vec.begin(), vec.end());      // sorts acoording to first element of each row

    // std::sort(vec.begin(), vec.end(), [](vector<int> &a, vector<int> &b) {
    //     return a[1] < b[1];                 // sorts according to second element of each row    
    // }); 

    for (const auto &row : vec) {
        for (int val : row) std::cout << val << " ";
        std::cout << "\n";
    }

    return 0;
}
