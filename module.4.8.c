// Header files which is accessible via include folder
#include <net/af_unix.h>
#include <linux/inetdevice.h>
#include <net/ip.h>
#include <linux/termios.h>
#include <net/inet_sock.h>
#include <linux/tty.h>
#include <linux/fdtable.h>
#include <net/protocol.h>
#include <linux/rbtree.h>
#include <linux/wait.h>
#include <net/tcp.h>
#include <linux/sysfs.h>
#include <linux/proc_fs.h>
#include <linux/timekeeper_internal.h>
#include <uapi/asm-generic/int-ll64.h>
#include <net/sch_generic.h>
#include <linux/lockref.h>
#include <linux/notifier.h>
#include <linux/fs_struct.h>
#include <linux/fs.h>
#include <linux/fs_pin.h>
#include <linux/pid_namespace.h>
#include <linux/spinlock_types.h>
#include <linux/uidgid.h>
#include <linux/ioport.h>
#include <linux/utsname.h>
#include <linux/netfilter.h>
#include <net/udp.h>
#include <linux/radix-tree.h>
#include <linux/tty_driver.h>
#include <linux/un.h>
#include <linux/types.h>
#include <asm-generic/int-ll64.h>
#include <linux/pid.h>
#include <linux/ns_common.h>
#include <net/route.h>
#include <net/sock.h>
#include <linux/mount.h>
#include <linux/module.h>
#include <asm/termbits.h>
#include <linux/netfilter/x_tables.h>
#include <linux/compiler.h>
#include <net/ip_fib.h>
#include <net/net_namespace.h>
#include <linux/rbtree_latch.h>
#include <linux/version.h>

// Local definition for included structure
struct Qdisc qdisc;
struct atomic_notifier_head atomic_notifier_head;
struct fib_table fib_table;
struct files_struct files_struct;
struct in_device in_device;
struct inet_protosw inet_protosw;
struct inet_sock inet_sock;
struct latch_tree_root ltr;
struct lockref lockref;
struct module_kobject module_kobject;
struct nf_hook_ops nf_hook_ops;
struct nf_sockopt_ops nf_sockopt_ops;
struct pid pid;
struct pid_namespace pid_namespace;
struct radix_tree_root radix_tree_root;
struct resource resource;
struct sock sock;
struct tcp_seq_afinfo tcp_seq_afinfo;
struct timekeeper my_timekeeper;
struct tty_driver tty_driver;
struct tty_struct tty_struct;
struct udp_seq_afinfo udp_seq_afinfo;
struct unix_sock unix_sock;
struct uts_namespace uts_namespace;
struct vfsmount vfsmount;
struct xt_table xt_table;

// Source level struct definition
// Forward-declare
struct array_cache;
struct fib_alias;
struct kthread_create_info;
struct mnt_namespace;
struct mnt_pcp;
struct module_sect_attr;
struct module_sect_attrs;
struct mount;
struct proc_dir_entry;


// struct array_cache
// File: mm/slab.c
struct array_cache {
	unsigned int avail;
	unsigned int limit;
	unsigned int batchcount;
	unsigned int touched;
	void *entry[];	/*
			 * Must have this definition in here for the proper
			 * alignment of array_cache. Also simplifies accessing
			 * the entries.
			 */
};

// struct fib_alias
// File: net/ipv4/fib_lookup.h
struct fib_alias {
	struct hlist_node	fa_list;
	struct fib_info		*fa_info;
	u8			fa_tos;
	u8			fa_type;
	u8			fa_state;
	u8			fa_slen;
	u32			tb_id;
	s16			fa_default;
	struct rcu_head		rcu;
};

// struct kthread_create_info
// File: kernel/kthread.c
struct kthread_create_info
{
	/* Information passed to kthread() from kthreadd. */
	int (*threadfn)(void *data);
	void *data;
	int node;

	/* Result passed back to kthread_create() from kthreadd. */
	struct task_struct *result;
	struct completion *done;

