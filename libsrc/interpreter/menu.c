
#include "quip_config.h"
#include "quip_prot.h"
#include "container_fwd.h"
#include "quip_menu.h"

void add_command_to_menu( Menu *mp, Command *cp )
{
	if( add_to_container(MENU_CONTAINER(mp),(Item *)cp) < 0 )
		NWARN("add_command_to_menu:  error adding command!?");
}

void list_menu(QSP_ARG_DECL  Menu *mp)
{
	List *lp;
	Node *np;

	lp = MENU_LIST(mp);
	np = QLIST_HEAD(lp);
	while( np != NULL ){
		Command *cp;
		cp = (Command *) NODE_DATA(np);
		list_command(QSP_ARG  cp);
		np = NODE_NEXT(np);
	}
}

