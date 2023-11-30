all:market
	echo "market program"
market:main.o avilablestock.o purchase.o sell.o 
	gcc main.o avilablestock.o purchase.o sell.o -o market
main:main.c
	gcc -c main.c
avilablestock:avilablestock.c
	gcc -c avilablestock.c
purchase:purchase.c
	gcc -c purchase.c
sell:sell.c
	gcc -c sell.c
clean:
	rm *.o market
install:
	sudo cp market /bin

