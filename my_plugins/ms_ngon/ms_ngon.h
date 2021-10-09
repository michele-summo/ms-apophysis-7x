/*
    Apophysis Plugin: ms_ngon

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

int PluginVarCalc(Variation* vp)
{
	double s;
	double c;
	double sz = VAR(ms_ngon_size);
	double cnv = VAR(ms_ngon_convergence);
	double v = VAR(ms_ngon_vertex);
	int type = VAR(ms_ngon_type);
	if (sz != 0 && (cnv != 0 || v != 0)) {
		double n = VAR(ms_ngon_n);
		double ns;
		double nc;
		double d = sqrt(sqr(FTx)+sqr(FTy));
		double t = atan2(FTy, FTx);
		fsincos(t, &s, &c);
		double nt = M_2PI*floor(t*n*M_1_2PI + 0.5)/n;
		fsincos(nt, &ns, &nc);
		double rn = c*nc + s*ns;
		double sn = s/rn;
		double cn = c/rn;
		double drn = sqrt(sqr(sn)+sqr(cn));
		double denom = d/(sz*(cnv + drn*v)) + 1;
		switch(type) {
			case 1:
				FPx += VVAR * (sz*cn)/denom;
				FPy += VVAR * (sz*sn)/denom;
				break;
			case 2:
				FPx += VVAR * ((sz*cn) - (sz*cn)/denom);
				FPy += VVAR * ((sz*sn) - (sz*sn)/denom);
				break;
			default:
				FPx += VVAR * (FTx + (sz*cn)/denom);
				FPy += VVAR * (FTy + (sz*sn)/denom);
		}
	} else {
		FPx += VVAR * FTx;
		FPy += VVAR * FTy;
	}
	return 1;
}