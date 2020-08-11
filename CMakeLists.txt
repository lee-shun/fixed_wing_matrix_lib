cmake_minimum_required(VERSION 3.0.0)
project(FIXED_WING_MATRIX_LIB)

set(TEST_MATRIX ./test/test_matrix.cpp)
set(TEST_PRINT ./test/test_ctrl_print.cpp)
set(TEST_VECTOR ./test/test_vector.cpp)
#add_library()

add_executable(test_matrix ${TEST_MATRIX})
add_executable(test_print ${TEST_PRINT})
add_executable(test_vector ${TEST_VECTOR})

#target_link_libraries()
