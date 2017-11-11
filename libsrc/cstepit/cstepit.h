

#ifdef INC_VERSION
char VersionId_inc_cstepit[] = QUIP_VERSION_STRING;
#endif /* INC_VERSION */

#ifndef VARS

#include "optimize.h"

#define VARS		MAX_OPT_PARAMS
#define VVARS		(VARS+5)
#define DATA 100
#define GRAIN 1000
#define STRING 80



/* stepit.c */

extern int stepit(QSP_ARG_DECL  void (*func)(void));
extern void halt_cstepit(void);
extern void getvals(double *,int);
extern void setvals(QSP_ARG_DECL  double *,int);
extern void setfobj(double);
extern void setminmax(QSP_ARG_DECL  double *,double *,int);
extern void setdelta(QSP_ARG_DECL  double *,double *,int);
extern void settrace(int);
extern void setmaxcalls(int);
extern int _reset_n_params(QSP_ARG_DECL  int);
#define reset_n_params(n) _reset_n_params(QSP_ARG  n)

/* quick.c */

extern void fn(void);


/* cs_supp.c */
COMMAND_FUNC( run_cstepit_scr );
void run_cstepit_c(QSP_ARG_DECL  float (*func)(SINGLE_QSP_ARG_DECL));

#endif /* undef VARS */

