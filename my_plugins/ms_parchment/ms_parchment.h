/*
    Apophysis Plugin: ms_parchment

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

int PluginVarPrepare(Variation* vp)
{
    return 1;
}

double pfmod(double a, double b) {
	double r = fmod(a, b);
	if (r < 0) {
		return b + r;
	} else {
		return r;
	}
}

int PluginVarCalc(Variation* vp)
{	
	double n = VAR(ms_parchment_n);
	double w = VAR(ms_parchment_weight);
	double t = atan2(FTy, FTx);
	double nt = M_2PI*floor(t*n*M_1_2PI + 0.5)/n;
	
	double wa;
	double wb;
	double dr = VAR(ms_parchment_dec_radius);
	if (dr != 0) {
		double dw = VAR(ms_parchment_dec_weight);
		double d = sqrt(sqr(FTx)+sqr(FTy));
		if (d < dr) {
			wa = pow(d/dr, dw);
			wb = pow((dr - d)/dr, dw);
			w = (wa * w + wb)/(wa + wb);
		}
	}
	
	double ntp;
	double nta;
	if (pfmod(t+M_PI-nt, M_2PI) < M_PI) {
		//t < nt
		ntp = nt - M_2PI/n;
		wa = pow(t - ntp, w);
		wb = pow(nt - t, w);
		nta = (wb*ntp + wa*nt)/(wa + wb);
	} else {
		ntp = nt + M_2PI/n;
		wa = pow(t - nt, w);
		wb = pow(ntp - t, w);
		nta = (wb*nt + wa*ntp)/(wa + wb);
	}
	double tdelta = nta - t;
	double s;
	double c;
	fsincos(tdelta, &s, &c);
	FPx += VVAR * (FTx*c - FTy*s);
	FPy += VVAR * (FTx*s + FTy*c);
    return 1;
}