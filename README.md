# Guide to Building gRPC with Protobuf

## System Requirements

Before building gRPC, you need to install the following tools:
- **`protoc`** (Protocol Buffers Compiler)
- **`grpc_cpp_plugin`** (gRPC C++ Plugin)
- **`protobuf` and `gRPC` C++**

## Installing on Ubuntu
```sh
sudo apt update
sudo apt install -y protobuf-compiler grpc-dev libgrpc++-dev
```
## Checking the Installed Version
```sh
protoc --version
```
```sh
which grpc_cpp_plugin (find the path of grpc_cpp_plugin)
```
## Building gRPC and Protobuf
Compiling gRPC Stub from .proto
```sh
protoc --grpc_out=. --plugin=protoc-gen-grpc=$(which grpc_cpp_plugin) aglcom.proto
```
Note: Replace /usr/local/bin/grpc_cpp_plugin with the actual path of grpc_cpp_plugin if different.
## Compiling Protobuf to C++ Code
```sh
protoc --cpp_out=. aglcom.proto
```
After running the above commands, you will get .pb.cc and .pb.h files to use in your C++ source code.
## Building a C++ Program with gRPC

Create a `build` directory, navigate into it, and use `cmake` to generate the necessary build files. Then, compile the project:

```sh
mkdir build      # Create a build directory
cd build        # Move into the build directory
cmake ..       # Generate build files using CMake
make           # Compile the project

```
