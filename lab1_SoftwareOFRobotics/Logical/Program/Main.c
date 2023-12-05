
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	fb_motor1.ke = 0.15;
	fb_motor1.Tm = 0.3;
	fb_motor1.u_in = 0;
	fb_motor1.dt = 0.001;
	
	fb_motor2.ke = 0.15;
	fb_motor2.Tm = 0.3;
	fb_motor2.u_in = 0;
	fb_motor2.dt = 0.001;
	
	fb_controller.k_p = 0.45;
	fb_controller.k_i = 1.5;
	fb_controller.max_abs_value = 25.0;
	fb_controller.dt = 0.001;
	
	speed = 0;
	speed2 = 0;
	counter = 0;
	enable = 1;
}

void _CYCLIC ProgramCyclic(void)
{
	if (enable)
	{
		if (counter == 300)
		{
			speed = 0;
			speed2 = 0;
			counter = 0;
		}
		else if (counter == 100){
			speed = 50;
			speed2 = 50;
		}
		fb_controller.e = speed - fb_motor1.W;
		FB_Controller(&fb_controller);
		
		fb_motor1.u_in = fb_controller.u;
		FB_motor(&fb_motor1);
		
		fb_motor2.u_in = speed2 * fb_motor2.ke;
		FB_motor(&fb_motor2);
		
		counter++;
	}
}

void _EXIT ProgramExit(void)
{

}

