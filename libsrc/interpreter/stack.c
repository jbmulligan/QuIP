
#include "quip_config.h"
#include "quip_prot.h"
#include "stack.h"
#include "node.h"
#include <stdio.h>

// a stack is just a list???

void push_item( Stack *stkp, void *ip )
{
	Node *np;

	np = mk_node(ip);
	addHead(stkp,np);
}

void *pop_item( Stack *stkp )
{
	Node *np;
	void *ip;

	np = remHead(stkp);
	assert(np!=NULL);
	ip = NODE_DATA(np);
	rls_node(np);
	return ip;
}

int stack_size( Stack *stkp )
{
	return eltcount(stkp);
}

