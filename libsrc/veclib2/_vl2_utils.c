//#include "quip_config.h"
//#include "quip_prot.h"
#include "my_vl2.h"
//#include "veclib/vl2_port.h"
//#include "veclib/platform_funcs.h"
#include "veclib_api.h"

//#define MEM_SIZE (16)//suppose we have a vector with 128 elements
#define MAX_SOURCE_SIZE (0x100000)

//In general Intel CPU and NV/AMD's GPU are in different platforms
//But in Mac OSX, all the OpenCL devices are in the platform "Apple"

#define MAX_CL_PLATFORMS	3

#define MAX_PARAM_SIZE	128

#define ERROR_CASE(code,string)	case code: msg = string; break;

void PF_FUNC_NAME(init)(SINGLE_QSP_ARG_DECL)
{
	// anything to do?
}

void PF_FUNC_NAME(alloc_data)(QSP_ARG_DECL  Data_Obj *dp, dimension_t size)
{
    	OBJ_DATA_PTR(dp) = getbuf(size);
}

//	put the space after tmpvec_name to prevent parens from being eaten as macro args???

void *TMPVEC_NAME (Platform_Device *pdp, size_t size, size_t len, const char *whence)
{
	return getbuf( size * len );
}

void FREETMP_NAME (void *a, const char *whence)
{
	givbuf(a);
}

