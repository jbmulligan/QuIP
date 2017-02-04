// 
// This file contains macros that are useful for writing kernels...
//
// A lot of this stuff is not platform specific!?

#include "veclib/gpu_call_utils.h"	// ditto

/**********************************************************************/

#ifdef FOOBAR
// statement arg not needed?

#ifdef BUILD_FOR_CUDA

#define _VEC_FUNC_2V_CONV(n,type,statement)	\
						\
_GENERIC_FAST_CONV_FUNC(n,std_type,type)	\
_GENERIC_EQSP_CONV_FUNC(n,std_type,type)	\
_GENERIC_SLOW_CONV_FUNC(n,std_type,type)	\
_GENERIC_FLEN_CONV_FUNC(n,std_type,type)	\
_GENERIC_ELEN_CONV_FUNC(n,std_type,type)	\
_GENERIC_SLEN_CONV_FUNC(n,std_type,type)

#else // ! BUILD_FOR_CUDA

#define _VEC_FUNC_2V_CONV(n,type,statement)	\
						\
_GENERIC_FAST_CONV_FUNC(n,std_type,type)	\
_GENERIC_EQSP_CONV_FUNC(n,std_type,type)	\
_GENERIC_SLOW_CONV_FUNC(n,std_type,type)

#endif // ! BUILD_FOR_CUDA

#endif // FOOBAR

// args n, s  are func_name, statement

// 5 args
#define _VEC_FUNC_5V(n,s)		GENERIC_VFUNC_CALL(n,s,,,,5,)
#define _VEC_FUNC_4V_SCAL(n,s)		GENERIC_VFUNC_CALL(n,s,,,1S_,4,)
#define _VEC_FUNC_3V_2SCAL(n,s)		GENERIC_VFUNC_CALL(n,s,,,2S_,3,)
#define _VEC_FUNC_2V_3SCAL(n,s)		GENERIC_VFUNC_CALL(n,s,,,3S_,2,)

// this is vramp2d
#define _VEC_FUNC_1V_3SCAL(n,cpu_s1,cpu_s2,s)	SLOW_VFUNC_CALL(n,s,,,3S_,1,)

// 3 args
#define _VEC_FUNC_3V(n,s)		GENERIC_VFUNC_CALL(n,s,,,,3,) 
#define _VEC_FUNC_CPX_3V(n,s)		GENERIC_VFUNC_CALL(n,s,,CPX_,,3,) 
#define _VEC_FUNC_QUAT_3V(n,s)		GENERIC_VFUNC_CALL(n,s,,QUAT_,,3,) 
#define _VEC_FUNC_1V_2SCAL(n,cpu_stat,s)	GENERIC_VFUNC_CALL(n,s,,,2S_,1,) 
#define _VEC_FUNC_2V_SCAL(n,s)		GENERIC_VFUNC_CALL(n,s,,,1S_,2,) 
#define _VEC_FUNC_VVSLCT(n,s)		GENERIC_VFUNC_CALL(n,s,SBM_,,,3,) 
#define _VEC_FUNC_VSSLCT(n,s)		GENERIC_VFUNC_CALL(n,s,SBM_,,1S_,2,) 
#define _VEC_FUNC_SSSLCT(n,s)		GENERIC_VFUNC_CALL(n,s,SBM_,,2S_,1,) 

#define _VEC_FUNC_SBM_1(n,s)		GENERIC_VFUNC_CALL(n,s,SBM_,,,1,) 

#define _VEC_FUNC_1V(n,s)		GENERIC_VFUNC_CALL(n,s,,,,1,) 
#define _VEC_FUNC_2V(n,s)		GENERIC_VFUNC_CALL(n,s,,,,2,) 
#define _VEC_FUNC_2V_MIXED(n,s)		GENERIC_VFUNC_CALL(n,s,,RC_,,2,) 
#define _VEC_FUNC_CPX_2V(n,s)		GENERIC_VFUNC_CALL(n,s,,CPX_,,2,) 
#define _VEC_FUNC_QUAT_2V(n,s)		GENERIC_VFUNC_CALL(n,s,,QUAT_,,2,) 

#define _VEC_FUNC_VVMAP( fn, op )	GENERIC_VEC_FUNC_DBM(fn,SET_DBM_BIT( src1 op src2 ),,,2SRCS)
// vsm_gt etc
#define _VEC_FUNC_VSMAP( fn, op )	GENERIC_VEC_FUNC_DBM(fn,SET_DBM_BIT(src1 op scalar1_val),,1S_,1SRC)

// this is vset
#define _VEC_FUNC_1V_SCAL(n,s)		GENERIC_VFUNC_CALL(n,s,,,1S_,1,) 
// where is cpx vset??

// Are these two redundant?
// this is bit_vset
#define _VEC_FUNC_DBM_1S(fn, s)		GENERIC_VEC_FUNC_DBM(fn,s,,1S_,)
// bit_vmov
#define _VEC_FUNC_DBM_SBM(fn, s)	GENERIC_VEC_FUNC_DBM(fn,s,,,SBM)

#define _VEC_FUNC_DBM_1V(fn, s)		GENERIC_VEC_FUNC_DBM(fn,s,,,1SRC)

