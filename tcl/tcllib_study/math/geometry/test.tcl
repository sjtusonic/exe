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
package require struct::tree 
package require math::geometry 1.3.0
#package require math::geometry 

#set point1 [list 1 2]
#set point2 [list 3 4]

#############
# MAIN
#############
## PROCEDURES
proc putsEnter  {p args} {global _UDV_DBG_PUTS_TAB;puts "$_UDV_DBG_PUTS_TAB--> $p";set _UDV_DBG_PUTS_TAB "$_UDV_DBG_PUTS_TAB--.";}
#proc putsEnter  {p args} {global _UDV_DBG_PUTS_TAB;puts "$_UDV_DBG_PUTS_TAB--> $p";set _UDV_DBG_PUTS_TAB "$_UDV_DBG_PUTS_TAB--."; puts "info scr= [info script]"}
proc putsReturn {p args} {global _UDV_DBG_PUTS_TAB;set _UDV_DBG_PUTS_TAB [regsub "...$" $_UDV_DBG_PUTS_TAB {}];puts "$_UDV_DBG_PUTS_TAB<-- $p"}
set proc_list {::math::geometry::inproduct ::math::geometry::p}
lappend proc_list ::math::geometry::areaParallellogram
set proc_list ""

foreach p $proc_list {
	trace add execution $p {enter} [list putsEnter]
		trace add execution $p {leave} [list putsReturn]
}
set p1 [::math::geometry::p 1 1]

## 
## ::math::geometry::p x y
set point1 [::math::geometry::p 1 3]
set point2 [::math::geometry::p 2 5]

## The package defines the following public procedures:
## 
## ::math::geometry::+ point1 point2
## 
## Compute the sum of the two vectors given as points and return it. The result is a vector as well.
## 
## ::math::geometry::- point1 point2
## 
## Compute the difference (point1 - point2) of the two vectors given as points and return it. The result is a vector as well.
puts "-----------------------------------------------"
puts [::math::geometry::+ $point1 $point2]
puts [::math::geometry::- $point1 $point2]
## 
## Construct a point from its coordinates and return it as the result of the command.
## 
## ::math::geometry::distance point1 point2
## 
## Compute the distance between the two points and return it as the result of the command. This is in essence the same as
## 
puts "-----------------------------------------------"
puts "distance:"
puts [::math::geometry::distance $point1 $point2]
## math::geometry::length [math::geomtry::- point1 point2]
## ::math::geometry::length point
## 
## Compute the length of the vector and return it as the result of the command.
## 
puts "-----------------------------------------------"
puts "length:"
puts [::math::geometry::length $point1]
puts "s:"
puts "p1:$point1"
## ::math::geometry::s* factor point
## 
## Scale the vector by the factor and return it as the result of the command. This is a vector as well.
## 
set factor 3
puts [::math::geometry::s* $factor  $point1]
## ::math::geometry::direction angle
## 
## Given the angle in degrees this command computes and returns the unit vector pointing into this direction. The vector for angle == 0 points to the right (up), and for angle == 90 up (north).
puts "-----------------------------------------------"
puts "direction:"
set angle 30 ;# in degrees
for {set angle 0} {$angle <=360} {incr angle 30} {
puts "angle:$angle:\t[::math::geometry::direction $angle]"
}

## 
## ::math::geometry::h length
## 
## Returns a horizontal vector on the X-axis of the specified length. Positive lengths point to the right (east).
puts "-----------------------------------------------"
set cmd "::math::geometry::h -3 "
puts "$cmd = [eval $cmd]"
## 
## ::math::geometry::v length
## 
## Returns a vertical vector on the Y-axis of the specified length. Positive lengths point down (south).
puts "-----------------------------------------------"
set cmd "::math::geometry::v 3 "
puts "$cmd = [eval $cmd]"
## 
## ::math::geometry::between point1 point2 s
## 
## Compute the point which is at relative distance s between the two points and return it as the result of the command. A relative distance of 0 returns point1, the distance 1 returns point2. Distances < 0 or > 1 extrapolate along the line between the two point.
puts "-----------------------------------------------"
set cmd " ::math::geometry::between \$point1 \$point2 0.5"
puts "$cmd = [eval $cmd]"
## 
## ::math::geometry::octant point
## 
## Compute the octant of the circle the point is in and return it as the result of the command. The possible results are
## 
## east
## northeast
## north
## northwest
## west
## southwest
## south
## southeast
## Each octant is the arc of the circle +/- 22.5 degrees from the cardinal direction the octant is named for.
puts "-----------------------------------------------"
puts "TEST anble:"
for {set angle 0} {$angle <=360} {incr angle 30} {
	set pp [::math::geometry::direction $angle]
	set cmd "::math::geometry::octant \$pp"
	#puts "$cmd = [eval $cmd]"
	puts "angle=$angle\tpoint=$pp\toctant=[eval $cmd]"
}
## 
## ::math::geometry::rect nw se
## 
## Construct a rectangle from its northwest and southeast corners and return it as the result of the command.
puts "-----------------------------------------------"
puts "point1=$point1"
puts "point2=$point2"
set cmd " ::math::geometry::rect \$point1 \$point2 "
puts "$cmd = [eval $cmd]"
## 
## ::math::geometry::nwse rect
## 
## Extract the northwest and southeast corners of the rectangle and return them as the result of the command (a 2-element list containing the points, in the named order).

