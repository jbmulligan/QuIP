//#ifdef HAVE_DEV_VGAT

#include "quip_config.h"

// What is this?  A custom driver???

#ifdef hAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif

#ifdef HAVE_SYS_IOCTL_H
#include <sys/ioctl.h>
#endif

#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>	/* exit */
#endif

#include "quip_prot.h"
#include "vgat_ioctl.h"

static int vgat_fd=(-1);

#define vgat_init() _vgat_init(SINGLE_QSP_ARG)

static void _vgat_init(SINGLE_QSP_ARG_DECL)
{
	static int warned=0;

	assert( vgat_fd < 0 );

	vgat_fd=open("/dev/vgat",O_RDONLY);
	if( vgat_fd < 0 ){
		if( !warned ){
			perror("open /dev/vgat");
			warn("unable to open /dev/vgat");
			warned=1;
		}
	}
}


void vbl_wait()
{
	int rv;

	if( vgat_fd < 0 ) vgat_init();
	if( vgat_fd < 0 ) return;

	if( ioctl(vgat_fd,VGAT_VBL_WAIT,&rv) < 0 ){
		perror("ioctl");
		exit(1);
	}
}

//#endif /* HAVE_DEV_VGAT */

