#!/bin/bash
echo "----------------------------"
echo "START EXE dot2path run.sh "
echo "----------------------------"
ls log && rm -rf log
ls output && rm -rf output

ls log || mkdir log
ls output || mkdir output

for d in `ls *.dot`
do
	log=./log/dot2path.$d.log
echo "----------------------------"
	echo "DOT TO PATH"
	echo "perl dot2path.pl  $d > $log ..."
echo "----------------------------"
	perl dot2path.pl  $d > $log
done

for dot in `ls ./output/*.dot`
do
echo "----------------------------"
	echo "OUTPUT PATH DOT TO SVG"
	echo "dot -Tsvg -o $dot.svg $dot ..."
echo "----------------------------"
	dot -Tsvg -o $dot.svg $dot
done
