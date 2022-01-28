
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

/*init function */

int value_Ext,array_valueExt[4];
char* nameExt;
int cb_value_Ext=0;

module_param(value_Ext,int,S_IRUSR|S_IWUSR);
module_param(nameExt,charp,S_IRUSR|S_IWUSR);
module_param_array(array_valueExt,int,NULL,S_IRUSR|S_IWUSR);
int notify_param(const char* val,const struct kernel_param *kp)
{
int res=param_set_int(val,kp);
       if(res==0) {
                printk(KERN_INFO "Call back function called...\n");
                printk(KERN_INFO "New value of cb_valueETX = %d\n", cb_value_Ext);
                return 0;
        }
        return -1;
}

const struct kernel_param_ops my_param_ops=
{
   .set =&notify_param,
   .get=&param_get_int,
};
module_param_cb(cb_value_Ext,&my_param_ops,&cb_value_Ext,S_IRUGO|S_IWUSR);


static int __init devicedriver_argument_init(void)
{
	int i;
   printk(KERN_INFO"device driver has inserted successfully");
   printk(KERN_INFO"value_EXT =%d \n",value_Ext);
   printk(KERN_INFO"nameExt =%s \n",nameExt);
   for( i=0;i<4;i++)
   {

   printk(KERN_INFO"array_valueExt[%d] =%d \n",i,array_valueExt[i]);
   }
return 0;   
}

static void __exit devicedriver_argument_exit(void)
{
   printk(KERN_INFO"device driver has unloaded succsfully");
}

module_init(devicedriver_argument_init);
module_exit(devicedriver_argument_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ali akrouti");
MODULE_VERSION("v1.0");
MODULE_DESCRIPTION("pass argument to device driver");