puts "-----------------------------------------------"
puts "TEST nwse:"
set rect  [::math::geometry::rect $point1 $point2 ]
set cmd " ::math::geometry::nwse \$rect"
puts "$cmd = [eval $cmd]"
set res [eval $cmd]
foreach {i j} $res {
	puts "p1=$i, p2=$j"
}
## 
## ::math::geometry::angle line
## 
## Calculate the angle from the positive x-axis to a given line (in two dimensions only).
## 
## 	list line
## 
## 	Coordinates of the line
puts "-----------------------------------------------"
puts "TEST angle:"
set line [list 1 2 3 4]
puts "line = $line"
set cmd " ::math::geometry::angle \$line"
puts "$cmd = [eval $cmd]"
## 
## ::math::geometry::angleBetween vector1 vector2
## 
## Calculate the angle between two vectors (in degrees)
## 
## list vector1
## 
## First vector
## 
## list vector2
## 
## Second vector
puts "-----------------------------------------------"
puts "TEST angleBetween:"
set point1 [::math::geometry::p 1 0]
set point2 [::math::geometry::p 0 2]
#puts "$cmd = [eval $cmd]"
puts [::math::geometry::angleBetween $point1 $point2]

## ::math::geometry::inproduct vector1 vector2
## 
## Calculate the inner product of two vectors
## 
## list vector1
## 
## First vector
## 
## list vector2
## 
## Second vector
puts "-----------------------------------------------"
puts "TEST inproduct:"
set p1 [::math::geometry::p 1 1]
set p2 [::math::geometry::p 3 2]

set cmd "::math::geometry::inproduct \$p1 \$p2"
 puts "$cmd = [eval $cmd]"
## 
## ::math::geometry::areaParallellogram vector1 vector2
## 
## Calculate the area of the parallellogram with the two vectors as its sides
## 
## list vector1
## 
## First vector
## 
## list vector2
## 
## Second vector
puts "-----------------------------------------------"
puts "TEST areaParallellogram:"
set p1 [::math::geometry::p 0 1]
set p2 [::math::geometry::p 2 1]

set cmd "::math::geometry::areaParallellogram \$p1 \$p2"
#::math::geometry::areaParallellogram $p1 $p2
puts "$cmd = [eval $cmd]"
# puts "[info frame 0]"
## 
## ::math::geometry::calculateDistanceToLine P line
## 
## Calculate the distance of point P to the (infinite) line and return the result
## 
## list P
## 
## List of two numbers, the coordinates of the point
## 
## list line
## 
## List of four numbers, the coordinates of two points on the line
puts "-----------------------------------------------"
puts "TEST calculateDistanceToLine:"
set p1 [::math::geometry::p 0 0]
puts "point = $p1"
#set p2 [::math::geometry::p 2 1]
set line [list 0 2 2 0]
puts "line = $line"

set cmd "::math::geometry::calculateDistanceToLine \$p1 \$line"
puts "$cmd = [eval $cmd]" ;# is 2^0.5
## 
## ::math::geometry::calculateDistanceToLineSegment P linesegment
## 
## Calculate the distance of point P to the (finite) line segment and return the result.
## 
## list P
## 
## List of two numbers, the coordinates of the point
## 
## list linesegment
## 
## List of four numbers, the coordinates of the first and last points of the line segment
puts "-----------------------------------------------"
puts "TEST calculateDistanceToLineSegment:"
set p1 [::math::geometry::p -2 0]
puts "point = $p1"
#set p2 [::math::geometry::p 2 1]
set lineSeg [list 1 0 0 1]
puts "lineSeg = $lineSeg"

