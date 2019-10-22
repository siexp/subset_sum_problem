cmake_minimum_required(VERSION 3.0)	

project(LargestSubset)	
set(CMAKE_CXX_STANDARD 14)	


enable_testing()
add_executable(tests test.cpp)
add_test(NAME LargestSubsetTests COMMAND tests)