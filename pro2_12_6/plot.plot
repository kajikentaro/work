set xrange [-1:5]
set yrange [-1:5]

plot "point.dat" using 1:2 with linespoints

set terminal png size 800, 800
set output "kadai11d.png"
replot

