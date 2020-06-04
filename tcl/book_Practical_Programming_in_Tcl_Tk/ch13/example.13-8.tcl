
proc ReadOnlyVar {varName} {
   upvar 1 $varName var
   global ReaOnly
   set ReaOnly($varName) $var
   trace variable $varName wu ReaOnlyTrace
}

proc ReaOnlyTrace { varName index op} {
   global ReaOnly
   upvar 1 $varName var
   switch $op {
      w {
         set var $ReaOnly($varName)
      }
      u {
         set var $ReaOnly($varName)
         trace variable $varName wu ReaOnlyTrace
      }
   }
}

# test:

set a 1
ReadOnlyVar a

puts "a=$a"
set a 1
puts "a=$a"
set a 2
puts "a=$a"
incr a
puts "a=$a"
