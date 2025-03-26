#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "aglcom.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using aglcom::DemoMessage;
using aglcom::DemoRequest;
using aglcom::DemoReply;

class DemoMessageServiceImpl final : public DemoMessage::Service {
  Status SendDemo(ServerContext* context, const DemoRequest* request, DemoReply* reply) override {
    std::string prefix("Hello ");
    std::cout << "Received request: " << request->name() << std::endl;
    reply->set_message(prefix + request->name());
    return Status::OK;
  }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  DemoMessageServiceImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();
  return 0;
}
