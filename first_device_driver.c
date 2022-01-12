#include <linux/modules.h>
#include <linux/init.h>
#include <linux/kernel.h>


/*
init function
*/

static int __init first_driver_init(void)
{
  printk(KERN_INFO "this my first linux driver");
  printk(KERN_INFO "driver successsfully inserted");
  
}
/*
exit function
*/

static void __exit first_driver_exit(void)
{
 printk(KERN_INFO "driver successfully removed"); 
}

module_init(first_driver_init);
module_exit(first_driver_exit);

MODULE_LICESNSE("GPL");
MODULE_VERSION("1.0");
MODULE_AUTHOR("ALI AKROUTI");
MODULE_DESCRIPTION("this my first module");
