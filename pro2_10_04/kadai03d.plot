set size square
set xrange [-2:2]
set cbrange[0:3]
set xzeroaxis
set yzeroaxis
set palette defined (0 "black" ,1 "red", 2 "green", 3 "blue")
unset colorbox
plot x*(x*x-2) linecolor "black", "kadai03d.txt" with points palette notitle
set terminal png size 800, 800
set output "kadai03d.png"
replot