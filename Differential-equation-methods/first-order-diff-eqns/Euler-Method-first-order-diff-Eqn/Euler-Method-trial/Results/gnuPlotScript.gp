set terminal pngcairo enhanced
set output "EulerMethodOde.png"
set grid
set xlabel "x"
set ylabel "y"
set title "Solution of ODE using Euler's Method   dy/dx = 1+y^2 " font ",14"
set xrange [0:pi/3];set yrange[0:]


set key width 0
set key bottom right box 
set key font ",10"
set tics nomirror
set xtics 0,.01,pi/3
set border 7
set xtics ("0" 0, "{/Symbol p}/6" pi/6 ,"{/Symbol p}/20" pi/20 ,"{/Symbol p}/10" pi/10 ,"{/Symbol p}/4" pi/4 ,"{/Symbol p}/3" pi/3)
set tics font ",12"
set border lw 2

plot "solOfOde.dat" using 1:2  title " yEuler" with lines lc rgb "#8b0000"  
