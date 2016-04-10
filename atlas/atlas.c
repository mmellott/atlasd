#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_init(void)
{
	printk(KERN_INFO "atlas: my burden is heavy...\n");
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
