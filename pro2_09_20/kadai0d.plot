set size square
set xrange[-1:1]
set yrange[-1:1]
set samples 1000
set parametric
plot [0:2*pi]cos(t),sin(t)
replot "kadai0d.dat" with lines
set terminal png size 800, 800
set output "kadai0d.png"
replot
