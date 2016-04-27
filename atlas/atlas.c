#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>

#include <net/cfg80211.h>
#include <net/mac80211.h>
#include <linux/netdevice.h>

void print_net_dev(void);
void set_cw(struct net_device *dev);

void print_net_dev(void)
{
	struct net_device *dev;

	dev = first_net_device(&init_net);
	while (dev) {
		printk(KERN_INFO "atlas: found [%s]\n", dev->name);
		if (strcmp(dev->name, "wlan0")) {
			set_cw(dev);
		}

		dev = next_net_device(dev);
	}
}

void set_cw(struct net_device *dev)
{
	struct ieee80211_txq_params txq_params;
	int ac, result;

	printk(KERN_INFO "atlas: setting cw\n");

	for (ac = 0; ac < IEEE80211_NUM_ACS; ac++) {
		txq_params.ac = ac;
		txq_params.txop = 0;
		txq_params.cwmin = 1;
		txq_params.cwmax = 7;
		txq_params.aifs = 2;
		result = set_txq_params(dev->ieee80211_ptr->wiphy, &txq_params);
	}
}

static int __init hello_init(void)
{
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
