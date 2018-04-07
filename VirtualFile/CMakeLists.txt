aux_source_directory(. vf_src_list)

include_directories(${PROJECT_SOURCE_DIR}/../ ${PROJECT_SOURCE_DIR}/../Queue/)

link_directories(${PROJECT_SOURCE_DIR}/../Queue/build)

add_library(virtualfile ${vf_src_list})

target_link_libraries(virtualfile queue)