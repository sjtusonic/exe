#dot -Tsvg t.dot -o t.svg

for i in `ls *dot`
do
	echo $i
	to=$i.svg
	dot -Tsvg $i -o $to
done
