// 【fract.c】：
#include "tcl.h"
int Tcl_myfract(ClientData notUsed, Tcl_Interp *interp, int argc, char **argv)
{
	int i, j;
	double res=1.0;
	char re[30];
	if (argc > 2)
	{
		Tcl_SetResult(interp, "wrong args: should be myfract", TCL_VOLATILE);
		return TCL_ERROR;
	}
	if (Tcl_GetInt(interp, argv[1], &i) != TCL_OK)
	{
		return TCL_ERROR;
	}
	for (j=1;j<=i;j++)
		res *= j;
	sprintf(re,"%le",res);
	Tcl_SetResult(interp, re, TCL_VOLATILE);
	return TCL_OK;
}

int Fract_Init(Tcl_Interp *Interp) {
	Tcl_CreateCommand (Interp, "myfract", (Tcl_CmdProc *)Tcl_myfract, (ClientData)0, 0);
	return TCL_OK;
}

