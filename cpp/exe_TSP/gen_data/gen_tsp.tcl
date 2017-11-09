
set CNT_NODE 100
set i $CNT_NODE
while {$i>0} {

    #set x [expr 1.0*int(rand()*100)/100 ]
    #set y [expr 1.0*int(rand()*100)/100 ]
    set x [expr int(rand()*100) ]
    set y [expr int(rand()*100) ]
    set ll [list $x $y]
    puts $ll
    incr i -1
}

