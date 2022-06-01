#include <iostream>
#include <vector>

#include <zmq.hpp>

int main()
{
    zmq::context_t ctx;
    zmq::socket_t sock(ctx, zmq::socket_type::pull);

    sock.connect("tcp://127.0.0.1:44100");
    
    zmq::message_t buf;
    auto res = sock.recv(buf, zmq::recv_flags::none);

    std::vector ivec(buf.data<uint8_t>(), buf.data<uint8_t>() + buf.size() / sizeof(uint8_t));

    std::cout << buf << std::endl;

    for (auto item : ivec)
        std::cout << (int32_t)item << std::endl;
}