set cmd "::math::geometry::calculateDistanceToLineSegment \$p1 \$lineSeg" ;
# point (-2,0) has no perpendicular to line {1 0 0 1}
# so the Distance is from point(-2,0) to (0,1), it's 5^0.5
#
puts "$cmd = [eval $cmd]" 
## 
## ::math::geometry::calculateDistanceToPolyline P polyline
## 
## Calculate the distance of point P to the polyline and return the result. Note that a polyline needs not to be closed.
## 
## list P
## 
## List of two numbers, the coordinates of the point
## 
## list polyline
## 
## List of numbers, the coordinates of the vertices of the polyline
puts "-----------------------------------------------"
puts "TEST calculateDistanceToPolyline:"
set p1 [::math::geometry::p -2 0]
puts "point = $p1"
#set p2 [::math::geometry::p 2 1]
set polyline [list 1 0 0 1 1 1 2 0.5]
puts "polyline = $polyline"

set cmd "::math::geometry::calculateDistanceToPolyline \$p1 \$polyline" ;
puts "$cmd = [eval $cmd]" 
## 
## ::math::geometry::calculateDistanceToPolygon P polygon
## 
## Calculate the distance of point P to the polygon and return the result. If the list of coordinates is not closed (first and last points differ), it is automatically closed.
## 
## list P
## 
## List of two numbers, the coordinates of the point
## 
## list polygon
## 
## List of numbers, the coordinates of the vertices of the polygon
puts "-----------------------------------------------"
puts "TEST calculateDistanceToPolygon:"
set p1 [::math::geometry::p -2 0]
puts "point = $p1"
#set p2 [::math::geometry::p 2 1]
set polygon [list 1 0 0 1 1 1 2 0.5]
puts "polygon = $polygon"

set cmd "::math::geometry::calculateDistanceToPolygon \$p1 \$polygon" ;
puts "$cmd = [eval $cmd]" 
## 
## ::math::geometry::findClosestPointOnLine P line
## 
## Return the point on a line which is closest to a given point.
## 
## list P
## 
## List of two numbers, the coordinates of the point
## 
## list line
## 
## List of four numbers, the coordinates of two points on the line
puts "-----------------------------------------------"
puts "TEST findClosestPointOnLine:"
set p1 [::math::geometry::p -2 0]
puts "point = $p1"
#set p2 [::math::geometry::p 2 1]
set polygon [list 1 0 0 1 ]
puts "polygon = $polygon"

set cmd "::math::geometry::findClosestPointOnLine \$p1 \$polygon" ;
puts "$cmd = [eval $cmd]" 
## 
## ::math::geometry::findClosestPointOnLineSegment P linesegment
## 
## Return the point on a line segment which is closest to a given point.
## 
## list P
## 
## List of two numbers, the coordinates of the point
## 
## list linesegment
## 
## List of four numbers, the first and last points on the line segment
puts "-----------------------------------------------"
puts "TEST findClosestPointOnLineSegment:"
set p1 [::math::geometry::p -2 0]
puts "point = $p1"
#set p2 [::math::geometry::p 2 1]
set polygon [list 1 0 0 1 ]
puts "polygon = $polygon"

set cmd "::math::geometry::findClosestPointOnLineSegment \$p1 \$polygon" ; # it's more obvious here for the difference between line and line segment
puts "$cmd = [eval $cmd]" 
## 
## ::math::geometry::findClosestPointOnPolyline P polyline
## 
## Return the point on a polyline which is closest to a given point.
## 
## list P
## 
## List of two numbers, the coordinates of the point
## 
## list polyline
## 
## List of numbers, the vertices of the polyline
puts "-----------------------------------------------"
puts "TEST findClosestPointOnPolyline:"
set p1 [::math::geometry::p -2 0]
puts "point = $p1"
#set p2 [::math::geometry::p 2 1]
set polygon [list 1 0 0 1 ]
puts "polygon = $polygon"