#define _VEC_FUNC_SBM_CPX_3V(n,s)	GENERIC_VFUNC_CALL(n,s,SBM_,CPX_,,3,) 
#define _VEC_FUNC_SBM_CPX_1S_2V(n,s)	GENERIC_VFUNC_CALL(n,s,SBM_,CPX_,1S_,2,) 
#define _VEC_FUNC_SBM_CPX_2S_1V(n,s)	GENERIC_VFUNC_CALL(n,s,SBM_,CPX_,2S_,1,) 
#define _VEC_FUNC_SBM_QUAT_3V(n,s)	GENERIC_VFUNC_CALL(n,s,SBM_,QUAT_,,3,) 
#define _VEC_FUNC_SBM_QUAT_1S_2V(n,s)	GENERIC_VFUNC_CALL(n,s,SBM_,QUAT_,1S_,2,) 
#define _VEC_FUNC_SBM_QUAT_2S_1V(n,s)	GENERIC_VFUNC_CALL(n,s,SBM_,QUAT_,2S_,1,) 
#define _VEC_FUNC_CPX_2V_T2(n,s)	GENERIC_VFUNC_CALL(n,s,,CPX_,,2,T2) 
#define _VEC_FUNC_CPXT_2V(n,s)		GENERIC_VFUNC_CALL(n,s,,CPX_,,2,T) 
#define _VEC_FUNC_CPXT_3V(n,s)		GENERIC_VFUNC_CALL(n,s,,CPX_,,3,T) 
#define _VEC_FUNC_CPXD_3V(n,s)		GENERIC_VFUNC_CALL(n,s,,CPX_,,3,D) 
#define _VEC_FUNC_CPX_1S_2V(n,s)	GENERIC_VFUNC_CALL(n,s,,CPX_,1S_,2,) 
#define _VEC_FUNC_QUAT_1S_2V(n,s)	GENERIC_VFUNC_CALL(n,s,,QUAT_,1S_,2,) 
#define _VEC_FUNC_CPX_1S_2V_T2(n,s)	GENERIC_VFUNC_CALL(n,s,,CPX_,1S_,2,T2) 
#define _VEC_FUNC_CPX_1S_2V_T3(n,s)	GENERIC_VFUNC_CALL(n,s,,CPX_,1S_,2,T3) 
#define _VEC_FUNC_QUAT_1S_2V_T4(n,s)	GENERIC_VFUNC_CALL(n,s,,QUAT_,1S_,2,T4) 
#define _VEC_FUNC_QUAT_1S_2V_T5(n,s)	GENERIC_VFUNC_CALL(n,s,,QUAT_,1S_,2,T5) 
#define _VEC_FUNC_CPXT_1S_2V(n,s)	GENERIC_VFUNC_CALL(n,s,,CPX_,1S_,2,T) 
#define _VEC_FUNC_CPXD_1S_2V(n,s)	GENERIC_VFUNC_CALL(n,s,,CPX_,1S_,2,D) 
#define _VEC_FUNC_CPX_1S_1V(n,s)	GENERIC_VFUNC_CALL(n,s,,CPX_,1S_,1,) 
#define _VEC_FUNC_QUAT_1S_1V(n,s)	GENERIC_VFUNC_CALL(n,s,,QUAT_,1S_,1,) 
#define _VEC_FUNC_CPX_3V_T1(n,s)	GENERIC_VFUNC_CALL(n,s,,CPX_,,3,T1) 
#define _VEC_FUNC_CPX_3V_T2(n,s)	GENERIC_VFUNC_CALL(n,s,,CPX_,,3,T2) 
#define _VEC_FUNC_CPX_3V_T3(n,s)	GENERIC_VFUNC_CALL(n,s,,CPX_,,3,T3) 
#define _VEC_FUNC_QUAT_2V_T4(n,s)	GENERIC_VFUNC_CALL(n,s,,QUAT_,,2,T4) 
#define _VEC_FUNC_QUAT_3V_T4(n,s)	GENERIC_VFUNC_CALL(n,s,,QUAT_,,3,T4) 
#define _VEC_FUNC_QUAT_3V_T5(n,s)	GENERIC_VFUNC_CALL(n,s,,QUAT_,,3,T5) 
#define _VEC_FUNC_CCR_3V(n,s)		GENERIC_VFUNC_CALL(n,s,,CCR_,,3,) 
#define _VEC_FUNC_QQR_3V(n,s)		GENERIC_VFUNC_CALL(n,s,,QQR_,,3,) 
#define _VEC_FUNC_CR_1S_2V(n,s)		GENERIC_VFUNC_CALL(n,s,,CR_,1S_,2,) 
#define _VEC_FUNC_QR_1S_2V(n,s)		GENERIC_VFUNC_CALL(n,s,,QR_,1S_,2,) 
// args d,s1,s2 are dst_arg, src_arg1, src_arg2
#define _VEC_FUNC_VS_LS(n,d,s1,s2)	GENERIC_LS_VFUNC_CALL(n,1S_,2,d,s1,s2)
#define _VEC_FUNC_VV_LS(n,d,s1,s2)	GENERIC_LS_VFUNC_CALL(n,,3,d,s1,s2)

// added
// This is for ramp1d, but it is NOT a generic call!?  BUG
// 1V_2SCAL
//#define _VEC_FUNC_2S_1V(n,s)		GENERIC_VFUNC_CALL(n,s,,,2S_,1,)


// special case for left shift
// is just for cuda???
#define GENERIC_LS_VFUNC_CALL(fn,sclrs,vecs,da,sa1,sa2)		\
	GENERIC_VFUNC_CALL(fn,LSHIFT_SWITCH_32(da,sa1,sa2),,,sclrs,vecs,)




// PORT ?

#define GENERIC_FAST_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)	\
_GENERIC_FAST_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)

#define GENERIC_EQSP_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)	\
_GENERIC_EQSP_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)

#define GENERIC_SLOW_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)	\
_GENERIC_SLOW_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)

#define GENERIC_FLEN_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)	\
_GENERIC_FLEN_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)

#define GENERIC_ELEN_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)	\
_GENERIC_ELEN_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)

#define GENERIC_SLEN_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)	\
_GENERIC_SLEN_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)



