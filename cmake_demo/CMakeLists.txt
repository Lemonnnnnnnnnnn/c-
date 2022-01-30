cmake_minimum_required(VERSION 3.0.0)
project(aaa VERSION 0.1.0)

set(MODULE_MAIN demo)                     # 设置模块名称变量
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CTest)
enable_testing()

aux_source_directory(${PROJECT_SOURCE_DIR} DIR_MAIN_SRCS) # 当前目录下所有可执行文件
# 法一
# aux_source_directory(${PROJECT_SOURCE_DIR}/math DIR_HELLO_SRCS) #math目录下所有可执行文件
# add_executable(${MODULE_MAIN} ${DIR_MAIN_SRCS} ${DIR_HELLO_SRCS})  # 执行多个文件
# 法二
add_subdirectory(math)  # 声明有一个子目录math
add_executable(${MODULE_MAIN} ${DIR_MAIN_SRCS})  # 执行根目录下的文件 名字为 MODULE_MAIN 即demo
target_link_libraries(${MODULE_MAIN} MathFunctions)  # 将根目录下的文件链接到 MODULE_MAIN


include(CPack)
