set xrange [-1:1]
set yrange [-1:1]

plot "point.dat" using 1:2 with linespoints

set terminal png size 800, 800
set output "output.png"
replot

