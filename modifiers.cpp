#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

int infinity()
{
    static int number = 0;
    number++;
    return number;
}

void print(int number)
{
    std::cout << number * 3 << " ";
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> e = {6, 7, 8, 9, 10, 11, 12, 13, 14};
    std::vector<int> result;
    result.resize(v.size() + e.size());
    std::fill(begin(result), end(result), 27);           // fills the range with arg 3
    std::generate(begin(result), end(result), infinity); // fills the range with the return value of funciton in arg 3
    std::iota(begin(result), end(result), 27);           // fills the value in single increments starting from arg 3
    std::replace(begin(result), end(result), 28, 27);    // simple replace arg 3 with arg 4 in rage
    std::remove(begin(result), end(result), 27);         // removes the arg 3 value from the range and pushes rest of the the values left , the end values are unpredictable
    std::unique(begin(result), end(result));             // removes adjacent duplicate values

    // remember *_copy can be used where * can be remove , unique , reverse , rotate , replace , partition , partial_sort to do these fuctions to a new vector , that is without chainging the main vector
    // similarly *_if with * = find , count , remove , remove_copy , replace , replace_copy and copy , to do these actoins only if the conditional fuction returs a true bool

    for (auto value : result)
        std::cout << value << " ";
    std::cout << std::endl;

    // std::transform(begin(v), end(v), begin(e), end(e), std::plus<int>()); // transform can take two values as arguments too
    // for (auto value : result)
    //     std::cout << value << " ";
    // std::cout << std::endl;

    for_each(begin(result), end(result), print); // for_each calls the function in arg 3 for every value in range , no replacement of original value
    std::cout << std::endl;

    return 0;
}