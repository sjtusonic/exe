#!/bin/bash
grep  "^proc " bdd.tcl | awk '{print $2}' > proc.list.rpt
grep -f proc.list.rpt bdd.tcl -n > call.tree.rpt

rm *.dot *.svg
/usr/bin/tclsh bdd.tcl  2>&1 | tee -i log

for f in `ls *.dot`
do
	echo "f=$f"
	dot -Tsvg -o $f.svg $f
done
