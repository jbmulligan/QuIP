
#include "quip_config.h"

#include "quip_prot.h"
#include "visca.h"
#include "item_type.h"

ITEM_INTERFACE_DECLARATIONS(Visca_Cmd_Set,cmd_set,0)
ITEM_INTERFACE_DECLARATIONS(Visca_Command,visca_cmd,0)
ITEM_INTERFACE_DECLARATIONS(Visca_Inquiry,visca_inq,0)


Item_Context *create_visca_cmd_context(QSP_ARG_DECL  const char *name)
{
	if( visca_cmd_itp == NULL )
		init_visca_cmds(SINGLE_QSP_ARG);

	return create_item_context(QSP_ARG  visca_cmd_itp, name);
}

void push_visca_cmd_context(QSP_ARG_DECL  Item_Context *icp)
{
	PUSH_ITEM_CONTEXT( visca_cmd_itp, icp );
}

Item_Context *pop_visca_cmd_context(SINGLE_QSP_ARG_DECL)
{
	return POP_ITEM_CONTEXT(visca_cmd_itp);
}

