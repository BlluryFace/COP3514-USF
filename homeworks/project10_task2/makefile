student.o: student.c student.h
	gcc -c student.c


project10_registration.o: project10_registration.c student.h
	gcc -c project10_registration.c

project10_registration: student.o project10_registration.o
	gcc -o project10_registration student.o project10_registration.o