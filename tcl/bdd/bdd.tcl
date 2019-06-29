source ~/workspace/github/small_lib/include.tcl
print_list_line_by_line auto_path

package require Tcl 8.4
package require struct::graph 
package require struct::list 
package require struct::set 
package require struct::tree 

# PROC
proc show_truth_table {ref cfg} {
	set DBG_EN_BK ::DEBUG_EN ;
	set ::DEBUG_EN 0;
	puts "CALLING show_truth_table ";
	show_var ref;
	show_var cfg;
	set inputNum NA;
	regsub {LUT} $ref {} inputNum;
	show_var inputNum;
	set cfgBin [hex2bin $cfg];
	show_var cfgBin;
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
	show_var len;
	for {set cntr 0} {$cntr<$len} {incr cntr} {
#show_var cntr;
		set fmtstr "%0${inputNum}d";
		set tmp [format $fmtstr [dec2bin $cntr]];
#show_var tmp;
		foreach digit [split $tmp ""] {
			puts -nonewline "$digit\t";
#show_var digit
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
proc graph2dot {g} {
	set fp [open ${g}.dot w]
	puts $fp "digraph G \{"
	foreach _arc [$g arcs] {
		puts "$_arc : [$g arc source $_arc] -> [$g arc target $_arc]";
		set from     "[deleteColon [$g arc source $_arc]]";
		set to       "[deleteColon [$g arc target $_arc]]";
		if {[$g arc keyexists $_arc label]} {
			set label [$g arc get $_arc label]
		} else {
			set label NA
		}
		puts $fp     "$from -> $to \[label=$label\]"
	}
	puts $fp "\}"

		close $fp;
}

proc build_bdt {ref cfg} {
	puts "CALLING build_bdt";
	regsub {.*'h} $cfg {} cfgTail;
	set rootNode ::mytree_${ref}_$cfgTail;
	puts $rootNode;
	show_var rootNode;
	puts "Graph G exists $rootNode: [::G node exists $rootNode]";
	if {![::G node exists $rootNode]} {
		::G node insert $rootNode 
	}
#if {[::ROOT exists $rootNode]} {
#return;
#}
	set inputNum NA;
	regsub {LUT} $ref {} inputNum;
	show_var inputNum;
	set cfgBin [hex2bin $cfg];
	show_var cfgBin;
	set llCfgBin [split $cfgBin ""];
	show_var llCfgBin;
	set cntrPrint 0;
	set len [string len $cfgBin ];
	set isSOPForm 1;
	puts "::G node insert N0";
	::G node insert N0;
	puts "::G arc insert $rootNode N0 rootArc";
	::G arc insert $rootNode N0 rootArc;
	for {set cntr 0} {$cntr<$len} {incr cntr} {
		show_var cntr;
#if {![lindex $llCfgBin $cntr]} { continue; }
		set fmtstr "%0${inputNum}d";
		set tmp [format $fmtstr [dec2bin $cntr]]
		show_var tmp
		set curNodeId 0 
		foreach digit [split $tmp ""] {
			show_var digit;
			set newNodeId "$curNodeId$digit";
			if {![::G node exists N$newNodeId]} {
				puts "::G node insert N$newNodeId ";
				::G node insert N$newNodeId ;
#set newArcName $digit;
				set _curArc [::G arc insert N$curNodeId N$newNodeId ];
				::G arc set $_curArc label $digit
			}
#if {![::G arc exists $newArcName ]} {
#}
			set curNodeId $newNodeId;
		}
		incr cntrPrint;;
	}
#::ROOT insert root end $node;
#puts [::ROOT serialize]
	puts [::G serialize]
	showSerialize ::G
	graph2dot ::G
}

proc print_basic_expr_atom {ref cfg isSOPForm } {
	puts "CALLING print_basic_expr_atom $ref, $cfg, $isSOPForm";
	regsub {LUT} $ref {} inputNum;
	set cfgBin [hex2bin $cfg];
	set len [string len $cfgBin ];
	show_var cfgBin;
	set llCfgBin [split $cfgBin ""];
	set cntrPrint 0;
	for {set cntr 0} {$cntr<$len} {incr cntr} {
#show_var cntr;
#show_var llCfgBin 
		if {![lindex $llCfgBin $cntr]} { continue; }
		set fmtstr "%0${inputNum}d";
		set tmp [format $fmtstr [dec2bin $cntr]]
#show_var tmp
		set j 0
		set op1 [expr {($isSOPForm)?" | ":" &  "}];
		set op2 [expr {($isSOPForm)?" & ":" |  "}];
		if {$cntrPrint !=0 } {
#puts -nonewline " | " ;
			puts -nonewline $op1;
		}
		puts -nonewline " ( ";
		foreach digit [split $tmp ""] {
#show_var digit;
			if {$j!=0} {
#puts -nonewline " & ";
				puts -nonewline $op2;
			} 
			if {!$digit} {
				puts -nonewline "!";
			}
			puts -nonewline "I[expr $inputNum-$j-1]";
#show_var digit;
			incr j 1;
		}
		puts -nonewline " ) ";
		puts "";
		incr cntrPrint;;
	}
}
proc build_basic_expression {ref cfg} {
	puts "CALLING build_basic_expression ";
	regsub {.*'h} $cfg {} cfgTail;
	set node ::mytree_${ref}_$cfgTail;
	puts $node;
	show_var node;
	puts "exists $node : [::ROOT exists $node]";
	if {[::ROOT exists $node]} {
		return;
	}
	set inputNum NA;
	regsub {LUT} $ref {} inputNum;
	show_var inputNum;
	show_var cfg;
	set cfgBin [hex2bin $cfg];
	show_var cfgBin;
	set llCfgBin [split $cfgBin ""];
	show_var llCfgBin;

	set len [string len $cfgBin ];
	show_var len;
	set cntr_1 0;
	set cntr_0 0;
	for {set cntr 0} {$cntr<$len} {incr cntr} {
#show_var cntr;
		if {[lindex $llCfgBin $cntr]} {
			incr cntr_1;
		} else {
			incr cntr_0;

		} ;#if {[lindex $llCfgBin $cntr]} {} else 
	} ;#for {set cntr 0} {$cntr<$len} {incr cntr} 
#show_var cntr_0 ;
#show_var cntr_1 ;
	set flagSOP [expr ($cntr_1 <= $cntr_0)?1:0]
#show_var flagSOP;
	set ::DEBUG_EN 0 ;
	print_basic_expr_atom $ref $cfg $flagSOP;
	set ::DEBUG_EN 1
};# end of proc build_basic_expression {ref cfg} 

proc buildTree {level} {
	set nodeCnt [expr pow(2,$level)-1];
	show_var nodeCnt ;
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

set file_data_in ./input/dump_lut_init.rpt.short20 
::struct::tree ::ROOT
set fp [open $file_data_in r]
while {[gets $fp line]>=0} {
	show_var line;
	set ll [split $line];
	show_var ll;
	set cell [lindex $ll 0];
	set ref [lindex $ll 1];
	set cfg [lindex $ll 2];
	set filterName LUT3
		if {$ref ne $filterName } {
			puts  "NOT MATCH $filterName, continue!";
			continue;
		}
	show_var cell;
	show_truth_table $ref $cfg;
	build_basic_expression $ref $cfg;
	build_bdt $ref $cfg;
}
close $fp;
puts [::ROOT serialize ]
