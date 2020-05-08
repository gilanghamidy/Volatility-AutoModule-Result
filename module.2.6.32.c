// Header files which is accessible via include folder
#include <linux/clocksource.h>
#include <linux/un.h>
#include <linux/pid.h>
#include <linux/sysfs.h>
#include <net/tcp.h>
#include <linux/rcupdate.h>
#include <net/route.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/radix-tree.h>
#include <net/inet_sock.h>
#include <linux/pid_namespace.h>
#include <linux/fs.h>
#include <linux/completion.h>
#include <linux/wait.h>
#include <linux/inetdevice.h>
#include <linux/arch/x86/include/asm/spinlock_types.h>
#include <linux/tty_driver.h>
#include <net/af_unix.h>
#include <linux/spinlock_types.h>
#include <linux/ioport.h>
#include <linux/netfilter.h>
#include <linux/fs_struct.h>
#include <net/ip.h>
#include <net/sch_generic.h>
#include <linux/termios.h>
#include <linux/netfilter/x_tables.h>
#include <linux/list.h>
#include <net/ip_fib.h>
#include <net/protocol.h>
#include <linux/types.h>
#include <linux/notifier.h>
#include <asm-generic/int-ll64.h>
#include <linux/mount.h>
#include <asm/termbits.h>
#include <linux/utsname.h>
#include <linux/version.h>
#include <linux/fdtable.h>
#include <net/net_namespace.h>
#include <linux/tty.h>
#include <net/sock.h>
#include <linux/compiler.h>
#include <net/udp.h>

// Local definition for included structure
struct Qdisc qdisc;
struct atomic_notifier_head atomic_notifier_head;
struct fib_table fib_table;
struct files_struct files_struct;
struct in_device in_device;
struct inet_protosw inet_protosw;
struct inet_sock inet_sock;
struct module_kobject module_kobject;
struct nf_hook_ops nf_hook_ops;
struct nf_sockopt_ops nf_sockopt_ops;
struct pid pid;
struct pid_namespace pid_namespace;
struct radix_tree_root radix_tree_root;
struct resource resource;
struct sock sock;
struct tcp_seq_afinfo tcp_seq_afinfo;
struct tty_driver tty_driver;
struct tty_struct tty_struct;
struct udp_seq_afinfo udp_seq_afinfo;
struct unix_sock unix_sock;
struct uts_namespace uts_namespace;
struct vfsmount vfsmount;
struct xt_table xt_table;

// Source level struct definition
// Forward-declare
struct clocksource;
struct fib_alias;
struct fib_node;
struct fn_hash;
struct fn_zone;
struct kmem_bufctl_t;
struct kmem_list3;
struct kthread_create_info;
struct module_sect_attr;
struct module_sect_attrs;
struct radix_tree_node;
struct rt_hash_bucket;
struct slab;
struct timekeeper;


// struct clocksource
// File: include/linux/clocksource.h
struct clocksource {
	/*
	 * First part of structure is read mostly
	 */
	char *name;
	struct list_head list;
	int rating;
	cycle_t (*read)(struct clocksource *cs);
	int (*enable)(struct clocksource *cs);
	void (*disable)(struct clocksource *cs);
	cycle_t mask;
	u32 mult;
	u32 shift;
	unsigned long flags;
	cycle_t (*vread)(void);
	void (*resume)(void);
#ifdef CONFIG_IA64
	void *fsys_mmio;        /* used by fsyscall asm code */
#define CLKSRC_FSYS_MMIO_SET(mmio, addr)      ((mmio) = (addr))
#else
#define CLKSRC_FSYS_MMIO_SET(mmio, addr)      do { } while (0)
#endif

	/*
	 * Second part is written at each timer interrupt
	 * Keep it in a different cache line to dirty no
	 * more than one cache line.
	 */
	cycle_t cycle_last ____cacheline_aligned_in_smp;

#ifdef CONFIG_CLOCKSOURCE_WATCHDOG
	/* Watchdog related data, used by the framework */
	struct list_head wd_list;
	cycle_t wd_last;
#endif
};

// struct fib_alias
// File: net/ipv4/fib_lookup.h
struct fib_alias {
	struct list_head	fa_list;
	struct fib_info		*fa_info;
	u8			fa_tos;
	u8			fa_type;
	u8			fa_scope;
	u8			fa_state;
#ifdef CONFIG_IP_FIB_TRIE
	struct rcu_head		rcu;
#endif
};

