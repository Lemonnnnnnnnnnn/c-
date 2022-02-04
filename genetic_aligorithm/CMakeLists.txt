cmake_minimum_required(VERSION 3.0.0)
project(genetic_aligorithm VERSION 0.1.0)


set(MODULE_MAIN genetic_aligorithm)

# include(CTest)
# enable_testing()

aux_source_directory(${PROJECT_SOURCE_DIR} DIR_MAIN)

add_executable(${MODULE_MAIN} ${DIR_MAIN} )
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(CPack)
