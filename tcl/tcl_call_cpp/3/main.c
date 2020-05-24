#include <tcl.h>
#include <stdio.h>
int Tcl_AppInit(Tcl_Interp *interp);
int main(int argc, char *argv[]) {
	Tcl_Main(argc, argv, Tcl_AppInit);
}
int Tcl_AppInit(Tcl_Interp *interp) {
	/* Initialize Tcl */
	if (Tcl_Init(interp) == TCL_ERROR) {
		return TCL_ERROR;
	}
	/* Initialize our extension */
	if (Fract_Init(interp) == TCL_ERROR) {
		return TCL_ERROR;
	}
	return TCL_OK;
}
