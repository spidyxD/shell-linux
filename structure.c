#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/list.h>
#include <linux/module.h>
/* This structure */
	struct birthday {
		int day;
		int month;
		int year;
	struct list_head list;
	}
/* Inserting elements into the linked list*/
	static LIST_HEAD(birthday_list);
	struct birthday *person;
	person = kmalloc(sizeof(*person), GFP KERNEL);
	person->day = 2;
	person->month= 8;
	person->year = 1995;
	INIT_LIST_HEAD(&person->list);
/* We can then add this instance to the end of the linked list */
	list_add_tail(&person->list, &birthday_list);
/* Traversing the list involves using the list for each entry() Macro */
	struct birthday *ptr;
	list_for_each_entry(ptr, &birthday_list, list) {
/* on each iteration ptr points */
/* to the next birthday struct */
	}
/* Removing elements from the list involves using the list del() macro, which
is passed a pointer to struct list head */
	list_del(struct list_head *element);
	
	struct birthday *ptr, *next;
	list_for_each_entry_safe(ptr,next,&birthday_list,list) {
/* on each iteration ptr points */
/* to the next birthday struct */
	list_del(&ptr->list);
	kfree(ptr);
	}
	///usr/src/linux-headers-4.10.0-32-generic/include/linux/module.h
* This function is called when the module is loaded. */
	int structure_init(void){
		printk(KERN_INFO "Hello.....Loading Module\n");
		return 0;
	}
/* This function is called when the module is removed. */
	void structure_exit(void){
		printk(KERN_INFO "Good bye......Removing Module\n");
	}
/* Macros for registering module entry and exit points. */
	module_init(structure_init);
	module_exit(structure_exit);
	MODULE_LICENSE("GPL");
	MODULE_DESCRIPTION("structure Module");
	MODULE_AUTHOR("Addiel");
