cmake_minimum_required(VERSION 3.0.0)
project(aStar VERSION 0.1.0)

include(CTest)
enable_testing()

aux_source_directory(${PROJECT_SOURCE_DIR} ALL_FILES)
add_executable(aStar ${ALL_FILES}) 

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
