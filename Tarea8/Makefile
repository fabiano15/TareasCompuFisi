all:
	cc -o comp1.out metodos.c tarea_8.c -lm 
	./comp1.out
	gnuplot -e "set term png; set output 'dibujo'; plot '0.dat' using 1:2 , '1000.dat' using 1:2, '2000.dat' using 1:2, '3000.dat' using 1:2, '4000.dat' using 1:2, '5000.dat' using 1:2, '6000.dat' using 1:2, '7000.dat' using 1:2, '8000.dat' using 1:2, '9000.dat' using 1:2, '10000.dat' using 1:2"
	
	cc -o comp2.out metodos2.c tarea_8_2.c -lm 
	./comp2.out
	gnuplot -e "set term png; set output 'dibujo2'; plot '02.dat' using 1:2 , '10002.dat' using 1:2, '20002.dat' using 1:2, '30002.dat' using 1:2, '40002.dat' using 1:2, '50002.dat' using 1:2, '60002.dat' using 1:2, '70002.dat' using 1:2, '80002.dat' using 1:2, '90002.dat' using 1:2, '100002.dat' using 1:2"
	
	
	
	make clean	


	
clean:
	
	mv 0.dat ./datos
	mv 1000.dat ./datos
	mv 2000.dat ./datos
	mv 3000.dat ./datos
	mv 4000.dat ./datos
	mv 5000.dat ./datos
	mv 6000.dat ./datos
	mv 7000.dat ./datos
	mv 8000.dat ./datos
	mv 9000.dat ./datos
	mv 10000.dat ./datos
	rm comp1.out 
	mv 02.dat ./datos
	mv 10002.dat ./datos
	mv 20002.dat ./datos
	mv 30002.dat ./datos
	mv 40002.dat ./datos
	mv 50002.dat ./datos
	mv 60002.dat ./datos
	mv 70002.dat ./datos
	mv 80002.dat ./datos
	mv 90002.dat ./datos
	mv 100002.dat ./datos
	rm comp2.out

	
