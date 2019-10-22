#pragma once

#include <algorithm>
#include <cstdint>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>

void restore_path(const std::vector<uint32_t> &I, const std::vector<std::vector<uint32_t>> &solutions_cache, std::vector<uint32_t> &M, uint32_t item_index, uint32_t current_capacity)
{
    if (item_index == 0 || current_capacity == 0)
        return;

    if (solutions_cache[item_index][current_capacity] == solutions_cache[item_index - 1][current_capacity])
    {
        restore_path(I, solutions_cache, M, item_index - 1, current_capacity);
    }
    else
    {
        restore_path(I, solutions_cache, M, item_index - 1, current_capacity - I[item_index]);
        M.push_back(I[item_index]);
    }
}

void find_largest_sum(uint32_t T, const std::vector<uint32_t> &I, std::vector<uint32_t> &M, uint32_t &S)
{
    if (I.empty())
    {
        throw std::logic_error{"I is empty"};
    }

    const auto input_size = I.size();
    std::vector<std::vector<uint32_t>> solutions_cache{input_size + 1};
    std::for_each(
        std::begin(solutions_cache), std::end(solutions_cache),
        [T](auto &subarray) {
            subarray.resize(T + 1);
        });

    // for each item
    for (uint32_t item_index = 1; item_index <= input_size; item_index++)
    {
        // until target capacity isn't reached
        for (uint32_t current_capacity = 1; current_capacity <= T; current_capacity++)
        {
            // skip item if it don't fit at current capacity
            if (current_capacity < I[item_index])
            {
                solutions_cache[item_index][current_capacity] = solutions_cache[item_index - 1][current_capacity];
            }
            else
            {
                // check if taking this item will improve the solution
                solutions_cache[item_index][current_capacity] = std::max(solutions_cache[item_index - 1][current_capacity], solutions_cache[item_index - 1][current_capacity - I[item_index]] + I[item_index]);
            }
        }
    }

    S = solutions_cache[input_size][T];
    restore_path(I, solutions_cache, M, input_size, T);
}