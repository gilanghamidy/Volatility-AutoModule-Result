#include <linux/module.h>
#include <linux/version.h>
#if LINUX_VERSION_CODE == KERNEL_VERSION(2,6,29)
#include "module.2.6.29.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(2,6,30)
#include "module.2.6.30.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(2,6,31)
#include "module.2.6.31.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(2,6,32)
#include "module.2.6.32.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(2,6,33)
#include "module.2.6.33.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(2,6,34)
#include "module.2.6.34.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(2,6,35)
#include "module.2.6.35.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(2,6,36)
#include "module.2.6.36.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(2,6,37)
#include "module.2.6.37.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(2,6,38)
#include "module.2.6.38.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(2,6,39)
#include "module.2.6.39.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,0,0)
#include "module.3.0.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,1,0)
#include "module.3.1.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,10,0)
#include "module.3.10.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,11,0)
#include "module.3.11.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,12,0)
#include "module.3.12.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,13,0)
#include "module.3.13.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,14,0)
#include "module.3.14.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,15,0)
#include "module.3.15.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,16,0)
#include "module.3.16.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,17,0)
#include "module.3.17.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,18,0)
#include "module.3.18.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,19,0)
#include "module.3.19.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,2,0)
#include "module.3.2.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,3,0)
#include "module.3.3.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,4,0)
#include "module.3.4.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,5,0)
#include "module.3.5.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,6,0)
#include "module.3.6.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,7,0)
#include "module.3.7.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,8,0)
#include "module.3.8.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(3,9,0)
#include "module.3.9.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,0,0)
#include "module.4.0.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,1,0)
#include "module.4.1.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,10,0)
#include "module.4.10.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,11,0)
#include "module.4.11.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,12,0)
#include "module.4.12.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,13,0)
#include "module.4.13.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,14,0)
#include "module.4.14.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,16,0)
#include "module.4.16.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,17,0)
#include "module.4.17.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,18,0)
#include "module.4.18.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,19,0)
#include "module.4.19.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,2,0)
#include "module.4.2.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,20,0)
#include "module.4.20.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,3,0)
#include "module.4.3.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,4,0)
#include "module.4.4.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,5,0)
#include "module.4.5.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,6,0)
#include "module.4.6.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,7,0)
#include "module.4.7.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,8,0)
#include "module.4.8.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(4,9,0)
#include "module.4.9.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(5,0,0)
#include "module.5.0.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(5,1,0)
#include "module.5.1.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(5,2,0)
#include "module.5.2.c"
#elif LINUX_VERSION_CODE == KERNEL_VERSION(5,3,0)
#include "module.5.3.c"
#else
#include "module.orig.c"
#endif