set cmd "::math::geometry::findClosestPointOnPolyline \$p1 \$polygon" ; # it's more obvious here for the difference between line and line segment
puts "$cmd = [eval $cmd]" 
## 
## ::math::geometry::lengthOfPolyline polyline
## 
## Return the length of the polyline (note: it not regarded as a polygon)
## 
## list polyline
## 
## List of numbers, the vertices of the polyline
puts "-----------------------------------------------"
puts "TEST lengthOfPolyline:"
set polyline [list 1 0 0 1 1 2 0 2]
puts "polyline = $polyline"

set cmd "::math::geometry::lengthOfPolyline \$polyline" 
puts "$cmd = [eval $cmd]" 
## TODO
## 
## ::math::geometry::movePointInDirection P direction dist
## 
## Move a point over a given distance in a given direction and return the new coordinates (in two dimensions only).
## 
## list P
## 
## Coordinates of the point to be moved
## 
## double direction
## 
## Direction (in degrees; 0 is to the right, 90 upwards)
## 
## list dist
## 
## Distance over which to move the point
## 
## ::math::geometry::lineSegmentsIntersect linesegment1 linesegment2
## 
## Check if two line segments intersect or coincide. Returns 1 if that is the case, 0 otherwise (in two dimensions only). If an endpoint of one segment lies on the other segment (or is very close to the segment), they are considered to intersect
## 
## list linesegment1
## 
## First line segment
## 
## list linesegment2
## 
## Second line segment
## 
## ::math::geometry::findLineSegmentIntersection linesegment1 linesegment2
## 
## Find the intersection point of two line segments. Return the coordinates or the keywords "coincident" or "none" if the line segments coincide or have no points in common (in two dimensions only).
## 
## list linesegment1
## 
## First line segment
## 
## list linesegment2
## 
## Second line segment
## 
## ::math::geometry::findLineIntersection line1 line2
## 
## Find the intersection point of two (infinite) lines. Return the coordinates or the keywords "coincident" or "none" if the lines coincide or have no points in common (in two dimensions only).
## 
## list line1
## 
## First line
## 
## list line2
## 
## Second line
## 
## See section References for details on the algorithm and math behind it.
## 
## ::math::geometry::polylinesIntersect polyline1 polyline2
## 
## Check if two polylines intersect or not (in two dimensions only).
## 
## list polyline1
## 
## First polyline
## 
## list polyline2
## 
## Second polyline
## 
## ::math::geometry::polylinesBoundingIntersect polyline1 polyline2 granularity
## 
## Check whether two polylines intersect, but reduce the correctness of the result to the given granularity. Use this for faster, but weaker, intersection checking.
## 
## How it works:
## 
## Each polyline is split into a number of smaller polylines, consisting of granularity points each. If a pair of those smaller lines' bounding boxes intersect, then this procedure returns 1, otherwise it returns 0.
## 
## list polyline1
## 
## First polyline
## 
## list polyline2
## 
## Second polyline
## 
## int granularity
## 
## Number of points in each part (<=1 means check every edge)
## 
## ::math::geometry::intervalsOverlap y1 y2 y3 y4 strict
## 
## Check if two intervals overlap.
## 
## double y1,y2
## 
## Begin and end of first interval
## 
## double y3,y4
## 
## Begin and end of second interval
## 
## logical strict
## 
## Check for strict or non-strict overlap
## 
## ::math::geometry::rectanglesOverlap P1 P2 Q1 Q2 strict
## 
## Check if two rectangles overlap.
## 
## list P1
## 
## upper-left corner of the first rectangle
## 
## list P2
## 
## lower-right corner of the first rectangle
## 
## list Q1
## 
## upper-left corner of the second rectangle
## 
## list Q2
## 
## lower-right corner of the second rectangle
## 
## list strict
## 
## choosing strict or non-strict interpretation
## 
## ::math::geometry::bbox polyline
## 
## Calculate the bounding box of a polyline. Returns a list of four coordinates: the upper-left and the lower-right corner of the box.
## 
## list polyline
## 
## The polyline to be examined
## 
## ::math::geometry::pointInsidePolygon P polyline
## 
## Determine if a point is completely inside a polygon. If the point touches the polygon, then the point is not completely inside the polygon.
## 
## list P
## 
## Coordinates of the point
## 
## list polyline
## 
## The polyline to be examined
## 
## ::math::geometry::pointInsidePolygonAlt P polyline
## 
## Determine if a point is completely inside a polygon. If the point touches the polygon, then the point is not completely inside the polygon. Note: this alternative procedure uses the so-called winding number to determine this. It handles self-intersecting polygons in a "natural" way.
## 
## list P
## 
## Coordinates of the point
## 
## list polyline
## 
## The polyline to be examined
## 
## ::math::geometry::rectangleInsidePolygon P1 P2 polyline
## 
## Determine if a rectangle is completely inside a polygon. If polygon touches the rectangle, then the rectangle is not complete inside the polygon.
## 
## list P1
## 
## Upper-left corner of the rectangle
## 
## list P2
## 
## Lower-right corner of the rectangle
## 
## list polygon
## 
## The polygon in question
## 
## ::math::geometry::areaPolygon polygon
## 
## Calculate the area of a polygon.
## 
## list polygon
## 
## The polygon in question
## 
## ::math::geometry::translate vector polyline
## 
## Translate a polyline over a given vector
## 
## list vector
## 
## Translation vector
## 
## list polyline
## 
## The polyline to be translated
## 
## ::math::geometry::rotate angle polyline
## 
## Rotate a polyline over a given angle (degrees) around the origin
## 
## list angle
## 
## Angle over which to rotate the polyline (degrees)
## 
## list polyline
## 
## The polyline to be rotated
## 
## ::math::geometry::reflect angle polyline
## 
## Reflect a polyline in a line through the origin at a given angle (degrees) to the x-axis
## 
## list angle
## 
## Angle of the line of reflection (degrees)
## 
## list polyline
## 
## The polyline to be reflected
## 
## ::math::geometry::degToRad angle
## 
## Convert from degrees to radians
## 
## list angle
## 
## Angle in degrees
## 
## ::math::geometry::radToDeg angle
## 
## Convert from radians to degrees
## 
## list angle
## 
## Angle in radians
## 
## ::math::geometry::circle centre radius
## 
## Convenience procedure to create a circle from a point and a radius.
## 
## list centre
## 
## Coordinates of the circle centre
## 
## list radius
## 
## Radius of the circle
## 
## ::math::geometry::circleTwoPoints point1 point2
## 
## Convenience procedure to create a circle from two points on its circumference The centre is the point between the two given points, the radius is half the distance between them.
## 
## list point1
## 
## First point
## 
## list point2
## 
## Second point
## 
## ::math::geometry::pointInsideCircle point circle
## 
## Determine if the given point is inside the circle or on the circumference (1) or outside (0).
## 
## list point
## 
## Point to be checked
## 
## list circle
## 
## Circle that may or may not contain the point
## 
## ::math::geometry::lineIntersectsCircle line circle
## 
## Determine if the given line intersects the circle or touches it (1) or does not (0).
## 
## list line
## 
## Line to be checked
## 
## list circle
## 
## Circle that may or may not be intersected
## 
## ::math::geometry::lineSegmentIntersectsCircle segment circle
## 
## Determine if the given line segment intersects the circle or touches it (1) or does not (0).
## 
## list segment
## 
## Line segment to be checked
## 
## list circle
## 
## Circle that may or may not be intersected
## 
## ::math::geometry::intersectionLineWithCircle line circle
## 
## Determine the points at which the given line intersects the circle. There can be zero, one or two points. (If the line touches the circle or is close to it, then one point is returned. An arbitrary margin of 1.0e-10 times the radius is used to determine this situation.)
## 
## list line
## 
## Line to be checked
## 
## list circle
## 
## Circle that may or may not be intersected
## 
## ::math::geometry::intersectionCircleWithCircle circle1 circle2
## 
## Determine the points at which the given two circles intersect. There can be zero, one or two points. (If the two circles touch the circle or are very close, then one point is returned. An arbitrary margin of 1.0e-10 times the mean of the radii of the two circles is used to determine this situation.)
## 
## list circle1
## 
## First circle
## 
## list circle2
## 
## Second circle
## 
## ::math::geometry::tangentLinesToCircle point circle
## 
## Determine the tangent lines from the given point to the circle. There can be zero, one or two lines. (If the point is on the cirucmference or very close to the circle, then one line is returned. An arbitrary margin of 1.0e-10 times the radius of the circle is used to determine this situation.)
## 
## list point
## 
## Point in question
## 
## list circle
## 
## Circle to which the tangent lines are to be determined
puts "info scr= [info script]"
