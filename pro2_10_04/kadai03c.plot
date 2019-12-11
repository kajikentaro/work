set terminal gif animate delay 100 optimize size 640,480
set output "kadai03c_3.gif"
set xrange[-5:5]
set yrange[-50:50]
set xzeroaxis
set yzeroaxis
do for[i=0:10]{
m_str = sprintf("%d times",i)
plot x*(x*x-2),"kadai03c.txt" every ::i::i using 1:2 with points ps 2 pt 7 title m_str}
unset output
