#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> e = {6, 7, 8, 9, 10, 11, 12, 13, 14};
    std::sort(begin(v), end(v));
    std::sort(begin(e), end(e));
    std::vector<int> result;
    result.resize(v.size() + e.size());

    std::set_difference(begin(v), end(v), begin(e), end(e), begin(result));   // set subtraction
    std::set_intersection(begin(v), end(v), begin(e), end(e), begin(result)); // set intersectoin
    std::set_union(begin(v), end(v), begin(e), end(e), begin(result));        // set intersectoin

    for (auto value : result)
        std::cout << value << " ";
    std::cout << std::endl;

    return 0;
}