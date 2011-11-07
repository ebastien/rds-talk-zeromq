#include <zmq.hpp>
#include <msgpack.hpp>
#include <vector>
#include <string>

using namespace std;

int main() {
  zmq::context_t context (1);
  zmq::socket_t socket (context, ZMQ_REP);
  socket.bind ("tcp://*:5555");

  while (true) {
    zmq::message_t request;
    socket.recv (&request);

    msgpack::unpacked msg;
    msgpack::unpack(&msg, static_cast<char*>(request.data()), request.size());
    msgpack::object obj = msg.get();
    vector<string> vec;
    obj.convert(&vec);

    vec.push_back("2011");

    msgpack::sbuffer sbuf;
    msgpack::pack(sbuf, vec);

    zmq::message_t reply (sbuf.size());
    memcpy (reply.data(), sbuf.data(), sbuf.size());
    socket.send (reply);
  }
  return 0;
}
