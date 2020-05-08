// Header files which is accessible via include folder
#include <linux/netfilter/x_tables.h>
#include <net/sch_generic.h>
#include <net/inet_sock.h>
#include <linux/tty_driver.h>
#include <linux/radix-tree.h>
#include <linux/netfilter.h>
#include <linux/spinlock_types.h>
#include <net/ip_fib.h>
#include <linux/pid_namespace.h>
#include <linux/pid.h>
#include <net/tcp.h>
#include <linux/termios.h>
#include <net/af_unix.h>
#include <linux/types.h>
#include <linux/ioport.h>
#include <linux/proc_fs.h>
#include <linux/version.h>
#include <linux/notifier.h>
#include <linux/compiler.h>
#include <linux/mount.h>
#include <net/udp.h>
#include <linux/completion.h>
#include <linux/list.h>
#include <linux/tty.h>
#include <linux/fs_struct.h>
#include <linux/wait.h>
#include <net/ip.h>
#include <net/route.h>
#include <asm/termbits.h>
#include <linux/fs.h>
#include <asm-generic/int-ll64.h>
#include <linux/inetdevice.h>
#include <net/net_namespace.h>
#include <linux/rcupdate.h>
#include <net/sock.h>
#include <linux/module.h>
#include </storage/linux-compile/linux/arch/x86/include/asm/spinlock_types.h>
#include <linux/fdtable.h>
#include <linux/un.h>
#include <linux/utsname.h>
#include <linux/sysfs.h>
#include <net/protocol.h>

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
struct array_cache;
struct fib_alias;
struct fib_node;
struct fn_hash;
struct fn_zone;
struct kmem_bufctl_t;
struct kmem_cache;
struct kmem_list3;
struct kthread_create_info;
struct module_sect_attr;
struct module_sect_attrs;
struct radix_tree_node;
struct rt_hash_bucket;
struct slab;


// struct array_cache
// File: mm/slab.c
struct array_cache {
	unsigned int avail;
	unsigned int limit;
	unsigned int batchcount;
	unsigned int touched;
	spinlock_t lock;
	void *entry[];	/*
			 * Must have this definition in here for the proper
			 * alignment of array_cache. Also simplifies accessing
			 * the entries.
			 */
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

// struct kmem_cache
// File: mm/slab.c
struct kmem_cache {
/* 1) per-cpu data, touched during every alloc/free */
	struct array_cache *array[NR_CPUS];
/* 2) Cache tunables. Protected by cache_chain_mutex */
	unsigned int batchcount;
	unsigned int limit;
	unsigned int shared;

	unsigned int buffer_size;
	u32 reciprocal_buffer_size;
/* 3) touched by every alloc & free from the backend */

	unsigned int flags;		/* constant flags */
	unsigned int num;		/* # of objs per slab */

/* 4) cache_grow/shrink */
	/* order of pgs per slab (2^n) */
	unsigned int gfporder;

	/* force GFP flags, e.g. GFP_DMA */
	gfp_t gfpflags;

	size_t colour;			/* cache colouring range */
	unsigned int colour_off;	/* colour offset */
	struct kmem_cache *slabp_cache;
	unsigned int slab_size;
	unsigned int dflags;		/* dynamic flags */

	/* constructor func */
	void (*ctor)(void *obj);

/* 5) cache creation/removal */
	const char *name;
	struct list_head next;

/* 6) statistics */
#if STATS
	unsigned long num_active;
	unsigned long num_allocations;
	unsigned long high_mark;
	unsigned long grown;
	unsigned long reaped;
	unsigned long errors;
	unsigned long max_freeable;
	unsigned long node_allocs;
	unsigned long node_frees;
	unsigned long node_overflow;
	atomic_t allochit;
	atomic_t allocmiss;
	atomic_t freehit;
	atomic_t freemiss;
#endif
#if DEBUG
	/*
	 * If debugging is enabled, then the allocator can add additional
	 * fields and/or padding to every object. buffer_size contains the total
	 * object size including these internal fields, the following two
	 * variables contain the offset to the user object and its size.
	 */
	int obj_offset;
	int obj_size;
#endif
	/*
	 * We put nodelists[] at the end of kmem_cache, because we want to size
	 * this array to nr_node_ids slots instead of MAX_NUMNODES
	 * (see kmem_cache_init())
	 * We still use [MAX_NUMNODES] and not [1] or [0] because cache_cache
	 * is statically defined, so we reserve the max number of nodes.
	 */
	struct kmem_list3 *nodelists[MAX_NUMNODES];
	/*
	 * Do not add fields after nodelists[]
	 */
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
	struct completion started;

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

// Local definition for source structure
struct fib_alias fib_alias;
struct fib_node fib_node;
struct fn_hash fn_hash;
struct fn_zone fn_zone;
struct kmem_cache kmem_cache;
struct kmem_list3 kmem_list3;
struct kthread_create_info kthread_create_info;
struct module_sect_attrs module_sect_attrs;
struct rt_hash_bucket rt_hash_bucket;
struct slab slab;

// Unknown or undefined struct in this kernel version: 
