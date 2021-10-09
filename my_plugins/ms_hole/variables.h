typedef struct
{
	double ms_hole_size;
	double ms_hole_convergence;
	int ms_hole_type;
    //double ms_hole_real;
	//double ms_hole_real_range;
	//double ms_hole_real_cycle;

	//int ms_hole_integer;
	//int ms_hole_integer_range;
	//int ms_hole_integer_nonzero;

} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("ms_hole");
APO_VARIABLES(
	VAR_REAL(ms_hole_size, /* default: */ 1.0),
	VAR_REAL(ms_hole_convergence, /* default: */ 1.0),
	VAR_INTEGER_RANGE(ms_hole_type, /* min: */ 0, /* max: */ 2, /* default: */ 0),
	//VAR_REAL(ms_hole_real, /* default: */ 0.0),
	//VAR_REAL_RANGE(ms_hole_real_range, /* min: */ -1.0, /* max: */ 1.0, /* default: */ 0.0),
	//VAR_REAL_CYCLE(ms_hole_real_cycle, /* min: */ -1.0, /* max: */ 1.0, /* default: */ 0.0),
	
	//VAR_INTEGER(ms_hole_integer, /* default: */ 0),
	//VAR_INTEGER_RANGE(ms_hole_integer_range, /* min: */ -1, /* max: */ 1, /* default: */ 0),
	//VAR_INTEGER_NONZERO(ms_hole_integer_nonzero, /* default: */ 1),
);
