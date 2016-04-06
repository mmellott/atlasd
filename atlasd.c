#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>

#include <linux/netlink.h>
#include <linux/nl80211.h>

#define MAX_PAYLOAD 1024

struct sockaddr_nl src, dst;
struct nlmsghdr *nlh = NULL;
struct iovec iov;
int sock;
struct msghdr msg;

int main()
{
    sock = socket(AF_NETLINK, SOCK_RAW, NETLINK_ROUTE);
    if (sock < 0) {
        return -1;
    }

    memset(&src, 0, sizeof (src));
    src.nl_family = AF_NETLINK;
    src.nl_pid = getpid();

    bind(sock, (struct sockaddr *) &src, sizeof (src));

    memset(&dst, 0, sizeof (dst));
    dst.nl_family = AF_NETLINK;
    dst.nl_pid = 0; /* For Linux Kernel */
    dst.nl_groups = 0; /* unicast */

    nlh = (struct nlmsghdr *) malloc(NLMSG_SPACE(MAX_PAYLOAD));
    memset(nlh, 0, NLMSG_SPACE(MAX_PAYLOAD));
    nlh->nlmsg_len = NLMSG_SPACE(MAX_PAYLOAD);
    nlh->nlmsg_pid = getpid();
    nlh->nlmsg_flags = 0;

    strcpy(NLMSG_DATA(nlh), "Hello");

    iov.iov_base = (void *) nlh;
    iov.iov_len = nlh->nlmsg_len;
    msg.msg_name = (void *) &dst;
    msg.msg_namelen = sizeof(dst);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    printf("Sending message to kernel\n");
    sendmsg(sock, &msg, 0);
    printf("Waiting for message from kernel\n");

    /* Read message from kernel */
    recvmsg(sock, &msg, 0);
    printf("Received message payload: %s\n", NLMSG_DATA(nlh));
    close(sock);
}
