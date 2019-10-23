#include "value_independent_knapsack_problem_dp_solver.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <cstdint>
#include <vector>
#include <stdexcept>

void default_test()
{
    std::cout << __FUNCTION__ << std::endl;
    
    const uint32_t T = 11;
    const std::vector<uint32_t> I = {1, 2, 3, 4, 5, 6, 7};

    std::vector<uint32_t> result;
    auto S = std::numeric_limits<uint32_t>::max();

    find_largest_sum(T, I, result, S);
    if (S != 11)
    {
        throw std::logic_error{"S != 11"};
    }

    const std::vector<uint32_t> expected_result{2, 4, 5};
    auto subset_equal = std::equal(
        std::cbegin(result), std::cend(result),
        std::cbegin(expected_result), std::end(expected_result));

    if (!subset_equal)
    {
        std::copy(std::cbegin(result), std::cend(result), std::ostream_iterator<uint32_t>(std::cerr, " "));
        throw std::logic_error{"incorrect solutions_cache"};
    }
}

void t_is_more_then_array_sum_test()
{
    std::cout << __FUNCTION__ << std::endl;

    const uint32_t T = 100;
    const std::vector<uint32_t> I = {0, 10, 11, 12, 13, 14, 15};

    std::vector<uint32_t> result;
    auto S = std::numeric_limits<uint32_t>::max();

    find_largest_sum(T, I, result, S);
    if (S != 75)
    {
        throw std::logic_error{"S != 75"};
    }

    const std::vector<uint32_t> expected_result{10, 11, 12, 13, 14, 15};
    auto subset_equal = std::equal(
        std::cbegin(result), std::cend(result),
        std::cbegin(expected_result), std::end(expected_result));

    if (!subset_equal)
    {
        std::copy(std::cbegin(result), std::cend(result), std::ostream_iterator<uint32_t>(std::cerr, " "));
        throw std::logic_error{"incorrect solutions_cache"};
    }
}

void t_is_less_then_array_sum_test()
{
    std::cout << __FUNCTION__ << std::endl;

    const uint32_t T = 100;
    const std::vector<uint32_t> I = {0, 12, 43, 11, 67, 20, 1, 4, 7, 31, 55, 6};

    std::vector<uint32_t> result;
    auto S = std::numeric_limits<uint32_t>::max();

    find_largest_sum(T, I, result, S);
    if (S != 100)
    {
        throw std::logic_error{"S != 100"};
    }

    const std::vector<uint32_t> expected_result{12, 67, 20, 1};
    auto subset_equal = std::equal(
        std::cbegin(result), std::cend(result),
        std::cbegin(expected_result), std::end(expected_result));

    if (!subset_equal)
    {
        std::copy(std::cbegin(result), std::cend(result), std::ostream_iterator<uint32_t>(std::cerr, " "));
        throw std::logic_error{"incorrect solutions_cache"};
    }
}

void t_is_unreachable_test()
{
    std::cout << __FUNCTION__ << std::endl;

    const uint32_t T = 59;
    const std::vector<uint32_t> I = {0, 12, 22, 10, 12, 40, 32};

    std::vector<uint32_t> result;
    auto S = std::numeric_limits<uint32_t>::max();

    find_largest_sum(T, I, result, S);
    if (S != 56)
    {
        throw std::logic_error{"S != 56"};
    }

    const std::vector<uint32_t> expected_result{12, 22, 10, 12};
    auto subset_equal = std::equal(
        std::cbegin(result), std::cend(result),
        std::cbegin(expected_result), std::end(expected_result));

    if (!subset_equal)
    {
        std::copy(std::cbegin(result), std::cend(result), std::ostream_iterator<uint32_t>(std::cerr, " "));
        throw std::logic_error{"incorrect solutions_cache"};
    }
}

void subset_is_always_equal_test()
{
    std::cout << __FUNCTION__ << std::endl;

    const uint32_t T = 1;
    const std::vector<uint32_t> I = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    std::vector<uint32_t> result;
    auto S = std::numeric_limits<uint32_t>::max();

    find_largest_sum(T, I, result, S);
    if (S != 0)
    {
        throw std::logic_error{"S != 0"};
    }

    const std::vector<uint32_t> expected_result{};
    auto subset_equal = std::equal(
        std::cbegin(result), std::cend(result),
        std::cbegin(expected_result), std::end(expected_result));

    if (!subset_equal)
    {
        std::copy(std::cbegin(result), std::cend(result), std::ostream_iterator<uint32_t>(std::cerr, " "));
        throw std::logic_error{"incorrect solutions_cache"};
    }
}

void large_allocation_test()
{
    std::cout << __FUNCTION__ << std::endl;

    const uint32_t T = std::numeric_limits<uint32_t>::max();
    const auto I = std::vector<uint32_t>{1000};

    std::vector<uint32_t> result;
    auto S = std::numeric_limits<uint32_t>::max();

    find_largest_sum(T, I, result, S);
}

int main()
{
    try
    {
        default_test();
        t_is_more_then_array_sum_test();
        t_is_less_then_array_sum_test();
        t_is_unreachable_test();
        subset_is_always_equal_test();

        // should segfault
        // large_allocation_test();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}