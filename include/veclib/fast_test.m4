
dnl	/*
dnl	 * We use the fast method only if everything is contiguous, and if the shapes
dnl	 * are identical.
dnl	 */

dnl	For pure bit operations (vand etc) there needs to be a different test!?
dnl	The above should be true, but bit0 should also be zero or a multiple of
dnl	the word size...
dnl	The "bitmap" arg below is DBM or SBM or nothing, this macro does not take
dnl	into account the type of the operand...
dnl	So the bit operations need something special...

dnl	// But for the NOCC methods, we need to do something different...
dnl	// We assume the index array is contiguous, and only test
dnl	// on the one source vector...

dnl FAST_TEST(bitmap,typ,vectors)
define(`FAST_TEST',`_FAST_TEST($1$2$3)')
define(`_FAST_TEST',FAST_TEST_$1)
define(`EQSP_TEST',EQSP_TEST_$1$2$3)

define(`FAST_TEST_NOCC',`FAST_TEST_1SRC')
define(`EQSP_TEST_NOCC',`EQSP_TEST_1SRC')

// When are these used???
dnl define(`FAST_TEST_',`0')
dnl define(`EQSP_TEST_',`0')

define(`FAST_TEST_CPX_1',`FAST_TEST_1')
define(`EQSP_TEST_CPX_1',`EQSP_TEST_1')
define(`FAST_TEST_QUAT_1',`FAST_TEST_1')
define(`EQSP_TEST_QUAT_1',`EQSP_TEST_1')

define(`FAST_TEST_1',`( N_IS_CONTIGUOUS(dst_dp) )')
define(`EQSP_TEST_1',`( IS_EVENLY_SPACED(dst_dp) )')

define(`FAST_TEST_1SRC',`( N_IS_CONTIGUOUS(SRC1_DP) )')
define(`EQSP_TEST_1SRC',`( IS_EVENLY_SPACED(SRC1_DP) )')

define(`FAST_TEST_2SRCS',`( FAST_TEST_1SRC && N_IS_CONTIGUOUS(SRC2_DP) && dp_same_size_query(SRC1_DP,SRC2_DP) )')

define(`EQSP_TEST_2SRCS',`( EQSP_TEST_1SRC && IS_EVENLY_SPACED(SRC2_DP) && dp_same_size_query(SRC1_DP,SRC2_DP) )')

define(`FAST_TEST_CONV',`FAST_TEST_2')
define(`FAST_TEST_LUTMAP_B',`FAST_TEST_2')
define(`FAST_TEST_LUTMAP_S',`FAST_TEST_2')

define(`FAST_TEST_2',`( FAST_TEST_1 && FAST_TEST_1SRC && dp_same_size_query(SRC1_DP,dst_dp) )')

define(`FAST_TEST_CPX_2',`FAST_TEST_2')
define(`EQSP_TEST_CPX_2',`EQSP_TEST_2')
define(`FAST_TEST_QUAT_2',`FAST_TEST_2')
define(`EQSP_TEST_QUAT_2',`EQSP_TEST_2')

define(`FAST_TEST_RC_2',`( FAST_TEST_1 && FAST_TEST_1SRC && dp_same_size_query(dst_dp,SRC1_DP) )')

define(`FAST_TEST_CR_2',`( FAST_TEST_1 && FAST_TEST_1SRC && dp_same_size_query_rc(SRC1_DP,dst_dp) )')

define(`FAST_TEST_QR_2',`FAST_TEST_CR_2')
define(`EQSP_TEST_QR_2',`EQSP_TEST_CR_2')

define(`EQSP_TEST_CONV',`EQSP_TEST_2')

define(`EQSP_TEST_2',`( EQSP_TEST_1 && EQSP_TEST_1SRC && dp_same_size_query(SRC1_DP,dst_dp) )')
define(`EQSP_TEST_LUTMAP_B',`EQSP_TEST_2')
define(`EQSP_TEST_LUTMAP_S',`EQSP_TEST_2')

define(`EQSP_TEST_RC_2',`( EQSP_TEST_1 && EQSP_TEST_1SRC && dp_same_size_query(dst_dp,SRC1_DP) )')

define(`EQSP_TEST_CR_2',`( EQSP_TEST_1 && EQSP_TEST_1SRC && dp_same_size_query_rc(SRC1_DP,dst_dp) )')

/* this is not used anywhere??? */
define(`FAST_TEST_M_2',`( FAST_TEST_1 && N_IS_CONTIGUOUS(SRC1_DP) && dp_equal_dims(SRC1_DP,dst_dp,1,4) )')

define(`FAST_TEST_SBM_1',`( N_IS_CONTIGUOUS(bitmap_src_dp) && N_IS_CONTIGUOUS(dst_dp) && dp_same_size_query(dst_dp,bitmap_src_dp) )')

define(`FAST_TEST_SBM_CPX_1',`( N_IS_CONTIGUOUS(bitmap_src_dp) && N_IS_CONTIGUOUS(dst_dp) && dp_same_size_query_rc(bitmap_src_dp,dst_dp) )')

define(`FAST_TEST_SBM_QUAT_1',`FAST_TEST_SBM_CPX_1')
define(`EQSP_TEST_SBM_QUAT_1',`EQSP_TEST_SBM_CPX_1')

define(`EQSP_TEST_SBM_1',`( IS_EVENLY_SPACED(bitmap_src_dp) && IS_EVENLY_SPACED(dst_dp) && dp_same_size_query(dst_dp,bitmap_src_dp) )')

define(`EQSP_TEST_SBM_CPX_1',`( IS_EVENLY_SPACED(bitmap_src_dp) && IS_EVENLY_SPACED(dst_dp) && dp_same_size_query_rc(bitmap_src_dp,dst_dp) )')

ifdef(`BUILD_FOR_GPU',`
define(`FAST_TEST_DBM_',`( N_IS_CONTIGUOUS(bitmap_dst_dp) && OBJ_BIT0(bitmap_dst_dp)==0 && (OBJ_N_TYPE_ELTS(bitmap_dst_dp)%BITS_PER_BITMAP_WORD)==0 )')
',`
define(`FAST_TEST_DBM_',`( N_IS_CONTIGUOUS(bitmap_dst_dp) )')
')

define(`FAST_TEST_DBM_1SRC',`( FAST_TEST_DBM_ && N_IS_CONTIGUOUS(SRC1_DP) && dp_same_size_query(SRC1_DP,bitmap_dst_dp) )')

define(`FAST_TEST_SBM',`( N_IS_CONTIGUOUS(bitmap_src_dp) && dp_same_size_query(bitmap_src_dp,bitmap_dst_dp) )')
dnl	BUG	bitmap fast test should include bit0==0 and size a multiple of word size!
define(`FAST_TEST_SBM1',`( N_IS_CONTIGUOUS(bitmap_src1_dp) && dp_same_size_query(bitmap_src1_dp,bitmap_dst_dp) )')
define(`FAST_TEST_SBM2',`( N_IS_CONTIGUOUS(bitmap_src2_dp) && dp_same_size_query(bitmap_src2_dp,bitmap_dst_dp) )')
define(`FAST_TEST_DBM_SBM',`( FAST_TEST_DBM_ && FAST_TEST_SBM )')
define(`FAST_TEST_DBM_1SBM',`( FAST_TEST_DBM_ && FAST_TEST_SBM1 )')
define(`FAST_TEST_DBM_2SBM',`( FAST_TEST_DBM_ && FAST_TEST_SBM1 && FAST_TEST_SBM2 )')

define(`FAST_TEST_DBM_2SRCS',`( FAST_TEST_DBM_ && N_IS_CONTIGUOUS(SRC1_DP) && N_IS_CONTIGUOUS(SRC2_DP) && dp_same_size_query(SRC1_DP,bitmap_dst_dp) && dp_same_size_query(SRC1_DP,bitmap_dst_dp))')

define(`EQSP_TEST_DBM_',`( IS_EVENLY_SPACED(bitmap_dst_dp) )')

define(`EQSP_TEST_DBM_1SRC',`( IS_EVENLY_SPACED(bitmap_dst_dp) && IS_EVENLY_SPACED(SRC1_DP) && dp_same_size_query(SRC1_DP,bitmap_dst_dp) )')

define(`EQSP_TEST_DBM_SBM',`( IS_EVENLY_SPACED(bitmap_dst_dp) && IS_EVENLY_SPACED(bitmap_src_dp) && dp_same_size_query(bitmap_src_dp,bitmap_dst_dp) )')
define(`EQSP_TEST_DBM_2SBM',`( IS_EVENLY_SPACED(bitmap_dst_dp) && IS_EVENLY_SPACED(bitmap_src1_dp) && IS_EVENLY_SPACED(bitmap_src2_dp) && dp_same_size_query(bitmap_src1_dp,bitmap_dst_dp) && dp_same_size_query(bitmap_src2_dp,bitmap_dst_dp) )')
define(`EQSP_TEST_DBM_1SBM',`( IS_EVENLY_SPACED(bitmap_dst_dp) && IS_EVENLY_SPACED(bitmap_src1_dp) && dp_same_size_query(bitmap_src1_dp,bitmap_dst_dp) )')

define(`EQSP_TEST_DBM_2SRCS',`( IS_EVENLY_SPACED(bitmap_dst_dp) && IS_EVENLY_SPACED(SRC1_DP) && IS_EVENLY_SPACED(SRC2_DP) && dp_same_size_query(SRC1_DP,bitmap_dst_dp) && dp_same_size_query(SRC1_DP,bitmap_dst_dp))')

define(`FAST_TEST_3',`( FAST_TEST_2 && N_IS_CONTIGUOUS(SRC2_DP) && dp_same_size_query(SRC2_DP,dst_dp) )')

define(`EQSP_TEST_3',`( EQSP_TEST_2 && IS_EVENLY_SPACED(SRC2_DP) && dp_same_size_query(SRC2_DP,dst_dp) )')

define(`FAST_TEST_CPX_3',`( FAST_TEST_CPX_2 && N_IS_CONTIGUOUS(SRC2_DP) && dp_same_size_query(SRC2_DP,dst_dp) )')

define(`EQSP_TEST_CPX_3',`( EQSP_TEST_CPX_2 && IS_EVENLY_SPACED(SRC2_DP) && dp_same_size_query(SRC2_DP,dst_dp) )')

define(`EQSP_TEST_QUAT_3',`( EQSP_TEST_QUAT_2 && IS_EVENLY_SPACED(SRC2_DP) && dp_same_size_query(SRC2_DP,dst_dp) )')

define(`FAST_TEST_QUAT_3',`( FAST_TEST_2 && N_IS_CONTIGUOUS(SRC2_DP) && dp_same_size_query(SRC2_DP,dst_dp) )')

define(`FAST_TEST_CCR_3',`( FAST_TEST_2 && N_IS_CONTIGUOUS(SRC2_DP) && dp_same_size_query_rc(SRC2_DP,dst_dp) )')

define(`EQSP_TEST_CCR_3',`( EQSP_TEST_2 && IS_EVENLY_SPACED(SRC2_DP) && dp_same_size_query_rc(SRC2_DP,dst_dp) )')

define(`FAST_TEST_QQR_3',`FAST_TEST_CCR_3')
define(`EQSP_TEST_QQR_3',`EQSP_TEST_CCR_3')

define(`FAST_TEST_SBM_2',`( FAST_TEST_2 && N_IS_CONTIGUOUS(bitmap_src_dp) && dp_same_size_query(bitmap_src_dp,dst_dp) )')

// BUG one of these should go...
// This is the new one
define(`FAST_TEST_SBM_CPX_2',`( FAST_TEST_2 && N_IS_CONTIGUOUS(bitmap_src_dp) && dp_same_size_query_rc(bitmap_src_dp,dst_dp) )')

// quat tests
define(`FAST_TEST_SBM_QUAT_2',`FAST_TEST_SBM_CPX_2')
define(`EQSP_TEST_SBM_QUAT_2',`EQSP_TEST_SBM_CPX_2')

// This one was here before
define(`FAST_TEST_CPX_SBM_2',`( FAST_TEST_2 && N_IS_CONTIGUOUS(bitmap_src_dp) && dp_same_size_query_rc(bitmap_src_dp,dst_dp) )')

define(`EQSP_TEST_SBM_2',`( EQSP_TEST_2 && IS_EVENLY_SPACED(bitmap_src_dp) && dp_same_size_query(bitmap_src_dp,dst_dp) )')

define(`EQSP_TEST_SBM_CPX_2',`( EQSP_TEST_2 && IS_EVENLY_SPACED(bitmap_src_dp) && dp_same_size_query_rc(bitmap_src_dp,dst_dp) )')

define(`FAST_TEST_QUAT_SBM_2',`( FAST_TEST_2 && N_IS_CONTIGUOUS(bitmap_src_dp) && dp_same_size_query(bitmap_src_dp,dst_dp) )')

/* not used? */
define(`FAST_TEST_SBM_3',`( FAST_TEST_3 && N_IS_CONTIGUOUS(bitmap_src_dp) && dp_same_size_query(bitmap_src_dp,dst_dp) )')

define(`FAST_TEST_SBM_CPX_3',`( FAST_TEST_3 && N_IS_CONTIGUOUS(bitmap_src_dp) && dp_same_size_query_rc(bitmap_src_dp,dst_dp) )')

define(`FAST_TEST_SBM_QUAT_3',`FAST_TEST_SBM_CPX_3')
define(`EQSP_TEST_SBM_QUAT_3',`EQSP_TEST_SBM_CPX_3')

define(`EQSP_TEST_SBM_3',`( EQSP_TEST_3 && IS_EVENLY_SPACED(bitmap_src_dp) && dp_same_size_query(bitmap_src_dp,dst_dp) )')

define(`EQSP_TEST_SBM_CPX_3',`( EQSP_TEST_3 && IS_EVENLY_SPACED(bitmap_src_dp) && dp_same_size_query_rc(bitmap_src_dp,dst_dp) )')

define(`FAST_TEST_4',`( FAST_TEST_3 && N_IS_CONTIGUOUS(SRC3_DP) && dp_same_size_query(SRC3_DP,dst_dp) )')

define(`FAST_TEST_5',`( FAST_TEST_4 && N_IS_CONTIGUOUS(SRC4_DP) && dp_same_size_query(SRC4_DP,dst_dp) )')

define(`EQSP_TEST_4',`( EQSP_TEST_3 && IS_EVENLY_SPACED(SRC3_DP) && dp_same_size_query(SRC3_DP,dst_dp) )')

define(`EQSP_TEST_5',`( EQSP_TEST_4 && IS_EVENLY_SPACED(SRC4_DP) && dp_same_size_query(SRC4_DP,dst_dp) )')


define(`dst_dp',oap->oa_dest)
define(`SRC_DP',OA_SRC_OBJ(oap,$1))
define(`SRC1_DP',SRC_DP(0))
define(`SRC2_DP',SRC_DP(1))
define(`SRC3_DP',SRC_DP(2))
define(`SRC4_DP',SRC_DP(3))
define(`SRC5_DP',SRC_DP(4))
define(`bitmap_src_dp',oap->oa_dp[4])
define(`bitmap_src1_dp',oap->oa_dp[0])
define(`bitmap_src2_dp',oap->oa_dp[1])
define(`bitmap_dst_dp',oap->oa_dest)