// What is this???
#define  GENERIC_FAST_VFUNC_DECL(name,statement,bm,typ,scalars,vectors,extra)	\
void name( DECLARE_KERN_ARGS_FAST_##bm##typ##scalars##vectors )				\
{										\
}


/* These are for calls with a destination bitmap (vvm_lt etc)
 *
 * Here we cannot vectorize over all the pixels, because multiple
 * pixels share the same bitmap word.  Each thread has to set all the bits
 * in a given word.
 */


// This loops over all of the bits in one word.  We have a problem here if
// all of the bits are not used - there is no harm in reading or setting
// unused bits, but it might cause a seg violation when trying to access
// corresponding non-bit args???  BUG?

#define FAST_DBM_LOOP( statement, advance )				\
									\
	for(i_dbm_bit=0;i_dbm_bit<BITS_PER_BITMAP_WORD;i_dbm_bit++){	\
		dbm_bit = NUMBERED_BIT(i_dbm_bit);			\
		statement ;						\
		advance							\
	}


#define FLEN_DBM_LOOP( statement, advance )		EQSP_DBM_LOOP(statement,advance)

#define EQSP_DBM_LOOP( statement, advance )					\
										\
	for(i_dbm_bit=0;i_dbm_bit<BITS_PER_BITMAP_WORD;i_dbm_bit++){		\
		dbm_bit = NUMBERED_BIT(i_dbm_bit);				\
		if( dbm_info_p->word_tbl[tbl_idx].valid_bits & dbm_bit ){	\
			statement;						\
			advance;						\
		}								\
	}

#define SLEN_DBM_LOOP( statement, advance )				\
									\
	SLOW_DBM_LOOP( statement, advance )

// len is a different type, but here we don't check the other len dimensions!?  BUG?
// We don't necessarily want to set all of the bits in the word, if there is
// a skipping increment?  So this probably won't work for subsamples?  BUG?

//#define SLOW_DBM_LOOP( statement, advance )	FAST_DBM_LOOP( statement, advance )

//#ifdef OMIT_FOR_TESTING
#define SLOW_DBM_LOOP( statement, advance )					\
										\
	for(i_dbm_bit=0;i_dbm_bit<BITS_PER_BITMAP_WORD;i_dbm_bit++){		\
		dbm_bit = NUMBERED_BIT(i_dbm_bit);				\
		if( dbm_info_p->word_tbl[tbl_idx].valid_bits & dbm_bit ){	\
			statement;						\
			advance;						\
		}								\
	}

// PORT ?
// BUG these seem to be re-defined in ocl...

#define ADVANCE_FAST_SRC1	index2++;
#define ADVANCE_FAST_SRC2	index3++;
#define ADVANCE_FAST_SRC3	index4++;
#define ADVANCE_FAST_SRC4	index5++;
#define ADVANCE_FAST_DBM	/* do something??? */
#define ADVANCE_FAST_SBM	/* do something??? */

#define ADVANCE_EQSP_SRC1	index2 += inc2;
#define ADVANCE_EQSP_SRC2	index3 += inc3;
#define ADVANCE_EQSP_SRC3	index4 += inc4;
#define ADVANCE_EQSP_SRC4	index5 += inc5;
#define ADVANCE_EQSP_DBM	/* dbm_bit += dbm_inc; */
#define ADVANCE_EQSP_SBM	/* do something? */

#define ADVANCE_SLOW_SRC1	index2.d5_dim[1]+=inc2.d5_dim[1];
#define ADVANCE_SLOW_SRC2	index3.d5_dim[1]+=inc3.d5_dim[1];
#define ADVANCE_SLOW_SRC3	index4.d5_dim[1]+=inc4.d5_dim[1];
#define ADVANCE_SLOW_SRC4	index5.d5_dim[1]+=inc5.d5_dim[1];
#define ADVANCE_SLOW_DBM	/* do something??? */
#define ADVANCE_SLOW_SBM	/* do something??? */

#define ADVANCE_FAST_DBM_	ADVANCE_FAST_DBM
#define ADVANCE_FAST_DBM_1SRC	ADVANCE_FAST_DBM ADVANCE_FAST_SRC1
#define ADVANCE_FAST_DBM_2SRCS	ADVANCE_FAST_DBM_1SRC ADVANCE_FAST_SRC2
#define ADVANCE_FAST_DBM_SBM	ADVANCE_FAST_DBM ADVANCE_FAST_SBM

#define ADVANCE_EQSP_DBM_	ADVANCE_EQSP_DBM
#define ADVANCE_EQSP_DBM_1SRC	ADVANCE_EQSP_DBM ADVANCE_EQSP_SRC1
#define ADVANCE_EQSP_DBM_1S_1SRC	ADVANCE_EQSP_DBM_1SRC
#define ADVANCE_EQSP_DBM_1S_	/* nop */
#define ADVANCE_EQSP_DBM_2SRCS	ADVANCE_EQSP_DBM_1SRC ADVANCE_EQSP_SRC2
#define ADVANCE_EQSP_DBM_SBM	ADVANCE_EQSP_DBM ADVANCE_EQSP_SBM

#define ADVANCE_SLOW_DBM_	ADVANCE_SLOW_DBM
#define ADVANCE_SLOW_DBM_1SRC	ADVANCE_SLOW_DBM ADVANCE_SLOW_SRC1
#define ADVANCE_SLOW_DBM_2SRCS	ADVANCE_SLOW_DBM_1SRC ADVANCE_SLOW_SRC2
#define ADVANCE_SLOW_DBM_SBM	ADVANCE_SLOW_DBM ADVANCE_SLOW_SBM

#define GENERIC_FAST_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)	\
	_GENERIC_FAST_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)

#define GENERIC_EQSP_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)	\
	_GENERIC_EQSP_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)

#define GENERIC_SLOW_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)	\
	_GENERIC_SLOW_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)

#define GENERIC_FLEN_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)	\
	_GENERIC_FLEN_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)

#define GENERIC_ELEN_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)	\
	_GENERIC_ELEN_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)

#define GENERIC_SLEN_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)	\
	_GENERIC_SLEN_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)




/* FIXME still need to convert these to generic macros if possible */

#define _VEC_FUNC_MM( func_name, statement )		\
__VEC_FUNC_MM( func_name, statement );


#define _VEC_FUNC_MM_IND( func_name, statement1, statement2 )\
__VEC_FUNC_MM_IND( func_name, statement1, statement2 )

// 2V_PROJ SETUP and HELPER do the same thing, but have different input types
// (only relevant for mixed operations, e.g. summing float to double

#define ___VEC_FUNC_FAST_2V_PROJ_SETUP( func_name, expr )	\
								\
KERNEL_FUNC_PRELUDE						\
								\
