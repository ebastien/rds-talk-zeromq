require 'ffi-rzmq'
require 'msgpack'

context = ZMQ::Context.new 1

requester = context.socket ZMQ::REQ
requester.connect "tcp://localhost:5555"

request = MessagePack.pack ["Hello", "Riviera.rb"]
puts request.inspect
requester.send_string request

reply = ''
requester.recv_string reply
puts reply.inspect
puts MessagePack.unpack(reply)
