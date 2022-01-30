cmake_minimum_required(VERSION 3.0.0)
project(genetic_aligorithm VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../out) # 指定可执行程序的输出目录
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(MODULE_MAIN genetic_aligorithm)
set(MODULE_FUNC func)

include(CTest)
enable_testing()

aux_source_directory(${PROJECT_SOURCE_DIR} DIR_MAIN)
add_subdirectory(func) # 添加子文库

add_executable(${MODULE_MAIN} ${DIR_MAIN} )
target_link_libraries(${MODULE_MAIN} ${MODULE_FUNC})


include(CPack)
