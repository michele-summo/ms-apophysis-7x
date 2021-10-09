typedef struct
{
	double ms_ngon_n;
	double ms_ngon_size;
	double ms_ngon_convergence;
	double ms_ngon_vertex;
	int ms_ngon_type;
	
    //double ms_ngon_real;
	//double ms_ngon_real_range;
	//double ms_ngon_real_cycle;

	//int ms_ngon_integer;
	//int ms_ngon_integer_range;
	//int ms_ngon_integer_nonzero;

} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("ms_ngon");
APO_VARIABLES(
	VAR_REAL(ms_ngon_n, /* default: */ 5.0),
	VAR_REAL(ms_ngon_size, /* default: */ 1.0),
	VAR_REAL(ms_ngon_convergence, /* default: */ 1.0),
	VAR_REAL(ms_ngon_vertex, /* default: */ 0.0),
	VAR_INTEGER_RANGE(ms_ngon_type, /* min: */ 0, /* max: */ 2, /* default: */ 0),
	//VAR_REAL(ms_ngon_real, /* default: */ 0.0),
	//VAR_REAL_RANGE(ms_ngon_real_range, /* min: */ -1.0, /* max: */ 1.0, /* default: */ 0.0),
	//VAR_REAL_CYCLE(ms_ngon_real_cycle, /* min: */ -1.0, /* max: */ 1.0, /* default: */ 0.0),
	
	//VAR_INTEGER(ms_ngon_integer, /* default: */ 0),
	//VAR_INTEGER_RANGE(ms_ngon_integer_range, /* min: */ -1, /* max: */ 1, /* default: */ 0),
	//VAR_INTEGER_NONZERO(ms_ngon_integer_nonzero, /* default: */ 1),
	
);
