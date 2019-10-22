# prerequisites
* cmake 3.0+
* gcc 7.0+ (or any other compiler that support C++14 for no reason)

# build
```
mkdir build
cd build

cmake ..
cmake --build .
ctest -C Debug -V
```