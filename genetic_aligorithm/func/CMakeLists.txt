message(STATUS "Enter func folder")

aux_source_directory(. ALL_CPP_FILE)   #将当前目录下所有源文件赋给ALL_CPP_FILE变量，当源文件数量比较多时会比较方便

add_library(func ${ALL_CPP_FILE})