KERNEL_FUNC_QUALIFIER void VFUNC_FAST_NAME(func_name##_setup)	\
	( DECLARE_KERN_ARGS_FAST_2V_PROJ_SETUP )		\
	FAST_2V_PROJ_BODY(expr,std_type)

#define ___VEC_FUNC_FAST_2V_PROJ_HELPER( func_name, expr )	\
								\
KERNEL_FUNC_PRELUDE						\
								\
KERNEL_FUNC_QUALIFIER void VFUNC_FAST_NAME(func_name##_helper)	\
	( DECLARE_KERN_ARGS_FAST_2V_PROJ_HELPER )		\
	FAST_2V_PROJ_BODY(expr,dest_type)

#define FAST_2V_PROJ_BODY(expr,type)				\
{								\
	INIT_INDICES_1						\
								\
	if( IDX1 < len2 ){					\
		KERNEL_ARG_QUALIFIER type *s2;			\
		s2 = s1 + len1;					\
		dest[IDX1] = expr ;				\
	} else if( IDX1 < len1 ){				\
		dest[IDX1] = s1[IDX1];				\
	}							\
}


#define ___VEC_FUNC_CPX_FAST_2V_PROJ_SETUP( func_name, re_expr, im_expr )\
									\
KERNEL_FUNC_PRELUDE						\
								\
	KERNEL_FUNC_QUALIFIER void VFUNC_FAST_NAME(func_name##_setup)	\
		( DECLARE_KERN_ARGS_CPX_FAST_2V_PROJ_SETUP )		\
	FAST_CPX_2V_PROJ_BODY(re_expr,im_expr,std_cpx)

#define ___VEC_FUNC_CPX_FAST_2V_PROJ_HELPER( func_name, re_expr, im_expr )\
									\
KERNEL_FUNC_PRELUDE						\
								\
	KERNEL_FUNC_QUALIFIER void VFUNC_FAST_NAME(func_name##_helper)	\
		( DECLARE_KERN_ARGS_CPX_FAST_2V_PROJ_HELPER )		\
	FAST_CPX_2V_PROJ_BODY(re_expr,im_expr,dest_cpx)

#define FAST_CPX_2V_PROJ_BODY(re_expr,im_expr,type)			\
	{								\
		INIT_INDICES_1						\
									\
		if( IDX1 < len2 ){					\
			type *s2;					\
			s2 = s1 + len1;					\
			dest[IDX1].re = re_expr ;			\
			dest[IDX1].im = im_expr ;			\
		} else if( IDX1 < len1 ){				\
			dest[IDX1].re = s1[IDX1].re;			\
			dest[IDX1].im = s1[IDX1].im;			\
		}							\
	}



#define ___VEC_FUNC_QUAT_FAST_2V_PROJ_SETUP( func_name, re_expr, im_expr1, im_expr2, im_expr3 )	\
									\
KERNEL_FUNC_PRELUDE						\
								\
	KERNEL_FUNC_QUALIFIER void VFUNC_FAST_NAME(func_name##_setup)	\
		( DECLARE_KERN_ARGS_QUAT_FAST_2V_PROJ_SETUP )		\
	FAST_QUAT_2V_PROJ_BODY(re_expr,im_expr1,im_expr2,im_expr3,std_quat)

#define ___VEC_FUNC_QUAT_FAST_2V_PROJ_HELPER( func_name, re_expr, im_expr1, im_expr2, im_expr3 )	\
									\
KERNEL_FUNC_PRELUDE						\
								\
	KERNEL_FUNC_QUALIFIER void VFUNC_FAST_NAME(func_name##_helper)	\
		( DECLARE_KERN_ARGS_QUAT_FAST_2V_PROJ_HELPER )		\
	FAST_QUAT_2V_PROJ_BODY(re_expr,im_expr1,im_expr2,im_expr3,dest_quat)


#define FAST_QUAT_2V_PROJ_BODY(re_expr,im_expr1,im_expr2,im_expr3,type)	\
	{								\
		INIT_INDICES_1						\
									\
		if( IDX1 < len2 ){					\
			type *s2;					\
			s2 = s1 + len1;					\
			dest[IDX1].re = re_expr ;			\
			dest[IDX1]._i = im_expr1 ;			\
			dest[IDX1]._j = im_expr2 ;			\
			dest[IDX1]._k = im_expr3 ;			\
		} else if( IDX1 < len1 ){				\
			dest[IDX1].re = s1[IDX1].re;			\
			dest[IDX1]._i = s1[IDX1]._i;			\
			dest[IDX1]._j = s1[IDX1]._j;			\
			dest[IDX1]._k = s1[IDX1]._k;			\
		}							\
	}



// BUG? does this need to be two macros, one for setup and one for helper?


#define ___VEC_FUNC_FAST_2V_PROJ_IDX( func_name, statement1, statement2 )	\
										\
KERNEL_FUNC_PRELUDE						\
								\
	KERNEL_FUNC_QUALIFIER void VFUNC_FAST_IDX_SETUP_NAME(func_name)		\
		( DECLARE_KERN_ARGS_FAST_IDX_SETUP )				\
	{									\
		INIT_INDICES_3							\
		if( index3 < len2 )						\
			statement1 ;						\
		else if( IDX1 < len1 )						\
			dst = index2 ;						\
	}									\
										\
	KERNEL_FUNC_QUALIFIER void VFUNC_FAST_IDX_HELPER_NAME(func_name)	\
		( DECLARE_KERN_ARGS_FAST_IDX_HELPER )				\
	{									\
		INIT_INDICES_3							\
		if( index3 < len2 )						\
			statement2 ;						\
		else if( IDX1 < len1 )						\
			dst = src1 ;						\
	}



/* For nocc_setup, we index directly into the value and count temp arrays
 * (a and b, respectively), but we have to double the index for the source
 * array c, and the index array d.  Because we are comparing adjacent pairs, 
 */


// vsum, vdot, etc
// BUG this is hard-coded for vsum!?
//
// The idea is that , because all threads cannot access the destination simultaneously,
// we have to make the source smaller recursively...  But when we project
// to a vector instead of a scalar, we can to the elements of the vector in parallel...
// This is quite tricky.
//
// Example:  col=sum(m)
//
// m = | 1 2 3 4 |
//     | 5 6 7 8 |
//
// tmp = | 4  6  |
//       | 12 14 |
//
// col = | 10 |
//       | 26 |
     

// BUG - we need to make this do vmaxv and vminv as well.
// It's the same except for the sum line, which would be replaced with
//

#define psrc1	s1[IDX1]
#define psrc2	s2[IDX1]

// for vsum:   psrc1 + psrc2
// for vmaxv:  psrc1 > psrc2 ? psrc1 : psrc2

// left shift was broken on cuda, what about now?

#define LSHIFT_SWITCH_32( ls_dst , arg1 , arg2 )			\
	switch(arg2) {							\
		case 0:  ls_dst = arg1;     break;			\
		case 1:  ls_dst = arg1<<1;  break;			\
		case 2:  ls_dst = arg1<<2;  break;			\
		case 3:  ls_dst = arg1<<3;  break;			\
		case 4:  ls_dst = arg1<<4;  break;			\
		case 5:  ls_dst = arg1<<5;  break;			\
		case 6:  ls_dst = arg1<<6;  break;			\
		case 7:  ls_dst = arg1<<7;  break;			\
		case 8:  ls_dst = arg1<<8;  break;			\
		case 9:  ls_dst = arg1<<9;  break;			\
		case 10: ls_dst = arg1<<10; break;			\
		case 11: ls_dst = arg1<<11; break;			\
		case 12: ls_dst = arg1<<12; break;			\
		case 13: ls_dst = arg1<<13; break;			\
		case 14: ls_dst = arg1<<14; break;			\
		case 15: ls_dst = arg1<<15; break;			\
		case 16: ls_dst = arg1<<16; break;			\
		case 17: ls_dst = arg1<<17; break;			\
		case 18: ls_dst = arg1<<18; break;			\
		case 19: ls_dst = arg1<<19; break;			\
		case 20: ls_dst = arg1<<20; break;			\
		case 21: ls_dst = arg1<<21; break;			\
		case 22: ls_dst = arg1<<22; break;			\
		case 23: ls_dst = arg1<<23; break;			\
		case 24: ls_dst = arg1<<24; break;			\
		case 25: ls_dst = arg1<<25; break;			\
		case 26: ls_dst = arg1<<26; break;			\
		case 27: ls_dst = arg1<<27; break;			\
		case 28: ls_dst = arg1<<28; break;			\
		case 29: ls_dst = arg1<<29; break;			\
		case 30: ls_dst = arg1<<30; break;			\
		case 31: ls_dst = arg1<<31; break;			\
	}

// vsum, vdot, etc
// BUG this is hard-coded for vsum!?
//
// The idea is that , because all threads cannot access the destination simultaneously,
// we have to make the source smaller recursively...  But when we project
// to a vector instead of a scalar, we can to the elements of the vector in parallel...
// This is quite tricky.
//
// Example:  col=sum(m)
//
// m = | 1 2 3 4 |
//     | 5 6 7 8 |
//
// tmp = | 4  6  |
//       | 12 14 |
//
// col = | 10 |
//       | 26 |
     

// BUG - we need to make this do vmaxv and vminv as well.
// It's the same except for the sum line, which would be replaced with
//

#define psrc1	s1[IDX1]
#define psrc2	s2[IDX1]

// for vsum:   psrc1 + psrc2
// for vmaxv:  psrc1 > psrc2 ? psrc1 : psrc2

#define ___VFUNC_CALL_2V_PROJ( func_name, type_code, expr )		\
									\
KERNEL_FUNC_PRELUDE							\
									\
	KERNEL_FUNC_QUALIFIER void g_##type_code##_##func_name		\
		( DECLARE_KERN_ARGS_2V_PROJ )				\
	{								\
		INIT_INDICES_1						\
									\
		if( IDX1 < len2 ){					\
			std_type *s2;					\
			s2 = s1 + len1;					\
			dest[IDX1] = expr ;				\
		} else if( IDX1 < len1 ){				\
			dest[IDX1] = s1[IDX1];				\
		}							\
	}

// BUG - this is vdot, needs setup and helper, because first pass is products
// subsequent passes are sums.  Maybe it shouldn't be a primitive?

#define ___VFUNC_CALL_FAST_3V_PROJ( func_name, type_code )		\
									\
KERNEL_FUNC_PRELUDE							\
									\
	KERNEL_FUNC_QUALIFIER void VFUNC_FAST_NAME(func_name)		\
		( DECLARE_KERN_ARGS_FAST_3V_PROJ )			\
	{								\
		INIT_INDICES_1						\
		if( IDX1 < len2 ){					\
			std_type *s1b;					\
			std_type *s2b;					\
			s1b = s1 + len1;				\
			s2b = s2 + len1;				\
			dest[IDX1] = s1[IDX1] * s2[IDX1] +		\
				s1b[IDX1] * s2b[IDX1] ;			\
		} else if( IDX1 < len1 ){				\
			dest[IDX1] = s1[IDX1];				\
		}							\
	}

#define ___VEC_FUNC_MM( func_name, type_code, statement )		\
									\
KERNEL_FUNC_PRELUDE							\
									\
	KERNEL_FUNC_QUALIFIER void VFUNC_HELPER_NAME(func_name,type_code)\
	( DECLARE_KERN_ARGS_MM )						\
	{								\
		INIT_INDICES_3						\
		if( index3.d5_dim[1] < len2 )					\
			statement ;					\
		else if( IDX1 < len1 )				\
			dst = src1 ;					\
	}								\
									\

/* For nocc_setup, we index directly into the value and count temp arrays
 * (a and b, respectively), but we have to double the index for the source
 * array c, and the index array d.  Because we are comparing adjacent pairs, 
 *
 * We assume that the data are contiguous, and use fast (single) indices.
 */


#define ___VFUNC_CALL_FAST_MM_NOCC( func_name, type_code, test1, test2 )	\
	___VEC_FUNC_FAST_MM_NOCC( func_name, test1, test2 )


/* For nocc_setup, we index directly into the value and count temp arrays
 * (a and b, respectively), but we have to double the index for the source
 * array c, and the index array d.  Because we are comparing adjacent pairs, 
 */

#define ___VEC_FUNC_FAST_MM_NOCC( func_name, test1, test2 )			\
									\
	___VEC_FUNC_FAST_MM_NOCC_SETUP( func_name, test1, test2 )		\
	___VEC_FUNC_FAST_MM_NOCC_HELPER( func_name, test1, test2 )


#ifndef IDX2
#define IDX2	index2
#endif // ! IDX2

// How are we handling the indices???

#define ___VEC_FUNC_FAST_MM_NOCC_SETUP( func_name, test1, test2 )		\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void VFUNC_FAST_NOCC_SETUP_NAME(func_name)	\
	( DECLARE_KERN_ARGS_FAST_NOCC_SETUP )				\
{									\
	INIT_INDICES_2							\
	IDX2 *= 2;							\
	if( IDX1 < len2 ){						\
		if( test1 ){						\
			dst_extrema[IDX1] = src_vals[IDX2];		\
			dst_counts[IDX1]=1;				\
			dst_indices[IDX2]=IDX2;			\
		} else if( test2 ){					\
			dst_extrema[IDX1] = src_vals[IDX2+1];	\
			dst_counts[IDX1]=1;				\
			dst_indices[IDX2]=IDX2+1;			\
		} else {						\
			dst_extrema[IDX1] = src_vals[IDX2];		\
			dst_counts[IDX1]=2;				\
			dst_indices[IDX2]=IDX2;			\
			dst_indices[IDX2+1]=IDX2+1;			\
		}							\
	} else {							\
		/* Nothing to compare */				\
		dst_extrema[IDX1] = src_vals[IDX2];			\
		dst_counts[IDX1]=1;					\
		dst_indices[IDX2]=IDX2;				\
	}								\
}

// indices and stride example:
//
// src data			ext_val			indices				counts
// 0  1  5  5  5  2  2  2	1   5   5   2		1  X  2   3   4  X  6   7	1  2  1  2		setup, n=4
// 1  5  5  2			5   5			2  3 (2) (3)  4  X (6) (7)	2  1			helper, n=2, stride=4
// 5  5				5			2  3  4  (3) (4) X (6) (7)	3			helper, n=1, stride=8

#define ___VEC_FUNC_FAST_MM_NOCC_HELPER( func_name, test1, test2 )	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void VFUNC_FAST_NOCC_HELPER_NAME(func_name)	\
	( DECLARE_KERN_ARGS_FAST_NOCC_HELPER )				\
{									\
	int i;								\
	INIT_INDICES_2							\
	IDX2 *= 2;							\
	if( IDX1 < len2 ){						\
		if( test1 ){						\
			dst_extrema[IDX1]=src_vals[IDX2];		\
			dst_counts[IDX1]=src_counts[IDX2];		\
			/* No copy necessary */				\
		} else if( test2 ){					\
			dst_extrema[IDX1]=src_vals[IDX2+1];		\
			dst_counts[IDX1]=src_counts[IDX2+1];	\
			/* Now copy the indices down */			\
			for(i=0;i<dst_counts[IDX1];i++){		\
				dst_indices[IDX1*stride+i] =		\
		dst_indices[IDX1*stride+stride/2+i];			\
			}						\
		} else {						\
			dst_extrema[IDX1]=src_vals[IDX2];		\
			dst_counts[IDX1] = src_counts[IDX2] + 	\
				src_counts[IDX2+1];			\
			/* Now copy the second half of the indices */	\
			for(i=0;i<src_counts[IDX2+1];i++){		\
	dst_indices[IDX1*stride+src_counts[IDX2]+i] =		\
		dst_indices[IDX1*stride+stride/2+i];			\
			}						\
		}							\
	} else {							\
		dst_extrema[IDX1]=src_vals[IDX2];			\
		dst_counts[IDX1]=src_counts[IDX2];			\
		/* No copy necessary */					\
	}								\
}


#define __GENERIC_FAST_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_FAST_CALL_NAME(name)			\
	( DECLARE_KERN_ARGS_FAST_##bm##typ##scalars##vectors )		\
{									\
	DECL_EXTRA_##extra						\
	INIT_INDICES_##bm##vectors					\
	statement ;							\
}

#define __GENERIC_EQSP_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_EQSP_CALL_NAME(name)( DECLARE_KERN_ARGS_EQSP_##bm##typ##scalars##vectors )	\
{									\
	DECL_EXTRA_##extra						\
	INIT_INDICES_##bm##vectors					\
	SCALE_INDICES_EQSP_##bm##vectors				\
	statement;							\
}

// BUG change to CAN_INDEX_THREE_DIMS

#define __GENERIC_SLOW_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_SLOW_CALL_NAME(name)( DECLARE_KERN_ARGS_SLOW_##bm##typ##scalars##vectors)	\
{									\
	DECL_EXTRA_##extra						\
	/*INIT_INDICES_XYZ_##bm##vectors*/					\
	/*SCALE_INDICES_XYZ_##bm##vectors*/				\
	INIT_INDICES_##bm##vectors					\
	SCALE_INDICES_##bm##vectors				\
	statement;						\
}

#ifdef BUILD_FOR_CUDA

#define __GENERIC_FLEN_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_FLEN_CALL_NAME(name)( DECLARE_KERN_ARGS_FLEN_##bm##typ##scalars##vectors)	\
{									\
	DECL_EXTRA_##extra						\
	INIT_INDICES_##bm##vectors					\
	if( IDX1 < len) {						\
		statement ;						\
	}								\
}

#define __GENERIC_ELEN_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_ELEN_CALL_NAME(name)( DECLARE_KERN_ARGS_ELEN_##bm##typ##scalars##vectors)	\
{									\
	DECL_EXTRA_##extra						\
	INIT_INDICES_##bm##vectors					\
	if( IDX1 < len ){					\
		SCALE_INDICES_EQSP_##bm##vectors			\
		statement;						\
	}								\
}

// Does OpenCL have a limit (like CUDA) on the number of dimensions (3)?

//	if( IDX1 < xyz_len.x && index1.y < xyz_len.y && index1.z < xyz_len.z ){

#define SLEN_SUBTST(index_name,len,dim_idx)	index_name.d5_dim[dim_idx] < len.d5_dim[dim_idx]

#define SLEN_IDX_TEST(idx,len)	( SLEN_SUBTST(idx,len,0) && SLEN_SUBTST(idx,len,1) && SLEN_SUBTST(idx,len,2) && SLEN_SUBTST(idx,len,3) && SLEN_SUBTST(idx,len,4) )

#define __GENERIC_SLEN_VEC_FUNC(name,statement,bm,typ,scalars,vectors,extra)	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_SLEN_CALL_NAME(name)( DECLARE_KERN_ARGS_SLEN_##bm##typ##scalars##vectors)	\
{									\
	DECL_EXTRA_##extra						\
	/*INIT_INDICES_XYZ_##bm##vectors*/					\
	INIT_INDICES_##bm##vectors					\
	if( SLEN_IDX_TEST(index1,szarr) ){				\
		/*SCALE_INDICES_XYZ_##bm##vectors*/				\
		SCALE_INDICES_##bm##vectors				\
		statement;						\
	}								\
}

#endif // BUILD_FOR_CUDA


/* These are for calls with a destination bitmap (vvm_lt etc)
 *
 * Here we cannot vectorize over all the pixels, because multiple
 * pixels share the same bitmap word.  Each thread has to set all the bits
 * in a given word.
 */


#ifdef BUILD_FOR_CUDA

#define REAL_CONVERSION( from_key, from_type, to_key, to_type )		\
									\
FAST_CONVERSION(from_key,from_type,to_key,to_type)			\
EQSP_CONVERSION(from_key,from_type,to_key,to_type)			\
SLOW_CONVERSION(from_key,from_type,to_key,to_type)			\
FLEN_CONVERSION(from_key,from_type,to_key,to_type)			\
ELEN_CONVERSION(from_key,from_type,to_key,to_type)			\
SLEN_CONVERSION(from_key,from_type,to_key,to_type)

#else // ! BUILD_FOR_CUDA


#define REAL_CONVERSION( from_key, from_type, to_key, to_type )		\
									\
FAST_CONVERSION(from_key,from_type,to_key,to_type)			\
EQSP_CONVERSION(from_key,from_type,to_key,to_type)			\
SLOW_CONVERSION(from_key,from_type,to_key,to_type)

#endif // ! BUILD_FOR_CUDA

#define FAST_CONVERSION(from_key,from_type,to_key,to_type)		\
_GENERIC_FAST_CONV_FUNC( v##from_key##2##to_key, from_type, to_type )

#define EQSP_CONVERSION(from_key,from_type,to_key,to_type)		\
_GENERIC_EQSP_CONV_FUNC( v##from_key##2##to_key, from_type, to_type )

#define SLOW_CONVERSION(from_key,from_type,to_key,to_type)		\
_GENERIC_SLOW_CONV_FUNC( v##from_key##2##to_key, from_type, to_type )

#define FLEN_CONVERSION(from_key,from_type,to_key,to_type)		\
_GENERIC_FLEN_CONV_FUNC( v##from_key##2##to_key, from_type, to_type )

#define ELEN_CONVERSION(from_key,from_type,to_key,to_type)		\
_GENERIC_ELEN_CONV_FUNC( v##from_key##2##to_key, from_type, to_type )

#define SLEN_CONVERSION(from_key,from_type,to_key,to_type)		\
_GENERIC_SLEN_CONV_FUNC( v##from_key##2##to_key, from_type, to_type )

// Here is the kernel itself...
// BUG these seem all the same!?
#define __GENERIC_FAST_CONV_FUNC( name, from_type, to_type )		\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_FAST_CALL_NAME(name)( DECLARE_KERN_ARGS_FAST_CONV(to_type) )	\
{									\
	INIT_INDICES_2							\
	dst = (to_type) src1 ;						\
}

#define __GENERIC_EQSP_CONV_FUNC( name, from_type, to_type )		\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_EQSP_CALL_NAME(name)( DECLARE_KERN_ARGS_EQSP_CONV(to_type) )	\
{									\
	INIT_INDICES_2							\
	SCALE_INDICES_2							\
	dst = (to_type) src1 ;						\
}

#define __GENERIC_SLOW_CONV_FUNC( name, from_type, to_type )		\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_SLOW_CALL_NAME(name)( DECLARE_KERN_ARGS_SLOW_CONV(to_type) )	\
{									\
	/*INIT_INDICES_XYZ_2*/						\
	/*SCALE_INDICES_XYZ_2*/						\
	INIT_INDICES_2							\
	SCALE_INDICES_2							\
	dst = (to_type) src1 ;						\
}

#define __GENERIC_FLEN_CONV_FUNC( name, from_type, to_type )		\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_FLEN_CALL_NAME(name)( DECLARE_KERN_ARGS_FLEN_CONV(to_type) )	\
{									\
	INIT_INDICES_2							\
	if( IDX1 < len) {						\
		dst = (to_type) src1 ;					\
	}								\
}

#define __GENERIC_ELEN_CONV_FUNC( name, from_type, to_type )		\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_ELEN_CALL_NAME(name)( DECLARE_KERN_ARGS_ELEN_CONV(to_type) )	\
{									\
	INIT_INDICES_2							\
	if( IDX1 < len) {						\
		SCALE_INDICES_2						\
		dst = (to_type) src1 ;					\
	}								\
}

#define __GENERIC_SLEN_CONV_FUNC( name, from_type, to_type )		\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_SLEN_CALL_NAME(name)( DECLARE_KERN_ARGS_SLEN_CONV(to_type) )	\
{									\
	/*INIT_INDICES_XYZ_2*/						\
	INIT_INDICES_2							\
	if( SLEN_IDX_TEST(index1,szarr) ){				\
		/*SCALE_INDICES_XYZ_2*/					\
		SCALE_INDICES_2						\
		dst = (to_type) src1 ;					\
	}								\
}


#define __GENERIC_FAST_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_FAST_CALL_NAME(name)( DECLARE_KERN_ARGS_FAST_DBM_##typ##scalars##vectors )	\
{									\
	INIT_INDICES_DBM_##scalars##vectors					\
	/*ADJUST_DBM_WORD_IDX*/							\
	FAST_DBM_LOOP( statement, ADVANCE_FAST_DBM_##vectors )		\
}

// EQSP is tricky because the number of relevant bits in a word is no
// longer all of the bits - so the LOOP should just loop over the bits
// in a single word!?  BUG?

#define __GENERIC_EQSP_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_EQSP_CALL_NAME(name)( DECLARE_KERN_ARGS_EQSP_DBM_##typ##scalars##vectors )	\
{									\
	INIT_INDICES_DBM_##scalars##vectors					\
	SCALE_INDICES_EQSP_DBM_##scalars##vectors				\
	/*ADJUST_DBM_WORD_IDX*/							\
	EQSP_DBM_LOOP(statement,ADVANCE_EQSP_DBM_##scalars##vectors)		\
}


#define __GENERIC_SLOW_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_SLOW_CALL_NAME(name)( DECLARE_KERN_ARGS_SLOW_DBM_##typ##scalars##vectors)	\
{									\
	/*INIT_INDICES_XYZ_DBM_##vectors*/					\
	/*SCALE_INDICES_XYZ_DBM_##vectors*/					\
	INIT_INDICES_DBM_##scalars##vectors					\
	SCALE_INDICES_DBM_##vectors					\
									\
	/*ADJUST_DBM_WORD_IDX*/							\
	SLOW_DBM_LOOP( statement , ADVANCE_SLOW_DBM_##vectors )		\
}

#ifdef BUILD_FOR_CUDA

#define __GENERIC_FLEN_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_FLEN_CALL_NAME(name)( DECLARE_KERN_ARGS_FLEN_DBM_##typ##scalars##vectors)	\
{									\
	INIT_INDICES_DBM_##scalars##vectors					\
	FLEN_DBM_LOOP(statement,ADVANCE_FAST_DBM_##vectors)			\
}

#define __GENERIC_ELEN_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_ELEN_CALL_NAME(name)( DECLARE_KERN_ARGS_ELEN_DBM_##typ##scalars##vectors)	\
{									\
	INIT_INDICES_DBM_##scalars##vectors					\
	SCALE_INDICES_EQSP_DBM_##scalars##vectors				\
	/* BUG need to put len test in statement */			\
	/*ADJUST_DBM_WORD_IDX*/							\
	FLEN_DBM_LOOP( statement, ADVANCE_EQSP_DBM_##scalars##vectors )		\
}



#define __GENERIC_SLEN_VEC_FUNC_DBM(name,statement,typ,scalars,vectors)	\
									\
KERNEL_FUNC_PRELUDE							\
									\
KERNEL_FUNC_QUALIFIER void GPU_SLEN_CALL_NAME(name)( DECLARE_KERN_ARGS_SLEN_DBM_##typ##scalars##vectors)	\
{									\
	/*INIT_INDICES_XYZ_DBM_##vectors*/					\
	/*SCALE_INDICES_XYZ_DBM_##vectors*/					\
	INIT_INDICES_DBM_##scalars##vectors					\
	SCALE_INDICES_DBM_##vectors					\
									\
	/* BUG need to put len test in statement */			\
	/* BUG can we test before scaling??? */				\
	/*ADJUST_DBM_WORD_IDX*/						\
	SLEN_DBM_LOOP( statement , ADVANCE_SLOW_DBM_##vectors )		\
}

#endif // BUILD_FOR_CUDA


#define ___VFUNC_CALL_MM( func_name, type_code, statement )		\
									\
KERNEL_FUNC_PRELUDE							\
									\
	KERNEL_FUNC_QUALIFIER void g_##type_code##_##func_name##_helper		\
	( DECLARE_KERN_ARGS_MM )						\
	{								\
		INIT_INDICES_3						\
		if( index3.d5_dim[1] < len2 )					\
			statement ;					\
		else if( IDX1 < len1 )				\
			dst = src1 ;					\
	}								\
									\

#define ___VFUNC_CALL_MM_IND( func_name, type_code, statement1, statement2 )\
									\
KERNEL_FUNC_PRELUDE							\
									\
	KERNEL_FUNC_QUALIFIER void g_##type_code##_##func_name##_index_setup	\
	(index_type* a, std_type* b, std_type* c, uint32_t len1, uint32_t len2)\
	{								\
		INIT_INDICES_3						\
		if( index3.d5_dim[1] < len2 )					\
			statement1 ;					\
		else if( IDX1 < len1 )				\
			dst = index2.d5_dim[1] ;				\
	}								\
									\
	KERNEL_FUNC_QUALIFIER void g_##type_code##_##func_name##_index_helper	\
		(index_type* a, index_type* b, index_type* c,		\
				std_type *orig, uint32_t len1, uint32_t len2)	\
	{								\
		INIT_INDICES_3						\
		if( index3.d5_dim[1] < len2 )					\
			statement2 ;					\
		else if( IDX1 < len1 )				\
			dst = src1 ;					\
	}								\
									\

#ifdef FOOBAR
// hard-coded for vdot!?
// BUG - for gpu needs helper and setup to take products once and then sum

#define ___VEC_FUNC_FAST_3V_PROJ( func_name)				\
									\
	KERNEL_FUNC_QUALIFIER void VFUNC_FAST_NAME(func_name)		\
		( DECLARE_KERN_ARGS_FAST_3V_PROJ )			\
	{								\
		INIT_INDICES_1						\
		if( IDX1 < len2 ){					\
			std_type *s1b;					\
			std_type *s2b;					\
			s1b = s1 + len1;				\
			s2b = s2 + len1;				\
			dest[IDX1] = s1[IDX1] * s2[IDX1] +		\
				s1b[IDX1] * s2b[IDX1] ;			\
		} else if( IDX1 < len1 ){				\
			dest[IDX1] = s1[IDX1];				\
		}							\
	}


#define ___VEC_FUNC_CPX_FAST_3V_PROJ( func_name)			\
									\
	KERNEL_FUNC_QUALIFIER void VFUNC_FAST_NAME(func_name)		\
		( DECLARE_KERN_ARGS_CPX_FAST_3V_PROJ )			\
	{								\
		INIT_INDICES_1						\
		if( IDX1 < len2 ){					\
			std_cpx *s1b;					\
			std_cpx *s2b;					\
			s1b = s1 + len1;				\
			s2b = s2 + len1;				\
			dest[IDX1].re = s1[IDX1].re * s2[IDX1].re -	\
					s1[IDX1].im * s2[IDX1].im +	\
				s1b[IDX1].re * s2b[IDX1].re -	\
				s1b[IDX1].im * s2b[IDX1].im ;		\
			dest[IDX1].im = s1[IDX1].re * s2[IDX1].im +	\
				s1[IDX1].im * s2[IDX1].re +	\
				s1b[IDX1].re * s2b[IDX1].im +		\
				s1b[IDX1].im * s2b[IDX1].re ;		\
		} else if( IDX1 < len1 ){				\
			dest[IDX1].re = s1[IDX1].re;			\
			dest[IDX1].im = s1[IDX1].im;			\
		}							\
	}

#endif // FOOBAR

