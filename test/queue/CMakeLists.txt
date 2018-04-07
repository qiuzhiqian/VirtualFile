project(QTEST)

message(${PROJECT_SOURCE_DIR})

aux_source_directory(. qtest_src_list)

include_directories(${PROJECT_SOURCE_DIR}/../../ ${PROJECT_SOURCE_DIR}/../../Queue/)

link_directories(${PROJECT_SOURCE_DIR}/../../Queue/build)

add_executable(qtest ${qtest_src_list})
target_link_libraries(qtest queue)