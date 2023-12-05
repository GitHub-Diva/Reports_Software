
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_Controller(struct FB_Controller* inst)
{
	REAL a = inst->e * inst->k_p;
	REAL b = inst->e * inst->k_i;
	
//	a = a > inst->max_abs_value ? inst->max_abs_value:a;
//	a = a < inst->max_abs_value ? - inst->max_abs_value : a;

	// Блок ограничения напряжения
	if ( abs(a) < inst->max_abs_value )
	{
		a = a;
	}
	else
	{
		if (a<0)
		{
			a = (-1)* inst->max_abs_value;
		}
		else
		{
			a = inst->max_abs_value;
		}
	}

	inst->Integrator.in = b + inst->iyOld;
	FB_Integrator(&inst->Integrator);
	
	REAL sum = a + inst->Integrator.out;
	
	inst->u = sum;
	
	inst->u = inst->u > inst->max_abs_value ? inst->max_abs_value : inst->u;
	inst->u = inst->u < - inst->max_abs_value ? -inst->max_abs_value: inst->u;
	
	inst->iyOld = inst->u - sum;
	
}
