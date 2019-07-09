#use Config;
#'urllist' => [q[http://mirrors.163.com/cpan/]],
#$Config{'urllist'} = q[http://mirrors.163.com/cpan/];

 
 use Graph;
 use Graph::Writer::Dot;
 $indotfname=shift;
 print "arg=$indotfname\n";


#FUNCTIONS
 sub graph2Dot {
	 my $g=shift;
	 my $fname=shift;
	 print "\n";
	 print "g=$g\n";
	 print "fname=$fname\n";

	 my @E = $g->edges;
	 open (FH_OUT, "> $fname");
	 my @V = $g->vertices;
	 print "\n";
#print "VERTICES:\n";
	 print FH_OUT  "digraph G {\n";
	 foreach my $i (@V) {
#print "$i\n";
		 my @n = $g->successors($i);
		 print "$i has NEIGHBOUR: #n=$#n\n";
		 if ($#n<0) {next;}
		 foreach my $j (@n) {
			 if ($j eq "") {next;}
			 print "$i -> $j\n";
#foreach (keys $edge) {print "$_ -> $edge[$_]\n";}
			 print FH_OUT  "$i -> $j\n";
		 }
	 }
	 print FH_OUT  "}\n";
	 close $FH_OUT;
 }

sub dot2graph {
# A directed graph.
	my $fn=shift;
	print "CALL dot2graph $fn\n";
	my $g = Graph->new;             
	open (FH_IN, $fn);
	while(<FH_IN>){
		if(/->/) {
			s/\[.*\]//g;
#my @ll=split($_,"->");

			print "$_\n";
			my $from=$_;
			my $to=$_;
			$from=~s/->.*//;
			$from=~s/ //g;
			$from=~s/\n//g;
			$to=~s/.*->//;
			$to=~s/ //g;
			$to=~s/\n//g;

			print "from:$from\n";
			print "to:$to\n";

			$g->add_edge($from,$to);
		}
	}
	close $FH_IN ;
	return $g;
}
# MAIN
my $g=&dot2graph($indotfname);

##########################
# show directly:
##########################
print "The graph is $g\n";

print "SHOW:\n";
##########################
# show vertices list:
##########################
my @V = $g->vertices;
print "\n";
print "VERTICES:\n";
print "$#V\n";
foreach my $i (@V) {
	print "$i\n";
}
##########################
# show successors 
##########################
my @n = $g->successors("N00");
print "NEIGHBOUR: #n=$#n\n";
foreach my $i (@n) {
	print "$i\n";
}

##########################
# show sptg, (span tree?)
##########################
my $sptg = $g->SPT_Dijkstra("N01");
print "SPTG: $sptg\n";

# self defined function
my $sptg_file_name=sptg.$indotfname;
my $writer=Graph::Writer::Dot->new();
#&graph2Dot($sptg,"./output/$sptg_file_name ");
# use lib:
$writer->write_graph($g,"./output/$sptg_file_name ");

#my $sptg = $g->SPT_Dijkstra("N01");
#print "$sptg\n";



##########################
# get path
##########################
print "SSST:\n";
@path = $g->SP_Dijkstra("N01","N0100");

print "#path=$#path\n";
foreach my $i (@path) {
	print "$i\n";
}
