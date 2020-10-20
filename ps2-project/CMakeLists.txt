#1. State the CMake version.
cmake_minimum_required(VERSION 3.18.4)



#2. Set the C++ version and optimization flags.
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse -msse2 -msse3")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} -O0")


#3. Which is the project's root folder?
project(ps2-project)



#4. Libraries
#4.1 Eigen3
include (ExternalProject)
ExternalProject_Add(
eigen
# we suppose here that your project is named TP
# Library Eigen3 is stored in the sub - folder eigen
SOURCE_DIR ${ps2-project_SOURCE_DIR}/src/3.2.10/eigen-eigen-b9cd8366d4e8
INSTALL_COMMAND echo " Skipping install "
)
INCLUDE_DIRECTORIES(${ps2-project_SOURCE_DIR}/src/3.2.10/eigen-eigen-b9cd8366d4e8)

#4.2 Boost
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.74 REQUIRED filesystem program_options regex unit_test_framework system timer)
#include_directories(src ${Boost_INCLUDE_DIR})



#5. EXECUTABLES
#5.1 Create the executable for the algebra files.
#5.1.1 Eigen3 files.
add_executable(array-addition-3x1-eigen3-exe src/tests/eigen3/array-addition-3x1.cpp)
add_executable(array-addition-equal-test-1-eigen3-exe src/tests/eigen3/array-addition-equal-test-1.cpp)
add_executable(array-addition-equal-test-2-eigen3-exe src/tests/eigen3/array-addition-equal-test-2.cpp)
add_executable(matrix-product-equal-test-exe src/tests/eigen3/matrix-product-equal-test.cpp)
add_executable(matrix-product-equal-test-2-exe src/tests/eigen3/matrix-product-equal-test-2.cpp)
add_executable(matrix-product-exe src/tests/eigen3/matrix-product.cpp)

#5.1.2 Ublas files.
add_executable(array-addition-3x1-ublas-exe src/tests/ublas/array-addition-3x1.cpp)  

#5.2 Link the executables and the libraries.
#5.2.1 Eigen3 files.
target_link_libraries(array-addition-3x1-eigen3-exe ${Boost_LIBRARIES})
target_link_libraries(array-addition-equal-test-1-eigen3-exe ${Boost_LIBRARIES})
target_link_libraries(array-addition-equal-test-2-eigen3-exe ${Boost_LIBRARIES})
target_link_libraries(random-matrix-product-equal-test-exe ${Boost_LIBRARIES})
target_link_libraries(random-matrix-product-equal-test-2-exe ${Boost_LIBRARIES})
target_link_libraries(random-matrix-product-exe ${Boost_LIBRARIES})

#5.2.2 Ublas files.
target_link_libraries(array-addition-3x1-ublas-exe ${Boost_LIBRARIES})



#6. TESTING
enable_testing()
add_test(Test array-addition-equal-test-1-eigen3-exe)
add_test(Test array-addition-equal-test-2-eigen3-exe)
add_test(Test matrix-product-equal-test-exe )
add_test(Test matrix-product-equal-test-2-exe )