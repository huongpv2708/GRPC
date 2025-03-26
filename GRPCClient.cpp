#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "aglcom.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using aglcom::DemoMessage;
using aglcom::DemoRequest;
using aglcom::DemoReply;

class DemoMessageClient {
 public:
  DemoMessageClient(std::shared_ptr<Channel> channel) : stub_(DemoMessage::NewStub(channel)) {}

  std::string SendDemo(const std::string& name) {
    DemoRequest request;
    request.set_name(name);

    DemoReply reply;
    ClientContext context;

    Status status = stub_->SendDemo(&context, request, &reply);

    if (status.ok()) {
      return reply.message();
    } else {
      std::cout << status.error_code() << ": " << status.error_message() << std::endl;
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<DemoMessage::Stub> stub_;
};

int main(int argc, char** argv) {
  DemoMessageClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
  std::string name("Demo msg");
  std::string reply = client.SendDemo(name);
  std::cout << "Client received: " << reply << std::endl;

  return 0;
}
