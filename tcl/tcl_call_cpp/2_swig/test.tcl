#!/usr/bin/tclsh
#【test.tcl】： 
load ./libfract.so
#load ./fract.so 
#load ./fract.o 
#load ./fract_wrap.o 
foreach i {1 2 3 4 5} {
	puts "------------------------x"
		puts "i=$i"
		#puts "TCL:[myfract 2]"
		set tcl_flag  [catch {myfract $i} return_str]
		if {$tcl_flag != 0} {
			puts "OK:$return_str"
		} else {
			puts "Error:$return_str"
		}

}
