#include <stdio.h>

#include <netlink/netlink.h>
#include <netlink/socket.h>
#include <netlink/msg.h>

int main()
{
    struct nl_sock *sk = NULL;
    struct nl_msg *msg = NULL;

    sk = nl_socket_alloc();
    msg = nlmsg_alloc();

    printf("Goodbye, cruel world...\n");

fail:
    if (sk) nl_socket_free(sk);
    if (msg) nlmsg_free(msg);
}

