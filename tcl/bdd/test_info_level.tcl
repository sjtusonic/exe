source ~/workspace/github/small_lib/include.tcl
proc l1 {} {
	puts "[string repeat --> [info level]]CALLING [info level 0]";
	puts "info level=[info level]";
	puts "info frame=[info frame]";
	set cntr [info level] ;puts "info frame $cntr =[info frame $cntr]";
	set il [info level];show_var il
#set cntr 1 ;puts "info frame $cntr =[info frame $cntr]";
#set cntr 2 ;puts "info frame $cntr =[info frame $cntr]";
#set cntr 3 ;puts "info frame $cntr =[info frame $cntr]";
		l2;
	l2;
	l21;
	puts "[string repeat <-- [info level]]RET [info level 0]";
}
proc l2 {} {
	puts "[string repeat --> [info level]]CALLING [info level 0]";
	puts "info level=[info level]";
	puts "info frame=[info frame]";
	set cntr [info level] ;puts "info frame $cntr =[info frame $cntr]";
	set il [info level];show_var il
		puts "[string repeat <-- [info level]]RET [info level 0]";

}
proc l21 {} {
	puts "[string repeat --> [info level]]CALLING [info level 0]";
	puts "info level=[info level]";
	puts "info frame=[info frame]";
	set cntr [info level] ;puts "info frame $cntr =[info frame $cntr]";
	set il [info level];show_var il
		l31;

	puts "[string repeat <-- [info level]]RET [info level 0]";
}
proc l31 {} {
	puts "[string repeat --> [info level]]CALLING [info level 0]";
	puts "info level=[info level]";
	puts "info frame=[info frame]";
	set cntr [info level] ;puts "info frame $cntr =[info frame $cntr]";
	set il [info level];show_var il

		puts "[string repeat <-- [info level]]RET [info level 0]";
}

# main
puts "info level=[info level]";
puts "info frame=[info frame]";
set cntr [info level] ;puts "info frame $cntr =[info frame $cntr]";
#set cntr 0 ;puts "info frame $cntr =[info frame $cntr]"
#set cntr 1 ;puts "info frame $cntr =[info frame $cntr]"
#set cntr 2 ;puts "info frame $cntr =[info frame $cntr]"
#set cntr 3 ;puts "info frame $cntr =[info frame $cntr]"


set t 1
show_var t;
if {1} {
	show_var t;
	if {1} {
 l1
		show_var t;
	}
}
