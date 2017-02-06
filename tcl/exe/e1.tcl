#!/usr/bin/tclsh


proc get_tail {name {tail_count 0}} {
# >set name 0/1/2/3/4/5
 # >get_tail $name
 # 5
 # >get_tail $name 1
 # 4/5
	set start_str "end-$tail_count"
	return [join [lrange [split $name "/"] $start_str end] "/"]
}
proc get_head {name {head_count 0}} {
# >set name 0/1/2/3/4/5
# >get_head $name
# 0
# >get_head $name 1
# 0/1
puts "call get_head $name $head_count"
	return [join [lrange [split $name "/"] 0 $head_count] "/"]
}
proc cut_tail {name {tail_count 0}} {
	puts "call cut_tail $name $tail_count"
	return [get_head $name [expr [llength [split $name "/"]] -$tail_count -1]]
}
proc cut_head {name {head_count 0}} {
	return [get_tail $name [expr [llength [split $name "/"]] - $head_count  -1]]
}

#foreach i [list 1 2 3] {
#    puts $i
#}

#puts [get_tail  1/2/3/4/5/6 ]
puts [cut_tail  1/2/3/4/5/6 1]
puts [cut_tail  1/2/3/4 1]
puts [cut_tail  1/2/3 1]
