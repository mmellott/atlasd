#include <stdio.h>

#include <netlink/netlink.h>
#include <netlink/genl/genl.h>
#include <linux/nl80211.h>

int main()
{
    struct nl_sock *sk = NULL;

    sk = nl_socket_alloc();
    genl_connect(sk);

    int driver_id = genl_ctrl_resolve(sk, "nl80211");

    printf("atlasd: dirver_id = %d\n", driver_id);

fail:
    if (sk) nl_socket_free(sk);
}

