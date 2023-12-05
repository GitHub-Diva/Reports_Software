
{REDUND_ERROR} FUNCTION_BLOCK FB_motor (*TODO: I don't know what this shit do)*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		u_in : {REDUND_UNREPLICABLE} REAL;
		dt : REAL;
	END_VAR
	VAR_OUTPUT
		W : {REDUND_UNREPLICABLE} REAL;
		phi : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR
		Tm : {REDUND_UNREPLICABLE} REAL;
		ke : {REDUND_UNREPLICABLE} REAL;
		Integrator : {REDUND_UNREPLICABLE} FB_Integrator;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_Integrator
	VAR_INPUT
		in : REAL;
		dt : REAL;
	END_VAR
	VAR_OUTPUT
		out : REAL;
	END_VAR
	VAR
		prev_value : REAL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_Controller
	VAR_INPUT
		e : {REDUND_UNREPLICABLE} REAL;
		dt : REAL;
	END_VAR
	VAR_OUTPUT
		u : {REDUND_UNREPLICABLE} REAL;
	END_VAR
	VAR
		last_sum : REAL;
		sum : REAL;
		a : REAL;
		k_p : REAL;
		k_i : REAL;
		max_abs_value : REAL;
		Integrator : FB_Integrator;
		iyOld : REAL;
	END_VAR
END_FUNCTION_BLOCK
