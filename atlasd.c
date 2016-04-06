#include <stdio.h>

#include <netlink/netlink.h>
#include <netlink/genl/genl.h>
#include <linux/nl80211.h>

static int get_cw(struct nl_msg *msg, void *arg)
{
    nl_msg_dump(msg, stdout);

    return NL_SKIP;
}

int main()
{
    struct nl_sock *sk = NULL;
    struct nl_msg *msg;

    sk = nl_socket_alloc();
    genl_connect(sk);

    int driver_id = genl_ctrl_resolve(sk, "nl80211");
    printf("atlasd: dirver_id = %d\n", driver_id);

    nl_socket_modify_cb(sk, NL_CB_VALID, NL_CB_CUSTOM, get_cw, NULL);

    printf("atlasd: getting info for wlan0\n");

    msg = nlmsg_alloc();
    int if_index = if_nametoindex("wlan0");

    /* setup message */
    genlmsg_put(msg, 0, 0, driver_id, 0, 0, NL80211_CMD_GET_INTERFACE, 0);
    NLA_PUT_U32(msg, NL80211_ATTR_IFINDEX, if_index);

    /* send/recv/ack */
    int r = nl_send_auto_complete(sk, msg);
    printf("atlasd: nl_send_auto_complete returned %d\n", r);
    nl_recvmsgs_default(sk);  // Retrieve the kernel's answer.
    nl_wait_for_ack(sk);

nla_put_failure: /* from NLA_PUT_* macros */
fail:
    if (sk) nl_socket_free(sk);
    if (msg) nlmsg_free(msg);
}

