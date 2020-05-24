#!/usr/bin/tclsh
#【test.tcl】： 
#load ./libfract.so
#load ./fract.o 
load ./fract_wrap.o 
set tcl_flag  [catch {myfract 2} return_str]
if {$tcl_flag != 0} {
	puts "OK:$return_str"
} else {
	puts "Error:$return_str"
}

