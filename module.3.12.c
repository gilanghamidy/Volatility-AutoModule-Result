// Header files which is accessible via include folder
#include <linux/spinlock_types.h>
#include <linux/proc_fs.h>
#include <linux/pid_namespace.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/tty.h>
#include <net/ip_fib.h>
#include <linux/timekeeper_internal.h>
#include <linux/tty_driver.h>
#include <net/tcp.h>
#include <net/af_unix.h>
#include <linux/sysfs.h>
#include <linux/lockref.h>
#include <linux/ioport.h>
#include <linux/netfilter/x_tables.h>
#include <net/ip.h>
#include <net/sock.h>
#include <linux/utsname.h>
#include <asm/termbits.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/netfilter.h>
#include <linux/completion.h>
#include <linux/radix-tree.h>
#include <linux/termios.h>
#include <net/inet_sock.h>
#include <net/udp.h>
#include <linux/un.h>
#include <net/protocol.h>
#include <net/net_namespace.h>
#include <linux/compiler.h>
#include <uapi/asm-generic/int-ll64.h>
#include <linux/version.h>
#include <net/sch_generic.h>
#include <linux/mount.h>
#include <linux/wait.h>
#include <asm-generic/int-ll64.h>
#include <linux/fs_struct.h>
#include <linux/notifier.h>
#include <linux/inetdevice.h>
#include <net/route.h>
#include <linux/fdtable.h>

// Local definition for included structure
struct Qdisc qdisc;
struct atomic_notifier_head atomic_notifier_head;
struct fib_table fib_table;
struct files_struct files_struct;
struct in_device in_device;
struct inet_protosw inet_protosw;
struct inet_sock inet_sock;
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
struct fib_alias;
struct kthread_create_info;
struct mnt_namespace;
struct mnt_pcp;
struct module_sect_attr;
struct module_sect_attrs;
struct mount;
struct radix_tree_node;
struct slab;


// struct fib_alias
// File: net/ipv4/fib_lookup.h
struct fib_alias {
	struct list_head	fa_list;
	struct fib_info		*fa_info;
	u8			fa_tos;
	u8			fa_type;
	u8			fa_state;
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
	struct completion done;

	struct list_head list;
};

// struct mnt_namespace
// File: fs/mount.h
struct mnt_namespace {
	atomic_t		count;
	unsigned int		proc_inum;
	struct mount *	root;
	struct list_head	list;
	struct user_namespace	*user_ns;
	u64			seq;	/* Sequence number to prevent loops */
	wait_queue_head_t poll;
	int event;
};

// struct mnt_pcp
// File: fs/mount.h
struct mnt_pcp {
	int mnt_count;
	int mnt_writers;
};

// struct module_sect_attr
// File: kernel/module.c
struct module_sect_attr
{
	struct module_attribute mattr;
	char *name;
	unsigned long address;
};

// struct module_sect_attrs
// File: kernel/module.c
struct module_sect_attrs
{
	struct attribute_group grp;
	unsigned int nsections;
	struct module_sect_attr attrs[0];
};

// struct mount
// File: fs/mount.h
struct mount {
	struct list_head mnt_hash;
	struct mount *mnt_parent;
	struct dentry *mnt_mountpoint;
	struct vfsmount mnt;
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
#ifdef CONFIG_FSNOTIFY
	struct hlist_head mnt_fsnotify_marks;
	__u32 mnt_fsnotify_mask;
#endif
	int mnt_id;			/* mount identifier */
	int mnt_group_id;		/* peer group identifier */
	int mnt_expiry_mark;		/* true if marked for expiry */
	int mnt_pinned;
	int mnt_ghosts;
};

// struct radix_tree_node
// File: lib/radix-tree.c
struct radix_tree_node {
	unsigned int	height;		/* Height from the bottom */
	unsigned int	count;
	union {
		struct radix_tree_node *parent;	/* Used when ascending tree */
		struct rcu_head	rcu_head;	/* Used when freeing node */
	};
	void __rcu	*slots[RADIX_TREE_MAP_SIZE];
	unsigned long	tags[RADIX_TREE_MAX_TAGS][RADIX_TREE_TAG_LONGS];
};

// struct slab
// File: mm/slab.c
struct slab {
	union {
		struct {
			struct list_head list;
			unsigned long colouroff;
			void *s_mem;		/* including colour offset */
			unsigned int inuse;	/* num of objs active in slab */
			kmem_bufctl_t free;
			unsigned short nodeid;
		};
		struct slab_rcu __slab_cover_slab_rcu;
	};
};

// Local definition for source structure
struct fib_alias fib_alias;
struct kthread_create_info kthread_create_info;
struct module_sect_attrs module_sect_attrs;
struct slab slab;

// Unknown or undefined struct in this kernel version: 
// struct fib_node
// struct fn_hash
// struct fn_zone
// struct kmem_list3
// struct log
// struct rt_hash_bucket
