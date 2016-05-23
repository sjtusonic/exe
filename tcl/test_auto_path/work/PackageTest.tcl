#!/usr/local/ActiveTcl/bin/tclsh
set auto_path [lappend auto_path [file dirname [info script]]]
package provide PackageTest 1.0
proc PackageTest_fun {} {
   global auto_path
   puts "============================"
   puts "$auto_path"
   puts "============================"
}
