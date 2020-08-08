cmake_minimum_required(VERSION 3.5)

project(manna-server)

# nghttp2
set(WITH_NEVERBLEED 1)
set(ENABLE_LIB_ONLY 1)
set(ENABLE_ASIO_LIB ON)
set(ENABLE_THIRD_PARTY 1)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/third-party/nghttp2)

# manna-server
add_library(${PROJECT_NAME} SHARED "")
include(src/CMakeLists.txt)

target_include_directories(
    ${PROJECT_NAME} INTERFACE
    "${CMAKE_CURRENT_LIST_DIR}/src"
)

target_link_libraries(manna-server ${Boost_LIBRARIES}) # Take Boost libraries from nghttp2!
target_link_libraries(manna-server nghttp2)
target_link_libraries(manna-server nghttp2_asio)