	struct list_head list;
};

// struct mnt_namespace
// File: fs/mount.h
struct mnt_namespace {
	atomic_t		count;
	struct ns_common	ns;
	struct mount *	root;
	struct list_head	list;
	struct user_namespace	*user_ns;
	u64			seq;	/* Sequence number to prevent loops */
	wait_queue_head_t poll;
	u64 event;
};

// struct mnt_pcp
// File: fs/mount.h
struct mnt_pcp {
	int mnt_count;
	int mnt_writers;
};

// struct module_sect_attr
// File: kernel/module.c
struct module_sect_attr {
	struct module_attribute mattr;
	char *name;
	unsigned long address;
};

// struct module_sect_attrs
// File: kernel/module.c
struct module_sect_attrs {
	struct attribute_group grp;
	unsigned int nsections;
	struct module_sect_attr attrs[0];
};

// struct mount
// File: fs/mount.h
struct mount {
	struct hlist_node mnt_hash;
	struct mount *mnt_parent;
	struct dentry *mnt_mountpoint;
	struct vfsmount mnt;
	union {
		struct rcu_head mnt_rcu;
		struct llist_node mnt_llist;
	};
#ifdef CONFIG_SMP
	struct mnt_pcp __percpu *mnt_pcp;
#else
	int mnt_count;
	int mnt_writers;
#endif
	struct list_head mnt_mounts;	/* list of children, anchored here */
	struct list_head mnt_child;	/* and going through their mnt_child */
	struct list_head mnt_instance;	/* mount instance on sb->s_mounts */
	const char *mnt_devname;	/* Name of device e.g. /dev/dsk/hda1 */
	struct list_head mnt_list;
	struct list_head mnt_expire;	/* link in fs-specific expiry list */
	struct list_head mnt_share;	/* circular list of shared mounts */
	struct list_head mnt_slave_list;/* list of slave mounts */
	struct list_head mnt_slave;	/* slave list entry */
	struct mount *mnt_master;	/* slave is on master->mnt_slave_list */
	struct mnt_namespace *mnt_ns;	/* containing namespace */
	struct mountpoint *mnt_mp;	/* where is it mounted */
	struct hlist_node mnt_mp_list;	/* list mounts with the same mountpoint */
#ifdef CONFIG_FSNOTIFY
	struct hlist_head mnt_fsnotify_marks;
	__u32 mnt_fsnotify_mask;
#endif
	int mnt_id;			/* mount identifier */
	int mnt_group_id;		/* peer group identifier */
	int mnt_expiry_mark;		/* true if marked for expiry */
	struct hlist_head mnt_pins;
	struct fs_pin mnt_umount;
	struct dentry *mnt_ex_mountpoint;
};

// struct proc_dir_entry
// File: fs/proc/internal.h
struct proc_dir_entry {
	unsigned int low_ino;
	umode_t mode;
	nlink_t nlink;
	kuid_t uid;
	kgid_t gid;
	loff_t size;
	const struct inode_operations *proc_iops;
	const struct file_operations *proc_fops;
	struct proc_dir_entry *parent;
	struct rb_root subdir;
	struct rb_node subdir_node;
	void *data;
	atomic_t count;		/* use count */
	atomic_t in_use;	/* number of callers into module in progress; */
			/* negative -> it's going away RSN */
	struct completion *pde_unload_completion;
	struct list_head pde_openers;	/* who did ->open, but not ->release */
	spinlock_t pde_unload_lock; /* proc_fops checks and pde_users bumps */
	u8 namelen;
	char name[];
};

// Local definition for source structure
struct fib_alias fib_alias;
struct kthread_create_info kthread_create_info;
struct module_sect_attrs module_sect_attrs;

// Unknown or undefined struct in this kernel version: 
// struct fib_node
// struct fn_hash
// struct fn_zone
// struct kmem_list3
// struct log
// struct rt_hash_bucket
// struct slab
