/* Automation Studio generated header file */
/* Do not edit ! */
/* Library  */

#ifndef _LIBRARY_
#define _LIBRARY_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define d_t 0.01f
#else
 _GLOBAL_CONST float d_t;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct FB_Integrator
{
	/* VAR_INPUT (analog) */
	float in;
	float dt;
	/* VAR_OUTPUT (analog) */
	float out;
	/* VAR (analog) */
	float prev_value;
} FB_Integrator_typ;

typedef struct FB_motor
{
	/* VAR_INPUT (analog) */
	float u_in;
	float dt;
	/* VAR_OUTPUT (analog) */
	float W;
	float phi;
	/* VAR (analog) */
	float Tm;
	float ke;
	struct FB_Integrator Integrator;
} FB_motor_typ;

typedef struct FB_Controller
{
	/* VAR_INPUT (analog) */
	float e;
	float dt;
	/* VAR_OUTPUT (analog) */
	float u;
	/* VAR (analog) */
	float last_sum;
	float sum;
	float a;
	float k_p;
	float k_i;
	float max_abs_value;
	struct FB_Integrator Integrator;
	float iyOld;
} FB_Controller_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void FB_motor(struct FB_motor* inst);
_BUR_PUBLIC void FB_Integrator(struct FB_Integrator* inst);
_BUR_PUBLIC void FB_Controller(struct FB_Controller* inst);


#ifdef __cplusplus
};
#endif
#endif /* _LIBRARY_ */

