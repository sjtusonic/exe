source ~/workspace/github/small_lib/include.tcl
#print_list_line_by_line auto_path

package require Tcl 8.4
package require struct::graph 
package require struct::list 
package require struct::set 
package require struct::tree 

# PROC
proc show_truth_table {ref cfg} {
	set DBG_EN_BK ::DEBUG_EN ;
	set ::DEBUG_EN 0;
	puts "[string repeat --> [info level]]CALLING show_truth_table ";
	set inputNum NA;
	regsub {LUT} $ref {} inputNum;
	set cfgBin [hex2bin $cfg];
	set llCfgBin [split $cfgBin ""];
###
#print header
	puts "----------------------";
	for {set i 0} {$i<$inputNum } {incr i} {
		set j [expr $inputNum-$i-1];
		puts -nonewline "I$j";
		puts -nonewline "\t";
	}
	puts -nonewline "O";
	puts "";
	puts "----------------------";

#print contents
	set len [string len $cfgBin];
	for {set cntr 0} {$cntr<$len} {incr cntr} {
		set fmtstr "%0${inputNum}d";
		set tmp [format $fmtstr [dec2bin $cntr]];
		foreach digit [split $tmp ""] {
			puts -nonewline "$digit\t";
		}
		puts -nonewline [lindex $llCfgBin $cntr];
		puts "";
	}
	puts "-----------------------------";
	set ::DEBUG_EN $DBG_EN_BK;
}

proc showSerialize {g} {
	set cnt 0;
	foreach item [$g serialize] {
		if {$item eq ""} {
			set item "@"
		}
		puts "$cnt:\t$item"
			incr cnt;
	}
}

proc deleteColon {n} {
	regsub -all {:} $n {} ret;
	return $ret;
}

proc graph2dot {g {dotFileName ""}} {
	puts "CALL graph2dot $g $dotFileName ";
	if {$dotFileName eq ""} {
		set dotFileName ${g}.dot;
	} 
	show_var dotFileName 
		set fp [open $dotFileName w];
	puts $fp "digraph G \{";
	foreach _arc [$g arcs] {
		puts "$_arc : [$g arc source $_arc] -> [$g arc target $_arc]";
		set from     "[deleteColon [$g arc source $_arc]]";
		set to       "[deleteColon [$g arc target $_arc]]";
		if {[$g arc keyexists $_arc label]} {
			set label [$g arc get $_arc label];
		} else {
			set label NA;
		}
		puts $fp     "$from -> $to \[label=$label\]";
	}
	puts $fp "\}";

	close $fp;
}

