#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> e = {6, 7, 8, 9, 10, 11, 12, 13, 14};
    std::vector<int> result;
    result.resize(v.size() + e.size());
    std::sort(begin(v), end(v));
    std::sort(begin(e), end(e));
    std::copy(begin(v), end(v), begin(result));                     // simple copy to target
    std::copy(begin(e), end(e), begin(result) + v.size());          // simple cut past using std::move
    std::copy_backward(begin(e), end(e), begin(result) + v.size()); // simple copy similar to copy but in backward direction, similarly move_backward

    for (auto value : result)
        std::cout << value << " ";
    std::cout << std::endl;
    return 0;
}