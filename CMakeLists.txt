cmake_minimum_required(VERSION 3.5)

project(aglcom_grpc)

set(CMAKE_PREFIX_PATH "/usr/local;/usr")

find_package(Protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 14)

include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${gRPC_INCLUDE_DIRS})

add_library(aglcom_proto
    aglcom.pb.cc
    aglcom.grpc.pb.cc
)

add_executable(GRPCServer GRPCServer.cpp)
target_link_libraries(GRPCServer aglcom_proto gRPC::grpc++ protobuf::libprotobuf)

add_executable(GRPCClient GRPCClient.cpp)
target_link_libraries(GRPCClient aglcom_proto gRPC::grpc++ protobuf::libprotobuf)
