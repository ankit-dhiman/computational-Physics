#    Author : Ankit Dhiman

set terminal pngcairo 
set output "rK4Method.png"
set grid
set xlabel "x"
set ylabel "y"
set title "Solution of ODE using Runge Kutta 4th order Method   dy/dx = 1+y^2 " font ",14"
set xrange [0:pi/3];set yrange[0:]


set key width 1
set key bottom right box 
set key font ",10"
set tics nomirror
set xtics 0,.01,pi/3
set xtics ("0" 0, "{/Symbol p}/6" pi/6 ,"{/Symbol p}/20" pi/20 ,"{/Symbol p}/10" pi/10 ,"{/Symbol p}/4" pi/4 ,"{/Symbol p}/3" pi/3)
set tics font ",12"
set border lw 1

plot "solution.dat" using 1:2  title " y(x)" with lines lc rgb "#8b0000"  
