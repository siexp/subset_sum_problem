cmake_minimum_required(VERSION 3.0)	

project(ValueIndependentKnapsackProblem)	
set(CMAKE_CXX_STANDARD 14)	


enable_testing()
add_executable(tests test.cpp)
add_test(NAME ValueIndependentKnapsackProblemTests COMMAND tests)