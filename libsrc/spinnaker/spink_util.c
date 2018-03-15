/* Jeff's interface to the 1394 subsystem usign PGR's libflycap_c */

#include "quip_config.h"

#include "quip_prot.h"
#include "function.h"
#include "data_obj.h"

#include <stdio.h>
#include <string.h>

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>		/* usleep */
#endif

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#include "spink.h"

// some globals...
static Spink_Map *current_map=NULL;

static spinSystem hSystem = NULL;
static spinInterfaceList hInterfaceList = NULL;
spinCameraList hCameraList = NULL;
size_t numCameras = 0;
static size_t numInterfaces = 0;

#define TMPSIZE	32	// for temporary object names, e.g. _frame55

ITEM_INTERFACE_DECLARATIONS(Spink_Interface,spink_interface,RB_TREE_CONTAINER)
ITEM_INTERFACE_DECLARATIONS(Spink_Cam,spink_cam,RB_TREE_CONTAINER)
ITEM_INTERFACE_DECLARATIONS(Spink_Map,spink_map,RB_TREE_CONTAINER)
ITEM_INTERFACE_DECLARATIONS(Spink_Node,spink_node,RB_TREE_CONTAINER)

#define UNIMP_FUNC(name)						\
	sprintf(ERROR_STRING,"Function %s is not implemented!?",name);	\
	warn(ERROR_STRING);

