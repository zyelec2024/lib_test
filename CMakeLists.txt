# 指定CMAKE版本
cmake_minimum_required(VERSION 3.12.4)

# 设置工程名及版本号
project(lib_test VERSION 0.0.1)

# 指定C语言标准
# set(CMAKE_C_STANDARD 11)#C11
# set(CMAKE_CXX_STANDARD 17)#C17
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加预编译宏定义
# add_compile_definitions(UNICODE _UNICODE)

# 添加编译文件

# 添加子cmkae及功能库
add_subdirectory(test/selftest)
list(APPEND EXTRA_LIBS selftest)

add_subdirectory(test/EasyLogger)
list(APPEND EXTRA_LIBS EasyLogger_test)

add_subdirectory(test/FlashDB)
list(APPEND EXTRA_LIBS FlashDB_test)

# 添加可执行文件 exe
add_executable(lib_test main/main.c)

# 链接exe和库
target_link_libraries(lib_test ${EXTRA_LIBS})

# target_include_directories(demo PRIVATE ${PROJECT_SOURCE_DIR})