/* 
 * random.c
 */

# include <tcl.h>

int RandomCmd(ClientData clientData,
		Tcl_Interp *interp,
		int argc, char * argv[]);
int RandomObjCmd(ClientData clientData,
		Tcl_Interp* interp,
		int objc, Tcl_Obj *CONST objv[]);

int Random_Init(Tcl_Interp * interp){
	if(Tcl_InitStubs(interp, "8.1",0)==NULL){
		return TCL_ERROR;
	}

	Tcl_CreateCommand(interp,
			"random",
			RandomCmd,
			/*
			(ClientData)NULL,
			(const 
			 Tcl_CmdDeleteProc*)
			NULL
			*/
			NULL,
			NULL
			);

	Tcl_CreateObjCommand(interp, "orandom", RandomObjCmd,
			(ClientData)NULL,
			(Tcl_CmdDeleteProc*)NULL);

	Tcl_PkgProvide(interp,
			"random", "1.1");
	return TCL_OK;
}

int RandomCmd(ClientData clientData,
		Tcl_Interp* interp,
		int argc,
		char* argv[])
{
	int rand,error;
	int range=0;
	if(argc>2){
		interp->result="Usage: random ?range?";
		return TCL_ERROR;

	}
	if(argc==2){
		if(Tcl_GetInt(interp,argv[1],&range)!=TCL_OK) {
			return TCL_ERROR;
		}
	}
	rand=random();
	if(range!=0){
		rand=rand%range;
	}
	sprintf(interp->result, "%d", rand);
	return TCL_OK;
}
