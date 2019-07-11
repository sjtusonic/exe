#!/bin/bash
/usr/bin/tclsh bdd.tcl  2>&1 | tee -i log

for f in `ls *.dot`
do
	echo "f=$f"
	dot -Tsvg -o $f.svg $f
done
