cmake_minimum_required(VERSION 3.5)

project(manna-server)

# nghttp2
set(ENABLE_LIB_ONLY 1)
set(ENABLE_ASIO_LIB ON)
set(ENABLE_THIRD_PARTY 1)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/third-party/nghttp2)

# manna-server
add_library(${PROJECT_NAME} SHARED "")
include(src/CMakeLists.txt)

target_link_libraries(manna-server boost_system)
target_link_libraries(manna-server nghttp2)
target_link_libraries(manna-server nghttp2_asio)
