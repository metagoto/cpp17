#!/bin/sh

#set -e

BUILD_TYPE=Release
CXX_STD=1z

CLANG_DIR=/home/runpac/dev/clang-install
LIBCPP_INC="$CLANG_DIR/include/c++/v1"
LIBCPP_LIB="$CLANG_DIR/lib"

CXX_FLAGS="-stdlib=libc++ -std=c++1z -I$LIBCPP_INC"
CXX_LINKER_FLAGS="-stdlib=libc++ -L$LIBCPP_LIB -lc++ -lc++abi"


export CXX="$CLANG_DIR/bin/clang++"
export CC="$CLANG_DIR/bin/clang"

CTEST_OUTPUT_ON_FAILURE=1
export CTEST_OUTPUT_ON_FAILURE

rm -rf build
mkdir build
cd build
cmake -DCPP17_CXX_STD=$CXX_STD -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
  -DCMAKE_CXX_FLAGS="${CXX_FLAGS}" -DCMAKE_EXE_LINKER_FLAGS="${CXX_LINKER_FLAGS}" \
  ..
make
make test
#ARGS="-V"
cd ..

