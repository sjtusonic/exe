/* PowObjCmd 
 *
  * Tcl 8.x wrapper for the pow(x,y) function.
   */

#include <tcl.h>
#include <math.h>
int 
PowObjCmd(ClientData clientData, Tcl_Interp *interp,
		int objc, Tcl_Obj *CONST objv[])
{
	Tcl_Obj  *resultptr;
	double    x,y,result;
	int       error;

	if (objc != 3) {
		Tcl_WrongNumArgs(interp,2,objv,
				"Usage : pow x y");
		return TCL_ERROR;
	}
	error = Tcl_GetDoubleFromObj(interp, objv[1], &x);
	if (error != TCL_OK) return error;
	error = Tcl_GetDoubleFromObj(interp, objv[2], &y);
	if (error != TCL_OK) return error;

	result = pow(x,y);
	resultptr = Tcl_GetObjResult(interp);
	Tcl_SetDoubleObj(resultptr,result);
	return TCL_OK;
}

//To make this new command available to Tcl, you also need to write an initialization function such as follows:
int 
Example_Init(Tcl_Interp *interp) {
	Tcl_CreateObjCommand(interp, "pow", PowObjCmd,
			(ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
	return TCL_OK;
}
