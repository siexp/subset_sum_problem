#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

void find_largest_sum( uint32_t T, const std::vector<uint32_t>& I, std::vector<uint32_t>& M, uint32_t &S )
{
}

void default_test()
{
    const uint32_t T = 11;
    const std::vector< uint32_t > I = { 1, 2, 3, 4, 5, 6, 7 };

    std::vector< uint32_t > result;
    auto sum = std::numeric_limits< uint32_t >::max();
    
    find_largest_sum( T, I, result, sum );
    if ( sum != 11 )
    {
        throw std::logic_error{ "sum != 11" };
    }

    const std::vector< uint32_t > expected_result{ 5, 6 };
    auto subset_equal = std::equal(
        std::cbegin( result ), std::cend( result ),
        std::cbegin( expected_result ), std::end( expected_result )
    );

    if ( !subset_equal )
    {
        throw std::logic_error{ "incorrect subset" };
    }
}


int main()
{
    try
    {
        default_test();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}