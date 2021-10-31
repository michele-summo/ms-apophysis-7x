typedef struct
{
	double ms_parchment_n;
	double ms_parchment_weight;
	double ms_parchment_dec_weight;
	double ms_parchment_dec_radius;
    //double ms_parchment_real;
	//double ms_parchment_real_range;
	//double ms_parchment_real_cycle;

	//int ms_parchment_integer;
	//int ms_parchment_integer_range;
	//int ms_parchment_integer_nonzero;

} Variables;

#ifdef _APOMSVC
	#include "apoplugin_msvc.h"
#else
	#include "apoplugin.h"
#endif

APO_PLUGIN("ms_parchment");
APO_VARIABLES(
	VAR_REAL(ms_parchment_n, /* default: */ 3),
	VAR_REAL(ms_parchment_weight, /* default: */ 2),
	VAR_REAL(ms_parchment_dec_weight, /* default: */ 1),
	VAR_REAL(ms_parchment_dec_radius, /* default: */ 0),
	//VAR_REAL(ms_parchment_real, /* default: */ 0.0),
	//VAR_REAL_RANGE(ms_parchment_real_range, /* min: */ -1.0, /* max: */ 1.0, /* default: */ 0.0),
	//VAR_REAL_CYCLE(ms_parchment_real_cycle, /* min: */ -1.0, /* max: */ 1.0, /* default: */ 0.0),
	
	//VAR_INTEGER(ms_parchment_integer, /* default: */ 0),
	//VAR_INTEGER_RANGE(ms_parchment_integer_range, /* min: */ -1, /* max: */ 1, /* default: */ 0),
	//VAR_INTEGER_NONZERO(ms_parchment_integer_nonzero, /* default: */ 1),
);
