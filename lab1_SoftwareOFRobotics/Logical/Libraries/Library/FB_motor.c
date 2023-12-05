
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: I don't know what this shit do) */
void FB_motor(struct FB_motor* inst)
{
	REAL a = inst->u_in / inst->ke - inst->W;
	REAL b = a / inst->Tm;
	
	inst->Integrator.in = b;
	FB_Integrator(&inst->Integrator);
	inst->W = inst->Integrator.out;
/*	
	inst->Integrator.in = inst->W;
	FB_Integrator(&inst->Integrator);
	inst->phi = inst->Integrator.out;
*/
}

