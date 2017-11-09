cp ../out.nearest.dat ./out_data.dat
#/usr/bin/tclsh gen_tsp.tcl > data.dat
gnuplot r.scr
evince out_data.ps


