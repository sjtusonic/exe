source ~/sonic/github/small_lib/include.tcl
proc lassign {valueList args} {
   if {[llength $args]==0} {
      error "wrong # args: lassign list varname ?varname--?"
   }
   if {[llength $valueList]==0} {
      set valueList [list {}]
   }
   uplevel 1 [list foreach $args $valueList {break}] ;# tricky, use foreach {a b c} {1 2 3 4 5} to batch-assign
   return [lrange $valueList [llength $args] end]
}

if {0} { ;# test
   set ll {1 2 3 4 5}
   puts "list left: [lassign $ll a b c]"
   show_var {a b c}
}
