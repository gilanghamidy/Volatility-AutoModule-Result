// Header files which is accessible via include folder
#include <net/udp.h>
#include <linux/notifier.h>
#include <linux/tty.h>
#include <net/protocol.h>
#include <asm-generic/int-ll64.h>
#include <linux/ioport.h>
#include <linux/termios.h>
#include <linux/utsname.h>
#include <linux/proc_fs.h>
#include <linux/fs_struct.h>
#include <linux/version.h>
#include <linux/clocksource.h>
#include <linux/sysfs.h>
#include <linux/pid_namespace.h>
#include <net/sock.h>
#include <linux/fs.h>
#include <net/inet_sock.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/tty_driver.h>
#include <net/net_namespace.h>
#include <net/route.h>
#include <linux/mount.h>
#include <linux/un.h>
#include <net/ip_fib.h>
#include <linux/fdtable.h>
#include <linux/netfilter/x_tables.h>
#include <linux/wait.h>
#include <linux/compiler.h>
#include <linux/time.h>
#include <net/tcp.h>
#include <linux/seqlock.h>
#include <linux/inetdevice.h>
#include <asm/termbits.h>
#include <net/sch_generic.h>
#include <linux/netfilter.h>
#include <net/ip.h>
#include </storage/linux-compile/linux/arch/x86/include/asm/clocksource.h>
#include <net/af_unix.h>
#include <linux/completion.h>
#include <asm-generic/posix_types.h>
#include <linux/spinlock_types.h>
#include <linux/radix-tree.h>
#include <linux/pid.h>

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
struct kmem_list3;
struct kthread_create_info;
struct log;
struct mnt_namespace;
struct mnt_pcp;
struct module_sect_attr;
struct module_sect_attrs;
struct mount;
struct radix_tree_node;
struct slab;
struct timekeeper;


// struct clocksource
// File: include/linux/clocksource.h
struct clocksource {
	/*
	 * Hotpath data, fits in a single cache line when the
	 * clocksource itself is cacheline aligned.
	 */
	cycle_t (*read)(struct clocksource *cs);
	cycle_t cycle_last;
	cycle_t mask;
	u32 mult;
	u32 shift;
	u64 max_idle_ns;
	u32 maxadj;
#ifdef CONFIG_ARCH_CLOCKSOURCE_DATA
	struct arch_clocksource_data archdata;
#endif

	const char *name;
	struct list_head list;
	int rating;
	int (*enable)(struct clocksource *cs);
	void (*disable)(struct clocksource *cs);
	unsigned long flags;
	void (*suspend)(struct clocksource *cs);
	void (*resume)(struct clocksource *cs);

	/* private: */
#ifdef CONFIG_CLOCKSOURCE_WATCHDOG
	/* Watchdog related data, used by the framework */
	struct list_head wd_list;
	cycle_t cs_last;
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
	u8			fa_state;
	struct rcu_head		rcu;
};

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
	int node;

	/* Result passed back to kthread_create() from kthreadd. */
	struct task_struct *result;
	struct completion done;

	struct list_head list;
};

// struct log
// File: kernel/printk.c
struct log {
	u64 ts_nsec;		/* timestamp in nanoseconds */
	u16 len;		/* length of entire record */
	u16 text_len;		/* length of text buffer */
	u16 dict_len;		/* length of dictionary buffer */
	u8 facility;		/* syslog facility */
	u8 flags:5;		/* internal record flags */
	u8 level:3;		/* syslog level */
};

// struct mnt_namespace
// File: fs/mount.h
struct mnt_namespace {
	atomic_t		count;
	struct mount *	root;
	struct list_head	list;
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

// struct timekeeper
// File: kernel/time/timekeeping.c
struct timekeeper {
	/* Current clocksource used for timekeeping. */
	struct clocksource	*clock;
	/* NTP adjusted clock multiplier */
	u32			mult;
	/* The shift value of the current clocksource. */
	u32			shift;
	/* Number of clock cycles in one NTP interval. */
	cycle_t			cycle_interval;
	/* Number of clock shifted nano seconds in one NTP interval. */
	u64			xtime_interval;
	/* shifted nano seconds left over when rounding cycle_interval */
	s64			xtime_remainder;
	/* Raw nano seconds accumulated per NTP interval. */
	u32			raw_interval;

	/* Current CLOCK_REALTIME time in seconds */
	u64			xtime_sec;
	/* Clock shifted nano seconds */
	u64			xtime_nsec;

	/* Difference between accumulated time and NTP time in ntp
	 * shifted nano seconds. */
	s64			ntp_error;
	/* Shift conversion between clock shifted nano seconds and
	 * ntp shifted nano seconds. */
	u32			ntp_error_shift;

	/*
	 * wall_to_monotonic is what we need to add to xtime (or xtime corrected
	 * for sub jiffie times) to get to monotonic time.  Monotonic is pegged
	 * at zero at system boot time, so wall_to_monotonic will be negative,
	 * however, we will ALWAYS keep the tv_nsec part positive so we can use
	 * the usual normalization.
	 *
	 * wall_to_monotonic is moved after resume from suspend for the
	 * monotonic time not to jump. We need to add total_sleep_time to
	 * wall_to_monotonic to get the real boot based time offset.
	 *
	 * - wall_to_monotonic is no longer the boot time, getboottime must be
	 * used instead.
	 */
	struct timespec		wall_to_monotonic;
	/* Offset clock monotonic -> clock realtime */
	ktime_t			offs_real;
	/* time spent in suspend */
	struct timespec		total_sleep_time;
	/* Offset clock monotonic -> clock boottime */
	ktime_t			offs_boot;
	/* The raw monotonic time for the CLOCK_MONOTONIC_RAW posix clock. */
	struct timespec		raw_time;
	/* Seqlock for all timekeeper values */
	seqlock_t		lock;
};

// Local definition for source structure
struct fib_alias fib_alias;
struct kmem_list3 kmem_list3;
struct kthread_create_info kthread_create_info;
struct log my_log;
struct module_sect_attrs module_sect_attrs;
struct slab slab;
struct timekeeper my_timekeeper;

// Unknown or undefined struct in this kernel version: 
// struct fib_node
// struct fn_hash
// struct fn_zone
// struct rt_hash_bucket