#ifdef HAVE_LIBSPINNAKER
#define SPINK_ENTRY(string,code)				\
{	#string,	code	}
#else // ! HAVE_LIBSPINNAKER
#define SPINK_ENTRY(string,code)				\
{	#string			}
#endif // ! HAVE_LIBSPINNAKER

#ifdef NOT_USED
static Named_Pixel_Format all_pixel_formats[]={
{ "mono8",	SPINK_PIXEL_FORMAT_MONO8			},
{ "411yuv8",	SPINK_PIXEL_FORMAT_411YUV8		},
{ "422yuv8",	SPINK_PIXEL_FORMAT_422YUV8		},
{ "444yuv8",	SPINK_PIXEL_FORMAT_444YUV8		},
{ "rgb8",	SPINK_PIXEL_FORMAT_RGB8			},
{ "mono16",	SPINK_PIXEL_FORMAT_MONO16			},
{ "rgb16",	SPINK_PIXEL_FORMAT_RGB16			},
{ "s_mono16",	SPINK_PIXEL_FORMAT_S_MONO16		},
{ "s_rgb16",	SPINK_PIXEL_FORMAT_S_RGB16		},
{ "raw8",	SPINK_PIXEL_FORMAT_RAW8			},
{ "raw16",	SPINK_PIXEL_FORMAT_RAW16			},
{ "mono12",	SPINK_PIXEL_FORMAT_MONO12			},
{ "raw12",	SPINK_PIXEL_FORMAT_RAW12			},
{ "bgr",	SPINK_PIXEL_FORMAT_BGR			},
{ "bgru",	SPINK_PIXEL_FORMAT_BGRU			},
{ "rgb",	SPINK_PIXEL_FORMAT_RGB			},
{ "rgbu",	SPINK_PIXEL_FORMAT_RGBU			},
{ "bgr16",	SPINK_PIXEL_FORMAT_BGR16			},
{ "bgru16",	SPINK_PIXEL_FORMAT_BGRU16			},
{ "jpeg",	SPINK_PIXEL_FORMAT_422YUV8_JPEG		},
};

#define N_NAMED_PIXEL_FORMATS	(sizeof(all_pixel_formats)/sizeof(Named_Pixel_Format))
#endif // NOT_USED

#ifdef HAVE_LIBSPINNAKER
#define SPINK_MODE(string,code,w,h,d)	{#string,code,w,h,d}
#else // ! HAVE_LIBSPINNAKER
#define SPINK_MODE(string,code,w,h,d)	{#string,w,h,d}
#endif // ! HAVE_LIBSPINNAKER

static Named_Video_Mode all_video_modes[]={
#ifdef FOO
SPINK_MODE( format7,		SPINK_VIDEOMODE_FORMAT7,		0, 0,	0 ),

SPINK_MODE( yuv444_160x120,	SPINK_VIDEOMODE_160x120YUV444,	160, 120, 3 ),

SPINK_MODE( yuv422_320x240,	SPINK_VIDEOMODE_320x240YUV422,	320, 240, 2 ),

SPINK_MODE( yuv411_640x480,	SPINK_VIDEOMODE_640x480YUV411,	640, 480, 0 /*1.5*/),
SPINK_MODE( yuv422_640x480,	SPINK_VIDEOMODE_640x480YUV422,	640, 480, 2 ),
SPINK_MODE( rgb8_640x480,		SPINK_VIDEOMODE_640x480RGB,	640, 480, 3 ),
SPINK_MODE( mono16_640x480,	SPINK_VIDEOMODE_640x480Y16,	640, 480, 2 ),
SPINK_MODE( mono8_640x480,	SPINK_VIDEOMODE_640x480Y8,	640, 480, 1 ),

SPINK_MODE( yuv422_800x600,	SPINK_VIDEOMODE_800x600YUV422,	800, 600, 2 ),
SPINK_MODE( rgb8_800x600,		SPINK_VIDEOMODE_800x600RGB,	800, 600, 3 ),
SPINK_MODE( mono16_800x600,	SPINK_VIDEOMODE_800x600Y16,	800, 600, 2 ),
SPINK_MODE( mono8_800x600,	SPINK_VIDEOMODE_800x600Y8,	800, 600, 1 ),

SPINK_MODE( yuv422_1024x768,	SPINK_VIDEOMODE_1024x768YUV422,	1024, 768, 2 ),
SPINK_MODE( rgb8_1024x768,	SPINK_VIDEOMODE_1024x768RGB,	1024, 768, 3 ),
SPINK_MODE( mono16_1024x768,	SPINK_VIDEOMODE_1024x768Y16,	1024, 768, 2 ),
SPINK_MODE( mono8_1024x768,	SPINK_VIDEOMODE_1024x768Y8,	1024, 768, 1 ),

SPINK_MODE( yuv422_1280x960,	SPINK_VIDEOMODE_1280x960YUV422,	1280, 960, 2 ),
SPINK_MODE( rgb8_1280x960,	SPINK_VIDEOMODE_1280x960RGB,	1280, 960, 3 ),
SPINK_MODE( mono16_1280x960,	SPINK_VIDEOMODE_1280x960Y16,	1280, 960, 2 ),
SPINK_MODE( mono8_1280x960,	SPINK_VIDEOMODE_1280x960Y8,	1280, 960, 1 ),

SPINK_MODE( yuv422_1600x1200,	SPINK_VIDEOMODE_1600x1200YUV422,	1600, 1200, 2 ),
SPINK_MODE( rgb8_1600x1200,	SPINK_VIDEOMODE_1600x1200RGB,	1600, 1200, 3 ),
SPINK_MODE( mono16_1600x1200,	SPINK_VIDEOMODE_1600x1200Y16,	1600, 1200, 2 ),
SPINK_MODE( mono8_1600x1200,	SPINK_VIDEOMODE_1600x1200Y8,	1600, 1200, 1 )
#endif // FOO

};

#define N_NAMED_VIDEO_MODES	(sizeof(all_video_modes)/sizeof(Named_Video_Mode))

const char *name_of_indexed_video_mode(int idx)
{
	if( idx < 0 || idx >= N_NAMED_VIDEO_MODES )
		return "(bad video mode index)";
	return all_video_modes[idx].nvm_name ;
}


/*
static Named_Color_Coding all_color_codes[]={
{ "mono8",	DC1394_COLOR_CODING_MONO8	},
{ "yuv411",	DC1394_COLOR_CODING_YUV411	},
{ "yuv422",	DC1394_COLOR_CODING_YUV422	},
{ "yuv444",	DC1394_COLOR_CODING_YUV444	},
{ "rgb8",	DC1394_COLOR_CODING_RGB8	},
{ "mono16",	DC1394_COLOR_CODING_MONO16	},
{ "rgb16",	DC1394_COLOR_CODING_RGB16	},
{ "mono16s",	DC1394_COLOR_CODING_MONO16S	},
{ "rgb16s",	DC1394_COLOR_CODING_RGB16S	},
{ "raw8",	DC1394_COLOR_CODING_RAW8	},
{ "raw16",	DC1394_COLOR_CODING_RAW16	}
};

#define N_NAMED_COLOR_CODES	(sizeof(all_color_codes)/sizeof(Named_Color_Coding))
*/

static Named_Grab_Mode all_grab_modes[]={
/*
SPINK_ENTRY(	drop_frames,	SPINK_DROP_FRAMES		),
SPINK_ENTRY(	buffer_frames,	SPINK_BUFFER_FRAMES	)
*/
};

#define N_NAMED_GRAB_MODES	(sizeof(all_grab_modes)/sizeof(Named_Grab_Mode))


#ifdef HAVE_LIBSPINNAKER

#ifdef FOOBAR
static Named_Bus_Speed all_bus_speeds[]={
/*
SPINK_ENTRY(	100,		SPINK_BUSSPEED_S100		),
SPINK_ENTRY(	200,		SPINK_BUSSPEED_S200		),
SPINK_ENTRY(	400,		SPINK_BUSSPEED_S400		),
SPINK_ENTRY(	800,		SPINK_BUSSPEED_S800		),
SPINK_ENTRY(	1600,		SPINK_BUSSPEED_S1600		),
SPINK_ENTRY(	3200,		SPINK_BUSSPEED_S3200		),
SPINK_ENTRY(	5000,		SPINK_BUSSPEED_S5000		),
SPINK_ENTRY(	10baseT,	SPINK_BUSSPEED_10BASE_T		),
SPINK_ENTRY(	100baseT,	SPINK_BUSSPEED_100BASE_T		),
SPINK_ENTRY(	1000baseT,	SPINK_BUSSPEED_1000BASE_T		),
SPINK_ENTRY(	10000baseT,	SPINK_BUSSPEED_10000BASE_T	),
SPINK_ENTRY(	fastest,	SPINK_BUSSPEED_S_FASTEST		),
SPINK_ENTRY(	any,		SPINK_BUSSPEED_ANY		)
*/
};

#define N_NAMED_BUS_SPEEDS	(sizeof(all_bus_speeds)/sizeof(Named_Bus_Speed))

static Named_Bandwidth_Allocation all_bw_allocations[]={
/*
SPINK_ENTRY(	off,		SPINK_BANDWIDTH_ALLOCATION_OFF		),
SPINK_ENTRY(	on,		SPINK_BANDWIDTH_ALLOCATION_ON		),
SPINK_ENTRY(	unsupported,	SPINK_BANDWIDTH_ALLOCATION_UNSUPPORTED	),
SPINK_ENTRY(	unspecified,	SPINK_BANDWIDTH_ALLOCATION_UNSPECIFIED	)
*/
};

#define N_NAMED_BW_ALLOCATIONS	(sizeof(all_bw_allocations)/sizeof(Named_Bandwidth_Allocation))

static Named_Interface all_interfaces[]={
/*
SPINK_ENTRY(	ieee1394,	SPINK_INTERFACE_IEEE1394	),
SPINK_ENTRY(	usb2,		SPINK_INTERFACE_USB_2	),
SPINK_ENTRY(	usb3,		SPINK_INTERFACE_USB_3	),
SPINK_ENTRY(	gigE,		SPINK_INTERFACE_GIGE	)
*/
};

#define N_NAMED_INTERFACES	(sizeof(all_interfaces)/sizeof(Named_Interface))
#endif // FOOBAR

#endif // HAVE_LIBSPINNAKER


const char *eii_prop_names[N_EII_PROPERTIES]={
	"timestamp",
	"gain",
	"shutter",
	"brightness",
	"exposure",
	"whiteBalance",
	"frameCounter",
	"strobePattern",
	"GPIOPinState",
	"ROIPosition"
};

#ifdef HAVE_LIBSPINNAKER

ITEM_INTERFACE_DECLARATIONS(Spink_Cam_Property_Type,pgr_prop,0)

//  When we change spink_cams, we have to refresh all properties!

void list_spink_cam_properties(QSP_ARG_DECL  Spink_Cam *skc_p)
{
	List *lp;
	Node *np;
	//Spink_Cam_Property_Type *pgpt;

	lp = pgr_prop_list();	// all properties
	np = QLIST_HEAD(lp);
	if( np != NULL ){
		sprintf(MSG_STR,"\n%s properties",skc_p->skc_name);
		prt_msg(MSG_STR);
	} else {
		sprintf(ERROR_STRING,"%s has no properties!?",skc_p->skc_name);
		warn(ERROR_STRING);
		return;
	}

	while(np!=NULL){
	//	pgpt = (Spink_Cam_Property_Type *)NODE_DATA(np);
		/*
		if( pgpt->info.present ){
			sprintf(MSG_STR,"\t%s",pgpt->name);
			prt_msg(MSG_STR);
		}
		*/
		np = NODE_NEXT(np);
	}
	prt_msg("");
}

// We call this after we select a spink_cam

void refresh_spink_cam_properties(QSP_ARG_DECL  Spink_Cam *skc_p)
{
	List *lp;
	Node *np;
	Spink_Cam_Property_Type *pgpt;

	lp = pgr_prop_list();	// all properties
	np = QLIST_HEAD(lp);
	while(np!=NULL){
		pgpt = (Spink_Cam_Property_Type *)NODE_DATA(np);
		refresh_property_info(QSP_ARG  skc_p, pgpt );
		/*
		if( pgpt->info.present ){
			refresh_property_value(QSP_ARG  skc_p, pgpt );
		}
		*/
		np = NODE_NEXT(np);
	}
}

void refresh_property_info(QSP_ARG_DECL  Spink_Cam *skc_p, Spink_Cam_Property_Type *pgpt )
{
	//spinkError error;

	/*
	error = spinkGetPropertyInfo( skc_p->sk_context, &(pgpt->info) );
	if( error != SPINK_ERROR_OK ){
		report_spink_error(QSP_ARG  error, "spinkGetPropertyInfo" );
		return;
	}
	*/
}

void show_property_info(QSP_ARG_DECL  Spink_Cam *skc_p, Spink_Cam_Property_Type *pgpt )
{
	//char var_name[32],val_str[32];

	sprintf(MSG_STR,"\n%s %s info:",skc_p->skc_name,pgpt->name);
	prt_msg(MSG_STR);

#ifdef FOOBAR
	// Now print out the property info?
	if( ! pgpt->info.present ){
		sprintf(MSG_STR,"%s is not present.",pgpt->name);
		prt_msg(MSG_STR);
		return;
	}

	if( pgpt->info.autoSupported )
		prt_msg("\tAuto is supported");
	else
		prt_msg("\tAuto is not supported");

	if( pgpt->info.manualSupported )
		prt_msg("\tManual is supported");
	else
		prt_msg("\tManual is not supported");

	if( pgpt->info.onOffSupported )
		prt_msg("\tOn/Off is supported");
	else
		prt_msg("\tOn/Off is not supported");

	if( pgpt->info.onePushSupported )
		prt_msg("\tOne push is supported");
	else
		prt_msg("\tOne push is not supported");

	if( pgpt->info.absValSupported )
		prt_msg("\tAbs. Val. is supported");
	else
		prt_msg("\tAbs. Val. is not supported");

	if( pgpt->info.readOutSupported )
		prt_msg("\tReadout is supported");
	else
		prt_msg("\tReadout is not supported");

	if( pgpt->info.absValSupported ){
		sprintf(MSG_STR,"\tRange:\n\t\t"
		"%d - %d (integer)\n\t\t"
		"%g - %g (absolute)",
			pgpt->info.min,
			pgpt->info.max,
	pgpt->info.absMin,pgpt->info.absMax);
		prt_msg(MSG_STR);

		sprintf(var_name,"%s_abs_min",pgpt->name);	// BUG possible buffer overrun, use snprintf or whatever...
		sprintf(val_str,"%g",pgpt->info.absMin);
		assign_var(var_name,val_str);

		sprintf(var_name,"%s_abs_max",pgpt->name);	// BUG possible buffer overrun, use snprintf or whatever...
		sprintf(val_str,"%g",pgpt->info.absMax);
		assign_var(var_name,val_str);
	} else {
		sprintf(MSG_STR,"\tRange:  %d - %d",
			pgpt->info.min,pgpt->info.max);
		prt_msg(MSG_STR);

		sprintf(var_name,"%s_abs_min",pgpt->name);	// BUG possible buffer overrun, use snprintf or whatever...
		assign_var(var_name,"(undefined)");

		sprintf(var_name,"%s_abs_max",pgpt->name);	// BUG possible buffer overrun, use snprintf or whatever...
		assign_var(var_name,"(undefined)");
	}

	sprintf(var_name,"%s_min",pgpt->name);	// BUG possible buffer overrun, use snprintf or whatever...
	sprintf(val_str,"%d",pgpt->info.min);
	assign_var(var_name,val_str);

	sprintf(var_name,"%s_max",pgpt->name);	// BUG possible buffer overrun, use snprintf or whatever...
	sprintf(val_str,"%d",pgpt->info.max);
	assign_var(var_name,val_str);

	sprintf(MSG_STR,"\tUnits:  %s (%s)",pgpt->info.pUnits,pgpt->info.pUnitAbbr);
	prt_msg(MSG_STR);
#endif // FOOBAR
}

void refresh_property_value(QSP_ARG_DECL  Spink_Cam *skc_p, Spink_Cam_Property_Type *pgpt )
{
	/*
	spinkError error;

	error = spinkGetProperty( skc_p->sk_context, &(pgpt->prop) );
	if( error != SPINK_ERROR_OK ){
		report_spink_error(QSP_ARG  error, "spinkGetProperty" );
		return;
	}
	*/
}

void show_property_value(QSP_ARG_DECL  Spink_Cam *skc_p, Spink_Cam_Property_Type *pgpt )
{
	sprintf(MSG_STR,"\n%s %s:",
		skc_p->skc_name,pgpt->name);
	prt_msg(MSG_STR);

#ifdef FOOBAR
	if( pgpt->info.autoSupported ){
		if( pgpt->prop.autoManualMode )
			sprintf(MSG_STR,"\tAuto mode enabled");
		else
			sprintf(MSG_STR,"\tAuto mode disabled");
	} else if( pgpt->info.manualSupported ){
		if( pgpt->prop.autoManualMode )
			sprintf(MSG_STR,"\tautoManualMode is true");
		else
			sprintf(MSG_STR,"\tautoManualMode is false");
	} else {
		sprintf(MSG_STR,"HUH???  Does not support auto or manual!?");
	}
	prt_msg(MSG_STR);

	if( pgpt->info.onOffSupported ){
		if( pgpt->prop.onOff )
			prt_msg("\tOn");
		else
			prt_msg("\tOff");
	}

	if( pgpt->info.onePushSupported ){
		if( pgpt->prop.onePush )
			prt_msg("\tOne push is true");
		else
			prt_msg("\tOne push is false");
	}
	// What exactly is readOut???  does this tell us whether we can read
	// the value back from the spink_cam???
	if( pgpt->info.readOutSupported ){
		// Now print out the property value itself!
		// Can we see both???

		sprintf(MSG_STR,"\t%s:  %d (integer)",
			pgpt->name,pgpt->prop.valueA);
		prt_msg(MSG_STR);

		// let a script access the value also
		sprintf(MSG_STR,"%d",pgpt->prop.valueA);
		assign_var(pgpt->name,MSG_STR);
		// should this be a reserved var?  I think so!

		if( pgpt->info.absValSupported ){
			sprintf(MSG_STR,"\t%s:  %g %s (absolute)",
				pgpt->name,pgpt->prop.absValue,pgpt->info.pUnitAbbr);
			prt_msg(MSG_STR);

			// let a script access the value also
			sprintf(MSG_STR,"%g",pgpt->prop.absValue);
			sprintf(ERROR_STRING,"%s_abs",pgpt->name);	// using ERROR_STRING as a temporary...
			assign_var(ERROR_STRING,MSG_STR);
			// should this be a reserved var?  I think so!
		} else {
			sprintf(ERROR_STRING,"%s_abs",pgpt->name);	// using ERROR_STRING as a temporary...
			assign_var(ERROR_STRING,"(undefined)");
		}
	} else {
		prt_msg("\t(Readout not supported)");
		sprintf(ERROR_STRING,"%s",pgpt->name);
		assign_var(ERROR_STRING,"(undefined)");
		sprintf(ERROR_STRING,"%s_abs",pgpt->name);
		assign_var(ERROR_STRING,"(undefined)");
	}
#endif // FOOBAR
}

void set_prop_value(QSP_ARG_DECL  Spink_Cam *skc_p, Spink_Cam_Property_Type *pgpt, Spink_Cam_Prop_Val *vp )
{
#ifdef FOOBAR
	spinkError error;

	if( vp->pv_is_abs ){
		if( vp->pv_u.u_f < pgpt->info.absMin || vp->pv_u.u_f > pgpt->info.absMax ){
			sprintf(ERROR_STRING,"Requested %s (%f) out of range (%f - %f)",
				pgpt->name,
				vp->pv_u.u_f,pgpt->info.absMin,pgpt->info.absMax);
			warn(ERROR_STRING);
			return;
		}
		pgpt->prop.absControl = TRUE;
		pgpt->prop.absValue = vp->pv_u.u_f;
	} else {
		if( vp->pv_u.u_i < pgpt->info.min || vp->pv_u.u_i > pgpt->info.max ){
			sprintf(ERROR_STRING,"Requested %s (%d) out of range (%d - %d)",
				pgpt->name,
				vp->pv_u.u_i,pgpt->info.min,pgpt->info.max);
			warn(ERROR_STRING);
			return;
		}
		pgpt->prop.absControl = FALSE;
		pgpt->prop.valueA = vp->pv_u.u_i;
	}

	error = spinkSetProperty( skc_p->sk_context, &(pgpt->prop));
	if( error != SPINK_ERROR_OK ){
		report_spink_error(QSP_ARG  error, "spinkSetProperty" );
		return;
	}
#endif // FOOBAR
}

void set_prop_auto(QSP_ARG_DECL  Spink_Cam *skc_p, Spink_Cam_Property_Type *pgpt, BOOL yn )
{
#ifdef FOOBAR
	spinkError error;

	if( ! pgpt->info.autoSupported ){
		sprintf(ERROR_STRING,"Sorry, auto mode not supported for %s.",
			pgpt->name);
		warn(ERROR_STRING);
		return;
	}

	pgpt->prop.autoManualMode = yn;
	error = spinkSetProperty( skc_p->sk_context, &(pgpt->prop) );
	if( error != SPINK_ERROR_OK ){
		report_spink_error(QSP_ARG  error, "spinkSetProperty" );
		return;
	}
#endif // FOOBAR
}

void
cleanup_spink_cam( Spink_Cam *skc_p )
{
	//if( IS_CAPTURING(skc_p) )
		 //dc1394_capture_stop( skc_p->sk_cam_p );
		 //fly_capture_stop( skc_p->sk_cam_p );
	//if( IS_TRANSMITTING(skc_p) )
		//dc1394_video_set_transmission( skc_p->sk_cam_p, DC1394_OFF );
		//fly_video_set_transmission( skc_p->sk_cam_p, DC1394_OFF );
	/* dc1394_free_spink_cam */
	//dc1394_spink_cam_free( skc_p->sk_cam_p );
	//fly_spink_cam_free( skc_p->sk_cam_p );
}


#define INDEX_SEARCH( stem, type, count, short_stem )			\
									\
static int index_of_##stem( type val )					\
{									\
	unsigned int i;							\
									\
	for(i=0;i<count;i++){						\
		if( all_##stem##s[i].short_stem##_value == val )	\
			return(i);					\
	}								\
	return -1;							\
}

#ifdef NOT_USED
INDEX_SEARCH(index_of_feature,dc1394feature_t,N_NAMED_FEATURES,all_features,nft_feature)
#endif /* NOT_USED */

#ifdef FOOBAR
INDEX_SEARCH(index_of_trigger_mode,dc1394trigger_mode_t,N_NAMED_TRIGGER_MODES,all_trigger_modes,ntm_mode)

INDEX_SEARCH(video_mode,spinkVideoMode,N_NAMED_VIDEO_MODES,nvm)
INDEX_SEARCH(framerate,spinkFrameRate,N_NAMED_FRAMERATES,nfr)
INDEX_SEARCH(grab_mode,spinkGrabMode,N_NAMED_GRAB_MODES,ngm)
INDEX_SEARCH(bus_speed,spinkBusSpeed,N_NAMED_BUS_SPEEDS,nbs)
INDEX_SEARCH(bw_allocation,spinkBandwidthAllocation,N_NAMED_BW_ALLOCATIONS,nba)
INDEX_SEARCH(interface,spinkInterfaceType,N_NAMED_INTERFACES,nif)
#endif // FOOBAR

#define NAME_LOOKUP_FUNC(stem,type,short_stem)		\
							\
static const char *name_for_##stem( type val )		\
{							\
	int i;						\
	i = index_of_##stem(val);			\
	if( i >= 0 )					\
		return(all_##stem##s[i].short_stem##_name);	\
	return NULL;					\
}

/*
NAME_LOOKUP_FUNC(video_mode,spinkVideoMode,nvm)
NAME_LOOKUP_FUNC(framerate,spinkFrameRate,nfr)
NAME_LOOKUP_FUNC(grab_mode,spinkGrabMode,ngm)
NAME_LOOKUP_FUNC(bus_speed,spinkBusSpeed,nbs)
NAME_LOOKUP_FUNC(bw_allocation,spinkBandwidthAllocation,nba)
NAME_LOOKUP_FUNC(interface,spinkInterfaceType,nif)
*/

int get_spink_cam_names( QSP_ARG_DECL  Data_Obj *str_dp )
{
	// Could check format of object here...
	// Should be string table with enough entries to hold the modes
	// Should the strings be rows or multidim pixels?
	List *lp;
	Node *np;
	Spink_Cam *skc_p;
	int i, n;

	lp = spink_cam_list();
	if( lp == NULL ){
		warn("No spink_cams!?");
		return 0;
	}

	n=eltcount(lp);
	if( OBJ_COLS(str_dp) < n ){
		sprintf(ERROR_STRING,"String object %s has too few columns (%ld) to hold %d spink_cam names",
			OBJ_NAME(str_dp),(long)OBJ_COLS(str_dp),n);
		warn(ERROR_STRING);
		n = OBJ_COLS(str_dp);
	}
		
	np=QLIST_HEAD(lp);
	i=0;
	while(np!=NULL){
		char *dst;
		skc_p = (Spink_Cam *) NODE_DATA(np);
		dst = OBJ_DATA_PTR(str_dp);
		dst += i * OBJ_PXL_INC(str_dp);
		if( strlen(skc_p->skc_name)+1 > OBJ_COMPS(str_dp) ){
			sprintf(ERROR_STRING,"String object %s has too few components (%ld) to hold spink_cam name \"%s\"",
				OBJ_NAME(str_dp),(long)OBJ_COMPS(str_dp),skc_p->skc_name);
			warn(ERROR_STRING);
		} else {
			strcpy(dst,skc_p->skc_name);
		}
		i++;
		if( i>=n )
			np=NULL;
		else
			np = NODE_NEXT(np);
	}

	return i;
}

int get_spink_cam_video_mode_strings( QSP_ARG_DECL  Data_Obj *str_dp, Spink_Cam *skc_p )
{
	// Could check format of object here...
	// Should be string table with enough entries to hold the modes
	// Should the strings be rows or multidim pixels?

	int i, n;

	if( OBJ_COLS(str_dp) < skc_p->skc_n_video_modes ){
		sprintf(ERROR_STRING,"String object %s has too few columns (%ld) to hold %d modes",
			OBJ_NAME(str_dp),(long)OBJ_COLS(str_dp),skc_p->skc_n_video_modes);
		warn(ERROR_STRING);
		n = OBJ_COLS(str_dp);
	} else {
		n=skc_p->skc_n_video_modes;
	}
		
	for(i=0;i<n;i++){
		int k;
		const char *src;
		char *dst;

		k=skc_p->skc_video_mode_indices[i];
		src = all_video_modes[k].nvm_name;
		dst = OBJ_DATA_PTR(str_dp);
		dst += i * OBJ_PXL_INC(str_dp);
		if( strlen(src)+1 > OBJ_COMPS(str_dp) ){
			sprintf(ERROR_STRING,"String object %s has too few components (%ld) to hold mode string \"%s\"",
				OBJ_NAME(str_dp),(long)OBJ_COMPS(str_dp),src);
			warn(ERROR_STRING);
		} else {
			strcpy(dst,src);
		}
	}
	set_script_var_from_int(QSP_ARG  "n_video_modes",n);
	return n;
}

static int bit_count(Framerate_Mask mask)
{
	int c=0;
	int nbits;

	nbits = sizeof(mask) * 8;
	while(nbits--){
		if( mask & 1 ) c++;
		mask >>= 1;
	}
	return c;
}

static void get_framerate_choices(QSP_ARG_DECL  Spink_Cam *skc_p)
{
	unsigned int i,n,idx;
	Framerate_Mask mask;

	if( skc_p->skc_framerate_names != NULL ){
		givbuf(skc_p->skc_framerate_names);
		skc_p->skc_framerate_names=NULL;	// in case we have an error before finishing
	}

	// format7 doesn't have a framerate!?

	mask = skc_p->skc_framerate_mask_tbl[ skc_p->skc_my_video_mode_index ];
/*
sprintf(ERROR_STRING,"%s:  video mode is %s",
skc_p->skc_name,all_video_modes[skc_p->skc_video_mode_index].nvm_name);
advise(ERROR_STRING);
sprintf(ERROR_STRING,"%s:  my video mode %s (index = %d)",
skc_p->skc_name,skc_p->skc_video_mode_names[skc_p->skc_my_video_mode_index],
skc_p->skc_my_video_mode_index);
advise(ERROR_STRING);
*/

	n = bit_count(mask);
	if( n <= 0 ){
		// this happens for the format7 video mode...
		// Can this ever happen?  If not, should be CAUTIOUS...
		//warn("no framerates for this video mode!?");
#ifdef FOOBAR
		if( skc_p->skc_video_mode == SPINK_VIDEOMODE_FORMAT7 ){
			if( skc_p->skc_framerate == SPINK_FRAMERATE_FORMAT7 ){
				advise("No framerates available for format7.");
			}
			  else {
				assert(0);
			}
		}
		  else {
			assert(0);
		}
#endif // FOOBAR
		return;
	}

	skc_p->skc_framerate_names = getbuf( n * sizeof(char *) );
	skc_p->skc_n_framerates = n ;

	i=(-1);
	idx=0;
	while(mask){
		i++;
		if( mask & 1 ){
#ifdef FOOBAR
			spinkFrameRate r;
			int j;
			r = i ;
			j = index_of_framerate( r );
			skc_p->skc_framerate_names[idx]=all_framerates[j].nfr_name;
#endif // FOOBAR
			idx++;
		}
			
		mask >>= 1;
	}

	assert( idx == n );
}

int get_spink_cam_framerate_strings( QSP_ARG_DECL  Data_Obj *str_dp, Spink_Cam *skc_p )
{
	int i, n;
	const char *src;
	char *dst;

	get_framerate_choices(QSP_ARG  skc_p);

	// Could check format of object here...
	// Should be string table with enough entries to hold the modes
	// Should the strings be rows or multidim pixels?

	n = skc_p->skc_n_framerates;

	if( OBJ_COLS(str_dp) < n ){
		sprintf(ERROR_STRING,"String object %s has too few columns (%ld) to hold %d framerates",
			OBJ_NAME(str_dp),(long)OBJ_COLS(str_dp),n);
		warn(ERROR_STRING);
		n = OBJ_COLS(str_dp);
	}

	for(i=0;i<skc_p->skc_n_framerates;i++){
		src = skc_p->skc_framerate_names[i];
		dst = OBJ_DATA_PTR(str_dp);
		dst += i * OBJ_PXL_INC(str_dp);
		if( strlen(src)+1 > OBJ_COMPS(str_dp) ){
			sprintf(ERROR_STRING,
"String object %s has too few components (%ld) to hold framerate string \"%s\"",
				OBJ_NAME(str_dp),(long)OBJ_COMPS(str_dp),src);
			warn(ERROR_STRING);
		} else {
			strcpy(dst,src);
		}
	}
	return n;
}

#ifdef FOOBAR
static void test_setup(QSP_ARG_DECL  Spink_Cam *skc_p,
		spinkVideoMode m, spinkFrameRate r, int *kp, int idx )
{
	spinkError error;
	BOOL supported;

	// punt if format 7
	if( m == SPINK_VIDEOMODE_FORMAT7 && r == SPINK_FRAMERATE_FORMAT7 ){
		// BUG?  make sure spink_cam has format7 modes?
		supported = TRUE;
	} else {
		error = spinkGetVideoModeAndFrameRateInfo( skc_p->sk_context,
			m,r,&supported );
		if( error != SPINK_ERROR_OK ){
			report_spink_error(QSP_ARG  error,
				"spinkGetVideoModeAndFrameRateInfo" );
			supported = FALSE;
		}
	}

	if( supported ){
		if( *kp < 0 || skc_p->skc_video_mode_indices[*kp] != idx ){
			*kp = (*kp)+1;
			skc_p->skc_video_mode_indices[*kp] = idx;
			skc_p->skc_video_mode_names[*kp] = all_video_modes[idx].nvm_name;
//fprintf(stderr,"test_setup:  adding video mode %s to %s\n",
//all_video_modes[idx].nvm_name,
//skc_p->skc_name);
			if( skc_p->skc_video_mode == m )
				skc_p->skc_video_mode_index = *kp;
		}
		skc_p->skc_framerate_mask_tbl[*kp] |= 1 << r;
	}
}
#endif // FOOBAR

// init_spink_base   -   grab frames to get the address
// associated with each frame index.  This wouldn't be necessary
// if we always provided the buffers, but we want this to work
// even when we don't.
//
// We keep track of the largest and smallest address, we save
// those so we can figure out the index of an arbitrary frame...


int check_buffer_alignment(QSP_ARG_DECL  Spink_Cam *skc_p)
{
	int i;

	// alignment requirement is now 1024
	// BUG this should be a parameter...
#define RV_ALIGNMENT_REQ	1024

	for(i=0;i<skc_p->skc_n_buffers;i++){
		if( ((long)(skc_p->skc_base+i*skc_p->skc_buf_delta)) % RV_ALIGNMENT_REQ != 0 ){
			sprintf(ERROR_STRING,"Buffer %d is not aligned - %d byte alignment required for raw volume I/O!?",
				i,RV_ALIGNMENT_REQ);
			warn(ERROR_STRING);
			return -1;
		}
	}
	return 0;
}

#ifdef FOOBAR
static int index_of_buffer(QSP_ARG_DECL  Spink_Cam *skc_p,spinkImage *ip)
{
	int idx;

	idx = ( ip->pData - skc_p->skc_base ) / skc_p->skc_buf_delta;
	/*
sprintf(ERROR_STRING,
"index_of_buffer:  data at 0x%lx, base = 0x%lx, idx = %d",
(long)ip->pData,(long)skc_p->skc_base,idx);
advise(ERROR_STRING);
*/

	assert( idx >= 0 && idx < skc_p->skc_n_buffers );
	return idx;
}
#endif // FOOBAR

#ifdef NOT_USED
static const char *name_for_pixel_format(spinkPixelFormat f)
{
	int i;

	for(i=0;i<N_NAMED_PIXEL_FORMATS;i++){
		if( all_pixel_formats[i].npf_value == f )
			return( all_pixel_formats[i].npf_name );
	}
	return("(unrecognixed pixel format code)");
}
#endif // NOT_USED

// libflycap doesn't have a queue mechanism like libdc1394...
// do we get the newest frame???

Data_Obj * grab_spink_cam_frame(QSP_ARG_DECL  Spink_Cam * skc_p )
{
#ifdef FOOBAR
	int index;

	spinkError error;

	if( skc_p->skc_base == NULL )
		init_spink_base(QSP_ARG  skc_p);

	error = spinkRetrieveBuffer( skc_p->sk_context, skc_p->sk_img_p );
	if( error != SPINK_ERROR_OK ){
		report_spink_error(QSP_ARG  error, "spinkRetrieveBuffer" );
		return NULL;
	}
//fprintf(stderr,"pixel format of retrieved images is %s (0x%x)\n",
//name_for_pixel_format(img.format),img.format);

	index = index_of_buffer(QSP_ARG  skc_p, skc_p->sk_img_p );
	skc_p->skc_newest = index;

	return( skc_p->skc_frm_dp_tbl[index] );
#endif // FOOBAR
	return NULL;
}

int reset_spink_cam(QSP_ARG_DECL  Spink_Cam *skc_p)
{
#ifdef FOOBAR
	spinkError error;

	error=spinkFireBusReset(skc_p->sk_context,&skc_p->sk_guid);
	if( error != SPINK_ERROR_OK ){
		report_spink_error(QSP_ARG  error, "spinkFireBusReset" );
	}
#endif // FOOBAR

	return 0;
}

void report_spink_cam_bandwidth(QSP_ARG_DECL  Spink_Cam *skc_p )
{
	UNIMP_FUNC("report_spink_cam_bandwidth");
}

unsigned int read_register( QSP_ARG_DECL  Spink_Cam *skc_p, unsigned int addr )
{
#ifdef FOOBAR
	spinkError error;
	unsigned int val;

	error = spinkReadRegister(skc_p->sk_context,addr,&val);
	if( error != SPINK_ERROR_OK ){
		report_spink_error(QSP_ARG  error, "spinkReadRegister" );
	}
	return val;
#else // FOOBAR
	return 0;
#endif // FOOBAR
}

void write_register( QSP_ARG_DECL  Spink_Cam *skc_p, unsigned int addr, unsigned int val )
{
#ifdef FOOBAR
	spinkError error;

	error = spinkWriteRegister(skc_p->sk_context,addr,val);
	if( error != SPINK_ERROR_OK ){
		report_spink_error(QSP_ARG  error, "spinkWriteRegister" );
	}
#endif // FOOBAR
}

void start_firewire_capture(QSP_ARG_DECL  Spink_Cam *skc_p)
{
#ifdef FOOBAR
	spinkError error;

advise("start_firewire_capture BEGIN");
	if( skc_p->skc_flags & FLY_CAM_IS_RUNNING ){
		warn("start_firewire_capture:  spink_cam is already capturing!?");
		return;
	}
advise("start_firewire_capture cam is not already running");
advise("start_firewire_capture calling spinkStartCapture");

//fprintf(stderr,"context = 0x%lx\n",(long)skc_p->sk_context);
	error = spinkStartCapture(skc_p->sk_context);
	if( error != SPINK_ERROR_OK ){
		report_spink_error(QSP_ARG  error, "spinkStartCapture" );
	} else {
		skc_p->skc_flags |= FLY_CAM_IS_RUNNING;

		// BUG - we should undo this when we stop capturing, because
		// we might change the video format or something else.
		// Perhaps more efficiently we could only do it when needed?
advise("start_firewire_capture calling init_spink_base");
		init_spink_base(QSP_ARG  skc_p);
	}
advise("start_firewire_capture DONE");
#endif // FOOBAR
}

void stop_firewire_capture(QSP_ARG_DECL  Spink_Cam *skc_p)
{
#ifdef FOOBAR
	spinkError error;

	if( (skc_p->skc_flags & FLY_CAM_IS_RUNNING) == 0 ){
		warn("stop_firewire_capture:  spink_cam is not capturing!?");
		return;
	}

	error = spinkStopCapture(skc_p->sk_context);
	if( error != SPINK_ERROR_OK ){
		report_spink_error(QSP_ARG  error, "spinkStopCapture" );
	} else {
		skc_p->skc_flags &= ~FLY_CAM_IS_RUNNING;
	}
#endif // FOOBAR
}

void set_fmt7_size(QSP_ARG_DECL  Spink_Cam *skc_p, int w, int h)
{
	UNIMP_FUNC("set_fmt7_size");
}

void release_oldest_frame(QSP_ARG_DECL  Spink_Cam *skc_p)
{
	UNIMP_FUNC("release_oldest_frame");
}

void list_spink_cam_trig(QSP_ARG_DECL  Spink_Cam *skc_p)
{
#ifdef FOOBAR
	spinkError error;
	spinkTriggerModeInfo tinfo;
	spinkTriggerMode tmode;

	error = spinkGetTriggerModeInfo(skc_p->sk_context,&tinfo);
	if( error != SPINK_ERROR_OK ){
		report_spink_error(QSP_ARG  error, "spinkGetTriggerModeInfo" );
		return;
	}
	fprintf(stderr,"Trigger mode info:\n");
#define BOOL_STR(v)	(v?"true":"false")
	fprintf(stderr,"\tpresent:  %s\n",BOOL_STR(tinfo.present));
	fprintf(stderr,"\treadOutSupported:  %s\n",BOOL_STR(tinfo.readOutSupported));
	fprintf(stderr,"\tonOffSupported:  %s\n",BOOL_STR(tinfo.onOffSupported));
	fprintf(stderr,"\tpolaritySupported:  %s\n",BOOL_STR(tinfo.polaritySupported));
	fprintf(stderr,"\tvalueReadable:  %s\n",BOOL_STR(tinfo.valueReadable));
	fprintf(stderr,"\tsourceMask:  0x%x\n",tinfo.sourceMask);
	fprintf(stderr,"\tsoftwareTriggerSupported:  %s\n",BOOL_STR(tinfo.softwareTriggerSupported));
	fprintf(stderr,"\tmodeMask:  0x%x\n",tinfo.modeMask);

	error = spinkGetTriggerMode(skc_p->sk_context,&tmode);
	if( error != SPINK_ERROR_OK ){
		report_spink_error(QSP_ARG  error, "spinkGetTriggerMode" );
		return;
	}
	fprintf(stderr,"Trigger mode:\n");
#define ONOFF_STR(v)	(v?"on":"off")
	fprintf(stderr,"\tonOff:  %s\n",ONOFF_STR(tmode.onOff));
#define SHOW_INT_PARAM(p) fprintf(stderr,"\t%s:  %d (0x%x)\n",\
	#p,tmode.p,tmode.p);
	SHOW_INT_PARAM(polarity)
	SHOW_INT_PARAM(source)
	SHOW_INT_PARAM(mode)
	SHOW_INT_PARAM(parameter)
#endif // FOOBAR
}

void set_buffer_obj(QSP_ARG_DECL  Spink_Cam *skc_p, Data_Obj *dp)
{
	// make sure sizes match
	if( OBJ_COLS(dp) != skc_p->skc_cols || OBJ_ROWS(dp) != skc_p->skc_rows ){
		sprintf(ERROR_STRING,
"set_buffer_obj:  size mismatch between %s (%dx%d) and object %s (%dx%d)",
			skc_p->skc_name,skc_p->skc_cols,skc_p->skc_rows,
			OBJ_NAME(dp),OBJ_COLS(dp),OBJ_ROWS(dp) );
		warn(ERROR_STRING);
		return;
	}
	if( PREC_CODE(OBJ_MACH_PREC_PTR(dp)) != PREC_UBY ){
		sprintf(ERROR_STRING,"Object %s (%s) should have %s precision!?",
			OBJ_NAME(dp),OBJ_PREC_NAME(dp),NAME_FOR_PREC_CODE(PREC_UBY));
		warn(ERROR_STRING);
		return;
	}
	{
#ifdef FOOBAR
		spinkError error;

		error = spinkSetUserBuffers(skc_p->sk_context, OBJ_DATA_PTR(dp),
				OBJ_COLS(dp)*OBJ_ROWS(dp)*OBJ_COMPS(dp),OBJ_FRAMES(dp));
		if( error != SPINK_ERROR_OK ){
			report_spink_error(QSP_ARG  error, "spinkSetUserBuffers" );
			return;
		}
#endif // FOOBAR
	}
	skc_p->skc_base = NULL;	// force init_spink_base to run again
}

#endif /* HAVE_LIBSPINNAKER */


static const char **grab_mode_names=NULL;

int pick_grab_mode(QSP_ARG_DECL Spink_Cam *skc_p, const char *pmpt)
{
	int idx;

	if( skc_p == NULL ){
		sprintf(ERROR_STRING,"pick_spink_cam_grab_mode:  no spink_cam selected!?");
		warn(ERROR_STRING);
		return -1;
	}

	if( grab_mode_names == NULL ){
		grab_mode_names = getbuf( sizeof(char *) * N_NAMED_GRAB_MODES );
		for(idx=0;idx<N_NAMED_GRAB_MODES;idx++)
			grab_mode_names[idx] = all_grab_modes[idx].ngm_name;
	}

	idx=WHICH_ONE(pmpt,N_NAMED_GRAB_MODES,grab_mode_names);
	return idx;
}

void pop_spink_cam_context(SINGLE_QSP_ARG_DECL)
{
	// pop old context...
	Item_Context *icp;
	icp=pop_dobj_context();
	assert( icp != NULL );
}

void push_spink_cam_context(QSP_ARG_DECL  Spink_Cam *skc_p)
{
	push_dobj_context(skc_p->skc_do_icp);
}

Item_Context * _pop_spink_node_context(SINGLE_QSP_ARG_DECL)
{
	Item_Context *icp;
	if( spink_node_itp == NULL ) init_spink_nodes();
	icp = pop_item_context(spink_node_itp);
	return icp;
}

void _push_spink_node_context(QSP_ARG_DECL  Item_Context *icp)
{
	if( spink_node_itp == NULL ) init_spink_nodes();
	push_item_context(spink_node_itp,icp);
}

// Don't we already have this???

static void substitute_char(char *buf,char find, char replace)
{
	char *s;

	s=buf;
	while( *s ){
		if( *s == find )
			*s = replace;
		s++;
	}
}

#define get_unique_cam_name(buf, buflen) _get_unique_cam_name(QSP_ARG  buf, buflen)

static int _get_unique_cam_name(QSP_ARG_DECL  char *buf, int buflen)
{
	int i=2;
	int orig_len;
	Spink_Cam *skc_p;

	orig_len = strlen(buf);
	if( orig_len+3 > buflen ){
		sprintf(ERROR_STRING,
			"Camera name buffer needs to be enlarged to accomodate multiple instances of '%s'!?",
			buf);
		error1(ERROR_STRING);
	}
	buf[orig_len]='_';
	buf[orig_len+2]=0;
	while(i<10){
		buf[orig_len+1]='0'+i;	// 2-9
		skc_p = spink_cam_of(buf);
		if( skc_p == NULL ) return 0;
	}
	return -1;
}

static int _register_one_node(QSP_ARG_DECL  spinNodeHandle hNode, int level)
{
	char name[LLEN];
	size_t l=LLEN;
	Spink_Node *skn_p;
	spinNodeType type;

	if( get_node_name(name,&l,hNode) < 0 )
		error1("register_one_node:  error getting node name!?");

	skn_p = new_spink_node(name);
	assert(skn_p!=NULL);

	assert(current_map!=NULL);
	skn_p->skn_skm_p = current_map;

	skn_p->skn_flags = 0;
	if( spink_node_is_readable(hNode) ){
		skn_p->skn_flags |= NODE_READABLE;
	}
	if( spink_node_is_writable(hNode) ){
		skn_p->skn_flags |= NODE_WRITABLE;
	}

	if( get_node_type(hNode,&type) < 0 ) return -1;
	skn_p->skn_type = type;
//fprintf(stderr,"register_one_node:  %s   flags = %d\n",skn_p->skn_name,skn_p->skn_flags);

	//skn_p->skn_handle = hNode;
	return 0;
}

#define register_map_nodes(hMap,skm_p) _register_map_nodes(QSP_ARG  hMap,skm_p)

static void _register_map_nodes(QSP_ARG_DECL  spinNodeMapHandle hMap, Spink_Map *skm_p)
{
	spinNodeHandle hRoot=NULL;

fprintf(stderr,"register_map_nodes %s BEGIN\n",skm_p->skm_name);
//fprintf(stderr,"register_map_nodes BEGIN   hMap = 0x%lx\n",(u_long)hMap);

	push_spink_node_context(skm_p->skm_icp);
//fprintf(stderr,"register_map_nodes fetching root node   hMap = 0x%lx\n",(u_long)hMap);
	if( fetch_spink_node(hMap, "Root", &hRoot) < 0 )
		error1("register_map_nodes:  error fetching map root node");

//fprintf(stderr,"register_map_nodes:  root node fetched, traversing...\n");
	current_map = skm_p;
	if( traverse_spink_node_tree(hRoot,0,_register_one_node) < 0 )
		error1("error traversing node map");
	current_map = NULL;
	pop_spink_node_context();
fprintf(stderr,"register_map_nodes %s DONE\n",skm_p->skm_name);
}


#define register_one_nodemap(skc_p, code, name) _register_one_nodemap(QSP_ARG  skc_p, code, name)

static void _register_one_nodemap(QSP_ARG_DECL  Spink_Cam *skc_p, Node_Map_Type type, const char *name)
{
	Spink_Map *skm_p;
	spinNodeMapHandle hMap = NULL;

//fprintf(stderr,"register_one_nodemap %s BEGIN, type = %d\n",name,type);
	insure_current_camera(skc_p);
	assert( skc_p->skc_current_handle != NULL );
//fprintf(stderr,"register_one_nodemap:  %s has current handle 0x%lx\n", skc_p->skc_name,(u_long)skc_p->skc_current_handle);

	skm_p = new_spink_map(name);
	if( skm_p == NULL ) error1("Unable to create map struct!?");
//fprintf(stderr,"Created new map struct %s at 0x%lx\n", skm_p->skm_name,(u_long)skm_p);

	if( spink_node_itp == NULL ) init_spink_nodes();
	skm_p->skm_icp = create_item_context(spink_node_itp,name);
	assert(skm_p->skm_icp!=NULL);
	// do we need to push the context too???

	//skm_p->skm_handle = NULL;
	skm_p->skm_type = type;
	skm_p->skm_skc_p = skc_p;

//	fetch_map_handle(skm_p);
//fprintf(stderr,"register_one_nodemap calling get_node_map_handle...\n");
	get_node_map_handle(&hMap,skm_p,"register_one_nodemap");	// first time just sets
//fprintf(stderr,"register_one_nodemap:  hMap = 0x%lx, *hMap = 0x%lx \n",(u_long)hMap, (u_long)*((void **)hMap));

	register_map_nodes(hMap,skm_p);
}

#define register_cam_nodemaps(skc_p) _register_cam_nodemaps(QSP_ARG  skc_p)

static void _register_cam_nodemaps(QSP_ARG_DECL  Spink_Cam *skc_p)
{
//fprintf(stderr,"register_cam_nodemaps BEGIN\n");
//fprintf(stderr,"register_cam_nodemaps registering device map\n");
	sprintf(MSG_STR,"%s.device_TL",skc_p->skc_name);
	register_one_nodemap(skc_p,DEV_NODE_MAP,MSG_STR);
//fprintf(stderr,"register_cam_nodemaps registering camera map\n");
	sprintf(MSG_STR,"%s.genicam",skc_p->skc_name);
	register_one_nodemap(skc_p,CAM_NODE_MAP,MSG_STR);
//fprintf(stderr,"register_cam_nodemaps DONE\n");
}

#define init_one_spink_cam(idx) _init_one_spink_cam(QSP_ARG  idx)

static int _init_one_spink_cam(QSP_ARG_DECL  int idx)
{
	spinCamera hCam;
//	spinNodeMapHandle hNodeMap;
	Spink_Cam *skc_p;
	char buf[MAX_BUFF_LEN];
	size_t len = MAX_BUFF_LEN;

	if( get_cam_from_list(hCameraList,idx,&hCam) < 0 )
		return -1;
//fprintf(stderr,"init_one_spink_cam:  get_cam_from_list returned 0x%lx\n",(u_long)hCam);

	if( get_camera_model_name(buf,len,hCam) < 0 ) return -1;
	substitute_char(buf,' ','_');
	// Check and see if another camera of this type has already
	// been detected...
	skc_p = spink_cam_of(buf);
	if( skc_p != NULL ){
		if( get_unique_cam_name(buf,MAX_BUFF_LEN) < 0 )
			return -1;
	}
	skc_p = new_spink_cam(buf);
	if( skc_p == NULL ) return -1;
	skc_p->skc_current_handle = hCam;
//fprintf(stderr,"init_one_spink_cam:  setting current handle to 0x%lx\n",(u_long)hCam);

	//skc_p->skc_handle = hCam;
	skc_p->skc_sys_idx = idx;
	skc_p->skc_iface_idx = -1;	// invalid value

	// register_cam_nodemaps will get the camera handle again...
//	if( release_spink_cam(hCam) < 0 )
//		return -1;

	//skc_p->skc_TL_dev_node_map = hNodeMapTLDevice;
	//skc_p->skc_genicam_node_map = hNodeMap;

	register_cam_nodemaps(skc_p);
	//skc_p->skc_flags = SPINK_CAM_CONNECTED;

	// Make a data_obj context for the frames...
	skc_p->skc_do_icp = create_dobj_context( QSP_ARG  skc_p->skc_name );
	assert(skc_p->skc_do_icp != NULL);

	// We have to explicitly release here, as we weren't able to call
	// insure_current_camera at the beginning...
	//spink_release_cam(skc_p);
	release_current_camera();

	return 0;
}

#define create_spink_camera_structs() _create_spink_camera_structs(SINGLE_QSP_ARG)

static int _create_spink_camera_structs(SINGLE_QSP_ARG_DECL)
{
	int i;

	for(i=0;i<numCameras;i++){
		if( init_one_spink_cam(i) < 0 )
			return -1;
	}
	return 0;
} // end create_spink_camera_structs

#define create_spink_interface_structs() _create_spink_interface_structs(SINGLE_QSP_ARG)

static int _create_spink_interface_structs(SINGLE_QSP_ARG_DECL)
{
	int i;
	Spink_Interface *ski_p;
	char buf[MAX_BUFF_LEN];
	size_t len = MAX_BUFF_LEN;


	for(i=0;i<numInterfaces;i++){
		spinInterface hInterface;
		// This call causes releaseSystem to crash!?
		if( get_spink_interface_from_list(&hInterface,hInterfaceList,i) < 0 )
			return -1;

		get_interface_name(buf,len,hInterface);
		substitute_char(buf,' ','_');
		ski_p = new_spink_interface(buf);

		//ski_p->ski_handle = hInterface;
		ski_p->ski_idx = i;

		if( release_interface(hInterface) < 0 )
			return -1;
	}
	return 0;
}

int init_spink_cam_system(SINGLE_QSP_ARG_DECL)
{
#ifdef HAVE_LIBSPINNAKER
	assert( hSystem == NULL );

	if( get_spink_system(&hSystem) < 0 )
		return -1;

	if( get_spink_interfaces(hSystem,&hInterfaceList,&numInterfaces) < 0 ) return -1;
	if( create_spink_interface_structs() < 0 ) return -1;

	// We get the cameras from the system, not from individual interfaces...
	if( get_spink_cameras(hSystem,&hCameraList,&numCameras) < 0 ) return -1;
	if( create_spink_camera_structs() < 0 ) return -1;

	do_on_exit(_release_spink_cam_system);

#endif // HAVE_LIBSPINNAKER
	return 0;
}


#define release_spink_interface_structs()	_release_spink_interface_structs(SINGLE_QSP_ARG)

static int _release_spink_interface_structs(SINGLE_QSP_ARG_DECL)
{
	// iterate through the list
	Node *np;
	List *lp;
	Spink_Interface *ski_p;

	lp = spink_interface_list();
	if( lp == NULL ) return 0;

	while( (np=remHead(lp)) != NULL ){
		ski_p = (Spink_Interface *) NODE_DATA(np);
		/*
		if( release_spink_interface(ski_p->ski_handle) < 0 )
			return -1;
			*/
		// could delete the struct here too!?!?
		del_spink_interface(ski_p);
		np = NODE_NEXT(np);
	}
	return 0;
}

void _release_spink_cam_system(SINGLE_QSP_ARG_DECL)
{
	assert( hSystem != NULL );
DEBUG_MSG(releast_spink_cam_system BEGIN)
	release_current_camera();

	if( release_spink_interface_structs() < 0 ) return;
	//if( release_spink_cam_structs() < 0 ) return;

	if( release_spink_cam_list(&hCameraList) < 0 ) return;
	if( release_spink_interface_list(&hInterfaceList) < 0 ) return;
	if( release_spink_system(hSystem) < 0 ) return;
DEBUG_MSG(releast_spink_cam_system DONE)
}

int _spink_release_cam(QSP_ARG_DECL  Spink_Cam *skc_p)
{
	assert(skc_p->skc_current_handle!=NULL);
//fprintf(stderr,"spink_release_cam:  old handle was 0x%lx, will set to NULL\n",(u_long)skc_p->skc_current_handle);
	if( release_spink_cam(skc_p->skc_current_handle) < 0 )
		return -1;
	skc_p->skc_current_handle=NULL;
	return 0;
}

