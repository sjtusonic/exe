#############
# HEAD
#############
source /home/zz/workspace/github/small_lib/include.tcl
#lappend auto_path /usr/share/tcltk/tcllib1.15
#lappend auto_path /usr/share/tcltk/tcllib1.15/struct
lappend auto_path /home/zz/workspace/tcllib-trunk/modules
puts "-----------------------------------------------"
puts "auto_path=$auto_path"
#package require Tcl 
#package require Tcllib 
package require struct::matrix 



#############
# MAIN
#############
::struct::matrix mymat
mymat add columns 2
mymat add rows 2
#mymat set column 1 {11 12}
#mymat set column 2 {21 22}
puts "mymat = [mymat serialize]"
puts "format 2string = [mymat format 2string]"
puts "mymat rows= [mymat rows]"
puts "mymat columns= [mymat columns]"

#
## matrixName set cell column row value:
mymat set cell 0 0 11
mymat set cell 0 1 21
mymat set cell 1 0 12
mymat set cell 1 1 22
puts "mymat = [mymat serialize]"
puts "format 2string = [mymat format 2string]"

::struct::matrix mymat2
mymat2 add columns 2
mymat2 add rows 2

mymat2 set cell 0 0 1
mymat2 set cell 0 1 2
mymat2 set cell 1 0 3
mymat2 set cell 1 1 4
puts "mymat2 = [mymat2 serialize]"
puts "format 2string = [mymat2 format 2string]"
