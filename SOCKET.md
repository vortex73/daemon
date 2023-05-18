# Learnings on sockets and `sys/socket.h`.

### Socket Function
- creates an unbound socket and returns a file descriptor.
`int socket(int domain,int type,int protocol);` 
- domain : defines the communications domain.
> `domain` parameter specifies the type of addresses that the socket will use. 
>> some examples are AF_INET(for IPv4) and AF_INET6(for IPv6)
- type : type of socket to be created.
- protocol : the protocol to be used with the socket. If 0 is given , then a default unspecified protocol suited for the given type will be applied.

