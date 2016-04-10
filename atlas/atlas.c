#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#include <net/cfg80211.h>

struct ieee80211_txq_params p;
struct wiphy *w;

static int __init hello_init(void)
{
        w = wiphy_new(NULL, 0);
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
