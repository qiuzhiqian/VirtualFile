aux_source_directory(. queue_src_list)

message(${queue_src_list})

include_directories(./ ../)

add_library(queue ${queue_src_list})