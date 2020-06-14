#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    // remember the begin and end can be modifed with +|- to generate a unique range

    std::make_heap(begin(v), end(v)); // arrages values in vector v as if it was a maxheap
    // v.push_back(10);                  // pushes an element to the end of the vector
    // std::push_heap(begin(v), end(v)); // used to heapify again so as to sort new elements
    std::sort(begin(v), end(v)); // sorts the heap in ascending order
    // std::sort_heap(begin(v), end(v)); // sorts but in a pop_heap push_heap fashion
    // std::nth_element(begin(v), begin(v) + 4, end(v)); //sorts the nth element to its right postion (that is if the postion if the whole vector was sorted) and everything before it is smaller and vice versa
    // std::rotate(begin(v), begin(v) + 3, end(v)); // used to right rotate n times , here n = 3
    // std::shuffle(begin(v), end(v), ); // do after chrono

    // for (int i = 0; i < 6; i++)
    // {
    //     for (auto value : v)
    //         std::cout << value;
    //     std::cout << std::endl;
    //     std::next_permutation(begin(v), begin(v) + 3);
    // }

    // next_permutation generate the next possible unique permutation for the selected range of elements specified in the parameter
    // similarly the prev_permutation gens the previous one

    std::reverse(end(v) - 4, end(v)); // reverses the order in the specified range in parmeter

    for (auto value : v)
        std::cout << value;
    std::cout << std::endl;

    std::cout << std::is_sorted(begin(v), end(v)) << std::endl; // returns boolen on if sorted with the range , similarly is_partitioned

    std::is_sorted_until(begin(v), end(v)); // returns the iterator from where it is not in ascending order , we can use it as first parameter to std::sort

    return 0;
}