#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#include <net/cfg80211.h>
#include <linux/netdevice.h>

struct ieee80211_txq_params p;
struct wiphy *w;

void print_net_dev(void)
{
	struct net_device *dev;

	dev = first_net_device(&init_net);
	while (dev) {
	    printk(KERN_INFO "atlas: found [%s]\n", dev->name);
	    dev = next_net_device(dev);
	}

}

static int __init hello_init(void)
{
	//w = wiphy_new(NULL, 0);
	print_net_dev();
	return 0;
}

static void __exit hello_cleanup(void)
{
	printk(KERN_INFO "atlas: and I shall never reset\n");
}

module_init(hello_init);
module_exit(hello_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Matthew Mellott");
MODULE_DESCRIPTION("A Simple Hello World module");
