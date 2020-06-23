
#!/usr/bin/tclsh
#===============================================================================
# FILE               :  stepsource.tcl
# USAGE              :  ./stepsource.tcl <options>
# DESCRIPTION        :  ---
# REQUIREMENT        :  ---
# AUTHOR             :  Harris Zhu (harriszh), harriszh@cadence.com
# Created On         :  2018-06-30 21:16
# Last Modified      :  2018-06-30 21:16
# Update Count       :  1
# REVISION           :  ---
#===============================================================================
 namespace eval ::stepsource {
 
 variable VERSION "1.0"
 
 proc StepCommand {stepcommand} {
    switch -regexp -- $stepcommand {
        ^\[0-9\]+$ {
            set ::stepsource::currentBreakPoint $stepcommand
            return
        }
        ^b\ *-*[0-9?]*$ {
            if {$stepcommand == "b -"} {set ::stepsource::breakPoints {} ; return}
            set bOption [lindex $stepcommand 1]
            if {$bOption == "?"} {puts $::stepsource::outChannel "breakpoints: $::stepsource::breakPoints" ; return}
            if {![string first - $bOption]} {
                set eraseBreakPoint [lsearch $::stepsource::breakPoints [expr abs($bOption)]]
                if {$eraseBreakPoint > -1} {
                    set ::stepsource::breakPoints [lreplace $::stepsource::breakPoints $eraseBreakPoint $eraseBreakPoint]
                }
                puts $::stepsource::outChannel "breakpoints: $::stepsource::breakPoints"
                return
            }
            set ::stepsource::breakPoints "$::stepsource::breakPoints $bOption"
            set ::stepsource::breakPoints [lsort -unique $::stepsource::breakPoints]
            if {$bOption == {}} {set ::stepsource::currentBreakPoint $bOption}
            return
        }
        ^l\ *[0-9]*\ *[0-9]*$ {
            regexp {l ([0-9]+) *([0-9]*)} $stepcommand trash listStart listEnd
            if ![info exists listStart] {
                set listStart 1
                set listEnd $::stepsource::lineCount
            } else {
                if {(![string is integer -strict $listEnd]) || ($listEnd < $listStart)} {set listEnd $listStart}
            }
            for {set i $listStart} {$i <= $listEnd} {incr i} {
                if ![info exists ::stepsource::lineArray($i)] {return}
                puts -nonewline $::stepsource::outChannel "$::stepsource::lineArray($i)"
            }
            return
        }
    }
    switch -- $stepcommand {
        a {
            foreach var [uplevel 3 info vars] {
                if ![uplevel 3 array exists [list $var]] {continue}
                puts $::stepsource::outChannel "-----------------------------------"
                uplevel 3 parray [list $var]
            }
        }
        c {
            foreach var [lsort [uplevel 3 info vars]] {
                if {$var == "errorInfo"} {continue}
                if ![uplevel 3 info exists [list $var]] {continue}
                if [uplevel 3 array exists [list $var]] {continue}
                set changeIcon "=="
                catch {if {$::stepsource::varValues($var) != [uplevel 3 set [list $var]]} {set changeIcon "->"}}
                if {![info exists ::stepsource::varValues($var)]} {set changeIcon "->"}
                if {$changeIcon == "->"} {puts $::stepsource::outChannel [format "%-30s %s %s" $var $changeIcon "[uplevel 3 set [list $var]]"]}
                set varrayadd $var ; lappend varrayadd [uplevel 3 set [list $var]] ; array set ::stepsource::currentValues $varrayadd
            }
            set ::stepsource::varDefault c
        }
        e {
            set level [expr [info level] - 1]
            set ::stepsource::watchLevel $level
            if {$level <= $::stepsource::highestLevel} {unset ::stepsource::watchLevel}
        }
        g {
            foreach var [lsort [info globals]] {
                if [array exists ::$var] {puts $::stepsource::outChannel [format "%-27s %s" $var Array:] ; continue}
                set changeIcon "=="
                catch {if {$::stepsource::varValues($var) != [set $var]} {set changeIcon "->"}}
                puts $::stepsource::outChannel [format "%-30s %s %s" $var $changeIcon "[set ::$var]"]
                set varrayadd $var ; lappend varrayadd [set ::$var] ; array set ::stepsource::currentValues $varrayadd
            }
        }
        h {
            puts $::stepsource::outChannel {\
 
 <line#>    run until line number
 <return>    run next line
 a        list array values
 b        run until next breakpoint
 b ?        list breakpoints
 b <line#>    set breakpoint
 b -<line#>    unset breakpoint
 b -        unset all breakpoints
 c        list changed variable values
 e        run to end of current procedure
 g        list global variables
 h        help
 l        list all instrumented lines
 l <line#> [<line#>]     list line numbers
 v        list variable values
 x        abort execution
 <anything else>    execute as tcl command
                }
        }
        v {
            foreach var [lsort [uplevel 3 info vars]] {
                if ![uplevel 3 info exists [list $var]] {continue}
                if [uplevel 3 array exists [list $var]] {puts $::stepsource::outChannel [format "%-27s %s" $var Array:] ; continue}
                set changeIcon "=="
                catch {if {$::stepsource::varValues($var) != [uplevel 3 set [list $var]]} {set changeIcon "->"}}
                if {![info exists ::stepsource::varValues($var)]} {set changeIcon "->"}
                puts $::stepsource::outChannel [format "%-30s %s %s" $var $changeIcon "[uplevel 3 set [list $var]]"]
                set varrayadd $var ; lappend varrayadd [uplevel 3 set [list $var]] ; array set ::stepsource::currentValues $varrayadd
            }
            set ::stepsource::varDefault v
        }
        x {
            error "abort"
        }
        {} {
            set ::stepsource::currentBreakPoint 0
        }
        default {
            catch {uplevel 3 $stepcommand} result
            puts $::stepsource::outChannel $result
        }
    }
 }
 
 proc StepNumber {linenumber} {
    set level [info level]
    if ![info exists ::stepsource::highestLevel] {set ::stepsource::highestLevel $level}
    if {$level < $::stepsource::highestLevel} {set $::stepsource::highestLevel $level}
 
    if ![info exists ::stepsource::currentBreakPoint] {set ::stepsource::currentBreakPoint 0}
    if {$::stepsource::currentBreakPoint > $::stepsource::lineCount} {set ::stepsource::currentBreakPoint $::stepsource::lineCount}
    set returnOK 1
    catch {
        if {[info level] < $::stepsource::watchLevel} {
            unset ::stepsource::watchLevel
            set returnOK 0
        } else {
            set ::stepsource::currentBreakPoint {}
        }
    }
    if {$::stepsource::currentBreakPoint == 0} {set returnOK 0}
    if {$linenumber == $::stepsource::currentBreakPoint} {unset ::stepsource::currentBreakPoint ; set returnOK 0}
    if {[lsearch -exact $::stepsource::breakPoints $linenumber] > -1} {set returnOK 0}
 
    if $returnOK {return}
 
    catch {
        set currentProcedure [lindex [info level -2] 0]
        if {[uplevel 2 info procs $currentProcedure] == {}} {set currentProcedure {}}
    }
    if ![info exists ::stepsource::lastProcedure] {set ::stepsource::lastProcedure {}}
    if ![info exists currentProcedure] {set currentProcedure {}}
    if {($level != $::stepsource::highestLevel) && ($::stepsource::lastProcedure != $currentProcedure)} {puts $::stepsource::outChannel "||||current procedure: $currentProcedure"}
    set ::stepsource::lastProcedure $currentProcedure
 
    set stepCommand $::stepsource::varDefault
    StepCommand $stepCommand
    while {$stepCommand != {}} {
        puts $::stepsource::outChannel "\n-----------------------------------"
        puts $::stepsource::outChannel $::stepsource::lineArray($linenumber)\n
        puts -nonewline $::stepsource::outChannel >
        set stepCommand [gets $::stepsource::inChannel]
        StepCommand $stepCommand
        if {([string is integer -strict $stepCommand]) || ($stepCommand == "b") || ($stepCommand == {}) || ($stepCommand == "e")} {
            catch {array set ::stepsource::varValues [array get ::stepsource::currentValues]}
            catch {array unset ::stepsource::currentValues}
            break
        }
    }
 }
 
 proc StepSource {filename} {
    namespace eval ::stepsource {}
    set ::stepsource::filename $filename
    namespace eval ::stepsource {
        if {[info procs original_unknown] == {}} {
            rename ::unknown original_unknown
            proc ::unknown {args} {
                if [string is integer -strict $args] {
                    ::stepsource::StepNumber $args
                } else {
                    set ::stepsource::unk_args $args
                    uplevel 1 ::stepsource::original_unknown $::stepsource::unk_args
                }
            }
        }
        if ![info exists inChannel] {set inChannel stdin}
        if ![info exists outChannel] {set outChannel stdout}
        if ![info exists breakPoints] {set breakPoints {}}
        if ![info exists varDefault] {set varDefault v}
        if ![info exists sourcedFiles] {set sourcedFiles {}}
        if {[lsearch -exact $sourcedFiles $filename] < 0} {lappend sourcedFiles $filename}
        if ![info exists ::stepsource::sourceProcs] {set ::stepsource::sourceProcs {}}
        set mtime [file mtime $filename]
        set oldMtime 0
        catch {set oldMtime $mtimes($filename)}
        array unset lineArray
        set lineCount 1
        foreach sF $sourcedFiles {
            set $sF {}
            set f [open $sF r]
            set noNumberLine {}
            while {![eof $f]} {
                set line [gets $f]
                set firstWord [string trim [string range [string trim $line] 0 [expr [string wordend [string trim $line] 0] - 1]]]
                set secondWord [string trim [string range [string trim $line] [string length $firstWord] [string wordend [string trim $line] [expr [string length $firstWord] + 1]]]]
                if ![regexp {(::[^ ]+)(\ |$)} $line trash firstNameSpace] {set firstNameSpace {}}
                if {$firstWord == ":"} {set firstWord $firstNameSpace}
                if {[string index $secondWord 0] == ":"} {set secondWord $firstNameSpace}
                if {$firstWord == "proc"} {lappend ::stepsource::sourceProcs $secondWord}
                if {([info commands $firstWord] != {}) || ([lsearch -exact $::stepsource::sourceProcs $firstWord] > -1)} {
                    set $sF "[set $sF]$noNumberLine[set lineCount]\;\t$line\n"
                    set arrayadd $lineCount ; lappend arrayadd $noNumberLine$lineCount\;\t$line\n ; array set lineArray $arrayadd
                    set noNumberLine {}
                    incr lineCount
                } elseif {($firstWord == "\{") && (([info commands $secondWord] != {}) || ([lsearch -exact $::stepsource::sourceProcs $secondWord] > -1))} {
                    set arrayadd $lineCount ; lappend arrayadd $noNumberLine$lineCount\;\t$line\n ; array set lineArray $arrayadd
                    regsub {\{} $line "\{$lineCount\;" line
                    set $sF "[set $sF]$noNumberLine\t$line\n"
                    set noNumberLine {}
                    incr lineCount
                } else {
                    set noNumberLine $noNumberLine\t$line\n
                }
            }
            close $f
            if {$noNumberLine != {}} {set $sF "[set $sF]$noNumberLine"}
        }
    }
    set ::stepsource::sourceProcs {}
    uplevel 1 eval \$\{::stepsource::$::stepsource::filename\}
 }
 }
 # end namespace eval ::stepsource
 proc ::ss {args} {
    catch {unset ::stepsource::watchLevel}
    catch {unset ::stepsource::currentBreakPoint}
    catch {array unset ::stepsource::varValues}
    uplevel 1 $args
 }
 package provide stepsource $::stepsource::VERSION

