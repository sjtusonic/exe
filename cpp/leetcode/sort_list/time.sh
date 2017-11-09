t1=`./get_date.tcl`
./a.out
t2=`./get_date.tcl`
echo "$t2-$t1"  | bc -l
