set yrange[0:]
set style data histogram
set style histogram cluster gap 1
set style fill solid
plot "kadai09b_2.txt" using 2:xticlabels(1)notitle
set terminal png
set output "kadai09b_2.png"
replot