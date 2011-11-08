!SLIDE
# ZeroMQ #
## Universal networking in Ruby ##
<div class="title_desc">
  <ul>
    <li>Emmanuel Bastien - @ebastien</li>
    <li>Ruby Drink-up of Sophia Antipolis</li>
    <li>8th November 2011</li>
  </ul>
</div>

!SLIDE
## Few common problems... ##

!SLIDE
* Multiple programming languages
* Low-level language bindings

!SLIDE
* Distributed applications
* Complex networking solutions

!SLIDE
* Concurrent processing
* Error-prone threads management

!SLIDE
# ZeroMQ #
## The NoSQL of messaging ##

!SLIDE
*To fix the world, we needed to do two things. One, to solve the general problem
of __"how to connect any code to any code, anywhere"__. Two, to wrap that up in
the __simplest possible building blocks__ that people could understand and use
easily.*

!SLIDE incremental
* LGPL networking library
* Socket-oriented
* Message-based
* High-level API
* Developed by [iMatix](http://www.imatix.com/)

!SLIDE
## Languages support ##
* C/C++
* Java
* C#
* Python
* Ruby
* Scala
* Smalltalk
* PHP
* Objective-C
* JavaScript
* Haskell
* Erlang
* ...

!SLIDE
## Simple APIs ##
    @@@ruby
    context = ZMQ::Context.new 1
    
    requester = context.socket ZMQ::REQ
    requester.connect "tcp://localhost:5555"
    
    requester.send_string "Hello"
    reply = ''
    requester.recv_string reply

!SLIDE
## APIs are transport-agnostic ##
* Local in-process: __inproc__
* Local inter-process: __ipc__
* Unicast: __tcp__
* Multicast: __pgm__

!SLIDE
## Messaging patterns ##
* request-reply
* publish-subscribe
* pipeline
* exclusive pair

!SLIDE
## Concurrency ##
* Thread-safe library and FFI extension
* Managed threads pool for async I/O
* No lock, no semaphore in application code

!SLIDE
## Robustness ##
* Automatic reconnection
* Monitored message queues
* Smart network error handling

!SLIDE
## Awesome when coupled with a portable serialization format ##
* [BERT](http://bert-rpc.org/)
* [MessagePack](http://msgpack.org/)
* [Protocol Buffers](http://code.google.com/p/protobuf/)
* [Avro](http://avro.apache.org/)
* [Thrift](http://thrift.apache.org/)

!SLIDE
## Support ##
* LGPL licence
* Commercial support from [iMatix](http://www.imatix.com/)

!SLIDE
## Resources ##
* [www.zeromq.org](http://www.zeromq.org/)
* [Learn ZeroMQ by example](https://github.com/andrewvc/learn-ruby-zeromq)
* [Ruby FFI extension for ZeroMQ](https://github.com/chuckremes/ffi-rzmq)

