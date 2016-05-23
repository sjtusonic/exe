source ~/sonic/github/small_lib/include.tcl

namespace eval db {
   variable data
   variable uid 0
   variable index
}

proc db::insert {keylist datablob} { ;# $key-(index)->$uid-(data)->$datablob
   variable data
   variable uid
   variable index
   set data([incr uid]) $datablob
   foreach key $keylist {
      lappend index($key) $uid
   }
}

proc db::get {key} {
   variable data
   variable index
   set result {}
   if {![info exist index($key)]} {
      return {}
   }
   foreach uid $index($key) {
      lappend result $data($uid)
   }
   return $result
}

proc db::save {filename} {
   variable uid
   set out [open $filename w]
   puts $out [list namespace eval db \
      [list variable uid $uid]]
   puts $out [list array set db::data  [array get db::data ]]
   puts $out [list array set db::index [array get db::index]]
   close $out
}
proc db::load {filename} {
   source $filename
}

if {0} { ;# test
   db::insert 0     [list 0 01 02 03]
   db::insert 0 [list 1 11 12 13 14]
   db::insert 0 [list 2 11 12 13 14]
   db::insert {1 2} [list x  11 12 13 14]
   db::insert {2 3} [list x 11 12 13 14]
   db::insert {4 3} [list 3 11 12 13 14]
   db::save ./KL.sav
   puts [db::get 0]
}
