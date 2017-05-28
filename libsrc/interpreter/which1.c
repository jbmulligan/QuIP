#include "quip_config.h"

#include <stdio.h>
#ifdef HAVE_STRING_H
#include <string.h>
#endif

#include "quip_prot.h"
#include "query_stack.h"
#include "query_prot.h"
#include "warn.h"
#include "history.h"
//#include "substr.h"

static int _one_of(QSP_ARG_DECL  const char *, int, const char **);


static int _one_of(QSP_ARG_DECL  const char *prompt, int n, const char** choices)
{
	int i;
	int nmatches=0;
	int lastmatch=(-1);	/* init to elim warning */
	const char *last_pick;

#ifdef HAVE_HISTORY
	if( IS_COMPLETING(THIS_QSP) && intractive(SINGLE_QSP_ARG) && *prompt ){
		char pline[LLEN];
		if( QS_FLAGS(THIS_QSP) & QS_FORMAT_PROMPT )
			sprintf(pline,PROMPT_FORMAT,prompt);
		else
			strcpy(pline,prompt);
		preload_history_list(QSP_ARG  pline,n,choices);
	}
#endif /* HAVE_HISTORY */

	/* last_pick=next_query_word(prompt); */
	last_pick = NAMEOF(prompt);

	for(i=0;i<n;i++){
		/* BUG we should be able to get rid of the test for null choices
		 * after we fix the precision initialization...
		 */
		if( choices[i] != NULL && !strcmp( last_pick, choices[i] ) ){
			return(i);
		}
	}
	
	/* if no exact match check for substring match */
	for(i=0;i<n;i++)
		if( is_a_substring( last_pick, choices[i] ) ){
			lastmatch=i;
			nmatches++;
		}
	if( nmatches==1 ){
		sprintf(ERROR_STRING,"Unambiguous substring match of \"%s\" to \"%s\"",
			last_pick,choices[lastmatch]);
		//advise(ERROR_STRING);
		WARN(ERROR_STRING);
		return(lastmatch);
	}
	else if( nmatches > 1 ){
		sprintf(ERROR_STRING,"ambiguous choice \"%s\"",last_pick);
		WARN(ERROR_STRING);
		return(-1);
	}

	sprintf(ERROR_STRING,"invalid choice \"%s\"",last_pick);
	WARN(ERROR_STRING);
	sprintf(ERROR_STRING,"valid selections for %s are:",prompt);
	advise(ERROR_STRING);
	for(i=0;i<n;i++){
		sprintf(ERROR_STRING,"\t%s",choices[i]);
		advise(ERROR_STRING);
	}
#ifdef HAVE_HISTORY
	if( intractive(SINGLE_QSP_ARG) ) rem_def(QSP_ARG  prompt,last_pick) ;
#endif /* HAVE_HISTORY */

	return(-1);
}

/* sometimes we would like to repetetively prompt the user
 * for a word from the list, and other times not!?
 */

int which_one(QSP_ARG_DECL  const char *prompt,int n,const char** choices)
{
	return _one_of(QSP_ARG prompt,n,choices);
}


int which_one2(QSP_ARG_DECL  const char* s,int n,const char** choices)
{
	inhibit_next_prompt_format(SINGLE_QSP_ARG);
	return _one_of(QSP_ARG s,n,choices);
}


