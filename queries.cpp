#include <iostream>
#include <vector> // for vector
#include <algorithm>
#include <numeric> // for accumulate

int triple(int value) { return (value * 3); }

bool is_odd(int value) { return (value % 2); }

int main()
{
    std::vector<int> v = {4, 6, 7, 8, 2, 3, 1, 5, 6};
    std::sort(begin(v), end(v));

    for (auto value : v)
        std::cout << value;
    std::cout << std::endl;

    auto count = std::count(begin(v), end(v), 6); // returns the number of times the element specified as parameter has appeared in the vector
    // remember accumulate is in numeric
    auto sum = std::accumulate(begin(v), end(v), 0); //produces the sum of the vector and the third parameter specifies the sarting value of sum which is 0.

    std::cout << count << std::endl;
    std::cout << sum << std::endl;

    std::vector<int> newv;
    // dont forget to resize the new vector before transformation
    newv.resize(v.size());
    std::transform(begin(v), end(v), begin(newv), triple); // can be used to transform a vector based of a function passed as arg 4, arg 3 is the begining of new vector
    // transform and accumulate can be done with transform_reduce

    for (auto value : newv)
        std::cout << value << " ";
    std::cout << std::endl;

    std::partial_sum(begin(v), end(v), begin(v)); // each element is generated as the sum of the previous elements(s) and saved to the arg 3 , here saved to same.
    // check out (tansform_)inclusive_scan and (tansform_)exclusive_scan similar to partial_sum , inverse of adjacent_difference
    for (auto value : v)
        std::cout << value << " ";
    std::cout << std::endl;

    std::adjacent_difference(begin(v), end(v), begin(v)); // self explanatory and inverse of partial_sum
    for (auto value : v)
        std::cout << value << " ";
    std::cout << std::endl;

    sum = std::inner_product(begin(v), end(v), begin(v), 1); // two vectors are multiplied linearly and accumulated , here the two vectors are same
    std::cout << sum << std::endl;

    std::cout << std::all_of(begin(v), end(v), is_odd) << std::endl;  // checks whether all of the values in the given range returns a true for fn in arg 3
    std::cout << std::any_of(begin(v), end(v), is_odd) << std::endl;  // checks whether any of the values in the given range returns a true for fn in arg 3
    std::cout << std::none_of(begin(v), end(v), is_odd) << std::endl; // checks whether none of the values in the given range returns a true for fn in arg 3

    std::cout << std::endl;

    std::cout << std::equal(begin(v), end(v), begin(v)) << std::endl;                                 // compares two vectors for equality
    std::cout << std::lexicographical_compare(begin(v), end(v), begin(newv), end(newv)) << std::endl; // compares two vectors for equality regardless of order ?
    auto miss = std::mismatch(begin(v), end(v), begin(v));                                            // returns the position of first mismatch

    std::cout << std::endl;

    // SEARCHES

    // NOT SORTED

    auto found = std::find(begin(v), end(v), 5); // returns pointer to the first occurance of the arg 3 value , else if not found returns the end pointer
    // remember find can be used for sorted or not sorted also
    if (found != end(v))
        std::cout << "element " << *found << " found at index :" << found - v.begin() << std::endl;

    // auto adjfound = std::adjacent_find(begin(v), end(v), 6); // returns the first index pointer of two adjacent arg 3 values found

    std::cout << std::endl;

    // SORTED
    bool bs = std::binary_search(begin(v), end(v), 5); // returns if a object exist or not in a sorted vector

    auto search = std::search(begin(v), end(v), begin(v) + 2, end(v) - 1); // searching a sub range in a range returns the poiner to fist elemnet in of subrange in range
    // std::cout << *search << std::endl;
    search = std::find_end(begin(v), end(v), begin(v) + 2, end(v) - 1); // similar to search but search starts from opposite direction (that is from end)

    search = std::find_first_of(begin(v), end(v), begin(v) + 2, end(v) - 1); // returns a pointer to any of the first occuring value in subrange that is in range , that is find any one value in subrange in the main range and return the pointer

    std::cout << *(std::max_element(begin(v), end(v))) << std::endl; // returns pointer to min element
    std::cout << *(std::min_element(begin(v), end(v))) << std::endl; // returns pointer to max element
    auto minmax = std::minmax_element(begin(v), end(v));

    std::cout << "The minmax elements are : " << std::endl;
    std::cout << *(minmax.first) << " and " << *(minmax.second) << std::endl;

    return 0;
}