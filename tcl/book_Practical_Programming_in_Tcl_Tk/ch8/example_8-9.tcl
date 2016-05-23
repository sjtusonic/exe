source ~/sonic/github/small_lib/include.tcl

proc RecordAppend {listName arrayName} {
   upvar $listName list
   lappend list $arrayName
}

proc RecordIterate {listName script} {
   upvar $listName list
   foreach arrayName $list {
      upvar #0 $arrayName data
      eval $script
   }
}

if {1} {
   set l1 {0 1}
   set l2 {0 2}
   set listName {l1 l2}
   set l3 {0 3}
   RecordAppend listName l3
   print_list_line_by_line listName
   print_list_line_by_line l1
   print_list_line_by_line l2
   puts "---"
   set scr {print_list_line_by_line arrayName}
   RecordIterate listName $scr
}
