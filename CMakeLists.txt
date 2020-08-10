project(FIXED_WING_MATRIX_LIB)

set(TEST_MATRIX ./test/test_matrix.cpp)
set(TEST_PRINT ./test/test_ctrl_print.cpp)
#add_library()

add_executable(test_matrix ${TEST_MATRIX})
add_executable(test_print ${TEST_PRINT})

#target_link_libraries()
