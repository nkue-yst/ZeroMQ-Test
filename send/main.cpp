#include <zmq.hpp>

int main()
{
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::push);
    
    sock.bind("tcp://127.0.0.1:44100");

    std::vector<uint8_t> ivec = { 10, 20, 30 };
    zmq::message_t msg(ivec);
    sock.send(msg, zmq::send_flags::none);
}