proc insert_node_wrp {g node_name} {
	puts "$g node insert  $node_name";
	if {![$g node exists $node_name]} {
		puts "CREATE NEW NODE";
		set n [$g node insert $node_name;]
			return $n;
#set newArcName $digit;
	} else {
		return $node_name;
	}
}
proc insert_arc_wrp {g from to {arcName ""} {label ""}} {
	puts        "$g arc insert $from -> $to $arcName";
	if {![$g arc exists $arcName]} {
		puts "CREATE NEW ARC: $arcName";
		if {$arcName eq ""} {
			set _curArc [$g arc insert $from $to ];
		} else {
			set _curArc [$g arc insert $from $to $arcName];
		}
		if {$label ne ""} {
			puts "$g arc set $_curArc label $label";
			$g arc set $_curArc label $label;
		}
	}
}
proc build_bdd_var_tree {g ref cfg} {
	puts "[string repeat --> [info level]]CALLING [info level 0]";
	regsub {.*'h} $cfg {} cfgTail;
	set rootNode ::mytree_${ref}_$cfgTail;
	insert_node_wrp $g $rootNode;
	set inputNum NA;
	regsub {LUT} $ref {} inputNum;
	set cfgBin [hex2bin $cfg];
	set llCfgBin [split $cfgBin ""];
	set cntrPrint 0;
	set len [string len $cfgBin ];
	for {set cntr 0} {$cntr<[expr $len-0]} {incr cntr} {
		puts "FOR1 ---------------------------------------------";
#if {![lindex $llCfgBin $cntr]} { continue; }
		set fmtstr "%0${inputNum}d";
		set cntrBin [format $fmtstr [dec2bin $cntr]];
		set curNodeId "0";
		set llCntrBin [split $cntrBin ""]
#foreach digit [lrange [split $cntrBin ""] 0 end] 

			for {set ithPrime 0} {$ithPrime<[llength $llCntrBin]} {incr ithPrime} {
				puts "FOR2 ---------------------";
#set digit [lindex $llCntrBin [expr $ithPrime +1]]
				set digit [lindex $llCntrBin [expr $ithPrime ]];
#set iff [info frame [expr [info level ] +2]];
#puts "MARK:[dict get $iff file]:[dict get $iff line] proc=[dict get $iff proc]";
#puts "info level=[info level]";
				set len_curNodeId [string length $curNodeId ];
				puts "len_curNodeId=$len_curNodeId";

				insert_node_wrp ::G N$ithPrime ;
				set newNodeId "$curNodeId$digit";
				insert_node_wrp ::G N$newNodeId;

				set arcName "N$curNodeId-N$newNodeId";
				insert_arc_wrp ::G N$curNodeId N$newNodeId $arcName $digit;
				set curNodeId $newNodeId;
			}
		incr cntrPrint;
	}

	puts "[string repeat <-- [info level]]RETURN [info level 0]";
}

proc build_bdd_leaf {g ref cfg} {
	puts "[string repeat --> [info level]]CALLING [info level 0]";
	puts "last Prime, successors should be Nodes of 0/1";
#set newNodeId "$digit";
# set newNodeId "$curNodeId$digit";
	set cfgBin [hex2bin $cfg];
	set llCfgBin [split $cfgBin ""];
	print_list_line_by_line llCfgBin ;
# set newValueId [lindex $llCfgBin $cntr];
# insert_node_wrp ::G P$newValueId ;

# set arcName "N$curNodeId-P$newValueId";
# insert_arc_wrp ::G N$curNodeId P$newValueId $arcName $digit;

	puts "nodes: [$g nodes]";
	foreach n [$g nodes] {
		set degree [$g node degree -out $n ];
		if {$degree !=0} {continue;}
		set lookupValue [regsub {N\d} $n {}];
		if {![regexp {^\d+$} $lookupValue] } {continue;}
		puts "node:$n degree out: [$g node degree -out $n ]";
#set lookupValue "01101";
		show_var lookupValue ;
## bin2dec;

		set ind [bin2dec $lookupValue];
		set truthValue [lindex $llCfgBin $ind];
		show_var truthValue ;
		set newPNode [insert_node_wrp  $g P$truthValue ];
		show_var newPNode;
		insert_arc_wrp $g $n $newPNode "$n-$newPNode" "toLeaf";
	}
	puts "[string repeat <-- [info level]]RETURN [info level 0]";
}
proc show_all_arcs {g} {
	foreach arc [$g arcs] {
#show_var arc
		puts "arc=$arc:";
		foreach key [$g arc keys $arc] {
			puts "key=$key,[$g arc get $arc $key]";
		}
#puts "[$g arc set $arc label]"
#puts "[$g arc attr label]"
	}
}
proc del_arc_and_pred {g arc} {
# predNode --(arc)--> succNode
#     del     del
# 1.   --(lInArcs)->predNode --(arc)--> succNode
#      change lInArcs' target to succNode
# 2.   delete predNode and arc
	set predNode [$g arc source $arc];
	set succNode [$g arc target $arc];
	show_var predNode ;
#1:
	set lInArcs [$g arcs -in $predNode];
	puts "lInArcs=$lInArcs";
	foreach _inarc $lInArcs {
		$g arc move-target $_inarc $succNode ;
	}
	set lOutArcs [$g arcs -out $predNode];
	puts "lOutArcs=$lOutArcs";
#2:
	$g node delete $predNode ;

#$g swap $predNode $succNode ;
#$g node delete $predNode 
}
proc del_arc_and_succ {g arc} {
}
proc reduce_P_in_arcs {g} {
	foreach arc [$g arcs] {
		if {[$g arc exists $arc ] && 
			[$g arc keyexists $arc label] && [$g arc get $arc label] eq "toLeaf"} {
				puts "ZJC this is toLeaf! $arc"
#puts "ZJC";
# TODO delete this arc and its predecessor
					del_arc_and_pred $g $arc
			}
	}
}
proc reduce_bdd { g ref cfg} {
	puts "[string repeat --> [info level]]CALLING [info level 0]";
	show_all_arcs $g;
	reduce_P_in_arcs $g;
	puts "[string repeat <-- [info level]]RETURN [info level 0]";
}
proc build_bdd {ref cfg} {
#puts "[string repeat --> [info level]]CALLING build_bdd";
	puts "[string repeat --> [info level]]CALLING [info level 0]";
	regsub {.*'h} $cfg {} cfgTail;
############
# insert root node for the type_of_bdd{LUT}{cfg}
############
	set rootNode ::mytree_${ref}_$cfgTail;
	puts $rootNode;
	puts "Graph G exists $rootNode: [::G node exists $rootNode]";
	if {![::G node exists $rootNode]} {
		::G node insert $rootNode 
	}
#if {[::ROOT exists $rootNode]} {
#return;
#}
	set inputNum NA;
	regsub {LUT} $ref {} inputNum;
	set cfgBin [hex2bin $cfg];
	set llCfgBin [split $cfgBin ""];
	set cntrPrint 0;
	set len [string len $cfgBin ];
#puts "::G node insert N0";
#::G node insert N0;
#puts "::G arc insert $rootNode N0 rootArc";
#::G arc insert $rootNode N0 rootArc;
	build_bdd_var_tree ::G $ref $cfg;
	build_bdd_leaf     ::G $ref $cfg;

	graph2dot ::G G.before_reduce.dot;
	reduce_bdd ::G $ref $cfg;
	graph2dot ::G after_reduce_gdd.dot;
	reduce_bdd_rule1 ::G $ref $cfg;
	graph2dot ::G after_reduce_gdd.rule1.dot;
#::ROOT insert root end $node;
#puts [::ROOT serialize]
	puts [::G serialize];
	showSerialize ::G;
	#graph2dot ::G;
	puts "[string repeat <-- [info level]]RETURN build_bdd";
}

# OPT ORDER:
# 1. var reorder
# 2. decompose BDD
# 3. construct factoring trees
# 4. back to 1.

# parent-B=C-son  => parent-C-son
proc reduce_bdd_rule1 {g ref cfg} { 
	foreach n [$g nodes] {
		set degree [$g node degree -out $n ];
		if {$degree <2} {continue;}
		puts "node=$n;deg=$degree";
		set ll_target ""
		foreach _arc [$g arcs -out $n] {
			puts "arc=$_arc:target=[$g arc target $_arc ]"
			lappend ll_target      [$g arc target $_arc ]
		}
		if {[llength [lsort -u $ll_target]]==1} {
			puts "UNIQ TARGET"
			del_arc_and_pred $g [lindex [$g arcs -out $n] 0]
		}
	}
}

# A-B-{C D} E-B-{C D}
# => {A E}-B-{C D}
proc reduce_bdd_rule2 {} { }

proc print_basic_expr_atom {ref cfg isSOPForm } {
	puts "[string repeat --> [info level]]CALLING print_basic_expr_atom $ref, $cfg, $isSOPForm";
	regsub {LUT} $ref {} inputNum;
	set cfgBin [hex2bin $cfg];
	set len [string len $cfgBin ];
	set llCfgBin [split $cfgBin ""];
	set cntrPrint 0;
	for {set cntr 0} {$cntr<$len} {incr cntr} {
		if {![lindex $llCfgBin $cntr]} { continue; }
		set fmtstr "%0${inputNum}d";
		set tmp [format $fmtstr [dec2bin $cntr]]
			set j 0
			set op1 [expr {($isSOPForm)?" | ":" &  "}];
		set op2 [expr {($isSOPForm)?" & ":" |  "}];
		if {$cntrPrint !=0 } {
#puts -nonewline " | " ;
			puts -nonewline $op1;
		}
		puts -nonewline " ( ";
		foreach digit [split $tmp ""] {
			if {$j!=0} {
#puts -nonewline " & ";
				puts -nonewline $op2;
			} 
			if {!$digit} {
				puts -nonewline "!";
			}
			puts -nonewline "I[expr $inputNum-$j-1]";
			incr j 1;
		}
		puts -nonewline " ) ";
		puts "";
		incr cntrPrint;;
	}
	puts "[string repeat <-- [info level]]RETURN build_basic_expression ";
}
proc build_basic_expression {ref cfg} {
	puts "[string repeat --> [info level]]CALLING build_basic_expression ";
	regsub {.*'h} $cfg {} cfgTail;
	set node ::mytree_${ref}_$cfgTail;
	puts $node;
	puts "exists $node : [::ROOT exists $node]";
	if {[::ROOT exists $node]} {
		puts "[string repeat <-- [info level]]RETURN build_basic_expression ";
		return;
	}
	set inputNum NA;
	regsub {LUT} $ref {} inputNum;
	set cfgBin [hex2bin $cfg];
	set llCfgBin [split $cfgBin ""];

	set len [string len $cfgBin ];
	set cntr_1 0;
	set cntr_0 0;
	for {set cntr 0} {$cntr<$len} {incr cntr} {
		if {[lindex $llCfgBin $cntr]} {
			incr cntr_1;
		} else {
			incr cntr_0;

		} ;#if {[lindex $llCfgBin $cntr]} {} else 
	} ;#for {set cntr 0} {$cntr<$len} {incr cntr} 
	set flagSOP [expr ($cntr_1 <= $cntr_0)?1:0]
		set ::DEBUG_EN 0 ;
	print_basic_expr_atom $ref $cfg $flagSOP;
	set ::DEBUG_EN 1
		puts "[string repeat <-- [info level]]RETURN build_basic_expression ";
};# end of proc build_basic_expression {ref cfg} 

proc buildTree {level} {
	set nodeCnt [expr pow(2,$level)-1];
	for {set i 0} {$i<$nodeCnt } {incr i} {
		set lv [floor [expr log10($i+1)/log10(2)]];
		puts "i=$i,lv=$lv";

		set n [G node insert ];
		G node set $n name "I$lv";
		if {$lv!=0} {
#G arc insert 
		}
	}
}


# MAIN
::struct::graph G

if {0} {
	puts [buildTree 3]
		G node insert i1
		G node insert i2
		G node insert i3
		puts [G node insert ]
		G arc insert i1 i2
#G i1 insert i2
#G i1 insert i2
		puts [G serialize]
		showSerialize ::G
		foreach arc  [G arcs ] {
#puts "arc $arc"
			puts "[G arc source $arc] -> [G arc target $arc]"
		}

#puts [expr pow(10,0.301)]
}

puts "info vars:[info vars *]"

set t 1

set file_data_in ./input/dump_lut_init.rpt.short20 
::struct::tree ::ROOT
set fp [open $file_data_in r]
while {[gets $fp line]>=0} {
	set ll [split $line];
	set cell [lindex $ll 0];
	set ref [lindex $ll 1];
	set cfg [lindex $ll 2];
	set filterName LUT3;
	if {$ref ne $filterName } {
		puts  "NOT MATCH $filterName, continue!";
		continue;
	}
	show_truth_table $ref $cfg;
	build_basic_expression $ref $cfg;
	build_bdd $ref $cfg;
}
close $fp;
puts [::ROOT serialize ]
