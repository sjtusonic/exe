#!/usr/bin/tclsh
source /home/zzz/workspace/github/small_lib/include.tcl 

proc update {arrayName} {
	upvar #0 $arrayName cfg
	for {set i -1} {$i<100} {incr i} {
		if {$i==-1} {set i ""}
		foreach head {in out} {
			set cmd "if {\[info exist cfg($head\$i)\] && !\[info exist cfg(d$head\$i)\]} { set cfg(d$head\$i) \$cfg($head\$i) }"
			eval $cmd
			set cmd "if {\[info exist cfg(d$head\$i)\] && !\[info exist cfg($head\$i)\]} { set cfg($head\$i) \$cfg(d$head\$i) }"
			eval $cmd
		}

	}
}

# MAIN
set cfg(k) val
set cfg(k1) val1
set cfg(dk1) dval1
set cfg(in) val_in
set cfg(dout) val_dout
set cfg(out1) val_out1
set cfg(in0) val_in0
set cfg(din0) val_din0
set cfg(in1) val_in1
set cfg(din2) val_din2
set cfg(in10) val_in10
set cfg(in9) val_in9

show_array cfg
update cfg
show_array cfg
