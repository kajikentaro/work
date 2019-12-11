set size square
set xrange[-1:1]
set yrange[-1:1]
set samples 1000
set parametric
plot [0:30*pi]0.01*t*cos(t),0.01*t*sin(t)
set terminal png size 800, 800
set output "kadai0a.png"
replot
