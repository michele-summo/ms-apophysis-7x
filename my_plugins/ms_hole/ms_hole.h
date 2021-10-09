/*
    Apophysis Plugin: ms_hole

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
	double sz = VAR(ms_hole_size);
	double cnv = VAR(ms_hole_convergence);
	int type = VAR(ms_hole_type);
	if (sz != 0 && cnv != 0) {
		double d = sqrt(sqr(FTx)+sqr(FTy));
		double t = atan2(FTy, FTx);
		fsincos(t, &s, &c);
		switch(type) {
			case 1:
				FPx += VVAR * (sz*c)/(d/(sz*cnv) + 1);
				FPy += VVAR * (sz*s)/(d/(sz*cnv) + 1);
				break;
			case 2:
				FPx += VVAR * ((sz*c) - (sz*c)/(d/(sz*cnv) + 1));
				FPy += VVAR * ((sz*s) - (sz*s)/(d/(sz*cnv) + 1));
				break;
			default:
				FPx += VVAR * (FTx + (sz*c)/(d/(sz*cnv) + 1));
				FPy += VVAR * (FTy + (sz*s)/(d/(sz*cnv) + 1));
		}
	} else {
		FPx += VVAR * FTx;
		FPy += VVAR * FTy;
	}
	return 1;
}