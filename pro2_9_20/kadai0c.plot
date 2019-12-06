set size square
set xrange[-1:1]
set yrange[-1:1]
set samples 1000
set parametric
plot [0:2*pi]cos(t),sin(t)
set palette defined (0 "black",1 "red")
replot "kadai0c.dat" with points palette
replot[0:2*pi]0.5*cos(t),0.5*sin(t)
replot "kadai0c.dat" with lines
set terminal png size 800, 800
set output "kadai0c.png"
replot
