
source ~/workspace/github/small_lib/include.tcl
print_list_line_by_line auto_path

package require Tcl 8.4
package require struct::graph 
package require struct::list 
package require struct::set 

proc buildTree {level} {
	set nodeCnt [expr pow(2,$level)-1]
	show_var nodeCnt 
	for {set i 0} {$i<$nodeCnt } {incr i} {
		set lv [floor [expr log10($i+1)/log10(2)]]
		puts "i=$i,lv=$lv"

		set n [G node insert ]
		G node set $n name "I$lv"
		if {$lv!=0} {
			G arc insert 
		}
	}
}
::struct::graph G

puts [buildTree 3]
G node insert i1
G node insert i2
G node insert i3
puts [G node insert ]
G arc insert i1 i2
#G i1 insert i2
#G i1 insert i2
puts [G serialize]
foreach arc  [G arcs ] {
	#puts "arc $arc"
	puts "[G arc source $arc] -> [G arc target $arc]"
}

puts [expr pow(10,0.301)]
