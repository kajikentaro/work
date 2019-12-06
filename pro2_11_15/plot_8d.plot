set size square
set xrange[1:1500000]
set logscale x
set logscale y
f(x)=A*x+B
fit f(x) "input.txt" using (log10($1)):(log10($2)) via A,B
plot "input.txt"
replot 10**(f(log10(x)))
set terminal png
set output "kadai08d.png"
replot