// struct fib_node
// File: net/ipv4/fib_hash.c
struct fib_node {
	struct hlist_node	fn_hash;
	struct list_head	fn_alias;
	__be32			fn_key;
	struct fib_alias        fn_embedded_alias;
};

// struct fn_hash
// File: net/ipv4/fib_hash.c
struct fn_hash {
	struct fn_zone	*fn_zones[33];
	struct fn_zone	*fn_zone_list;
};

// struct fn_zone
// File: net/ipv4/fib_hash.c
struct fn_zone {
	struct fn_zone		*fz_next;	/* Next not empty zone	*/
	struct hlist_head	*fz_hash;	/* Hash table pointer	*/
	int			fz_nent;	/* Number of entries	*/

	int			fz_divisor;	/* Hash divisor		*/
	u32			fz_hashmask;	/* (fz_divisor - 1)	*/
#define FZ_HASHMASK(fz)		((fz)->fz_hashmask)

	int			fz_order;	/* Zone order		*/
	__be32			fz_mask;
#define FZ_MASK(fz)		((fz)->fz_mask)
};

// struct kmem_bufctl_t
// File: mm/slab.c
typedef unsigned int kmem_bufctl_t;

// struct kmem_list3
// File: mm/slab.c
struct kmem_list3 {
	struct list_head slabs_partial;	/* partial list first, better asm code */
	struct list_head slabs_full;
	struct list_head slabs_free;
	unsigned long free_objects;
	unsigned int free_limit;
	unsigned int colour_next;	/* Per-node cache coloring */
	spinlock_t list_lock;
	struct array_cache *shared;	/* shared per node */
	struct array_cache **alien;	/* on other nodes */
	unsigned long next_reap;	/* updated without locking */
	int free_touched;		/* updated without locking */
};

// struct kthread_create_info
// File: kernel/kthread.c
struct kthread_create_info
{
	/* Information passed to kthread() from kthreadd. */
	int (*threadfn)(void *data);
	void *data;

	/* Result passed back to kthread_create() from kthreadd. */
	struct task_struct *result;
	struct completion done;

	struct list_head list;
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

// struct radix_tree_node
// File: lib/radix-tree.c
struct radix_tree_node {
	unsigned int	height;		/* Height from the bottom */
	unsigned int	count;
	struct rcu_head	rcu_head;
	void		*slots[RADIX_TREE_MAP_SIZE];
	unsigned long	tags[RADIX_TREE_MAX_TAGS][RADIX_TREE_TAG_LONGS];
};

// struct rt_hash_bucket
// File: net/ipv4/route.c
struct rt_hash_bucket {
	struct rtable	*chain;
};

// struct slab
// File: mm/slab.c
struct slab {
	struct list_head list;
	unsigned long colouroff;
	void *s_mem;		/* including colour offset */
	unsigned int inuse;	/* num of objs active in slab */
	kmem_bufctl_t free;
	unsigned short nodeid;
};

// struct timekeeper
// File: kernel/time/timekeeping.c
struct timekeeper {
	/* Current clocksource used for timekeeping. */
	struct clocksource *clock;
	/* The shift value of the current clocksource. */
	int	shift;

	/* Number of clock cycles in one NTP interval. */
	cycle_t cycle_interval;
	/* Number of clock shifted nano seconds in one NTP interval. */
	u64	xtime_interval;
	/* Raw nano seconds accumulated per NTP interval. */
	u32	raw_interval;

	/* Clock shifted nano seconds remainder not stored in xtime.tv_nsec. */
	u64	xtime_nsec;
	/* Difference between accumulated time and NTP time in ntp
	 * shifted nano seconds. */
	s64	ntp_error;
	/* Shift conversion between clock shifted nano seconds and
	 * ntp shifted nano seconds. */
	int	ntp_error_shift;
	/* NTP adjusted clock multiplier */
	u32	mult;
};

// Local definition for source structure
struct fib_alias fib_alias;
struct fib_node fib_node;
struct fn_hash fn_hash;
struct fn_zone fn_zone;
struct kmem_list3 kmem_list3;
struct kthread_create_info kthread_create_info;
struct module_sect_attrs module_sect_attrs;
struct rt_hash_bucket rt_hash_bucket;
struct slab slab;
struct timekeeper my_timekeeper;

// Unknown or undefined struct in this kernel version: 
// struct log
