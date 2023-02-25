#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

/* Meta info*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sapargali");
MODULE_DESCRIPTION("A simple LKM to demostrate the use of parameters");

/* Kernel Module's Parametrs */
static unsigned int gpio_nr = 12;
static char *device_name = "Sapar";

module_param(gpio_nr, uint, S_TRUGO);
module_param(device_name, charp, S_TRUGO);

MODULE_PARM_DESC(gpio_nr, "Nr. of GPIO to use in this LKM");
MODULE_PARAM_DESC(device_name, "Device name to use in this LKM");

/*
  This function is called, when the module is loaded into the kernel
*/
static int __init ModuleInit(void) {
  printk("gpio_nr = %u\n", gpio_nr);
  printk("device_name = %s\n", device_name);
  printk("hello, new Kernel!\n");
  return 0;
}

/*
  This function is called, when the module is removed from the kernel
*/
static void __exit ModuleExit(void) {
  printk("Goodbye, Kernel\n");
}
