default:
	gcc tty.c -c -o tty.o
	gcc editor.c -c -o editor.o
	gcc session.c -c -o session.o
	gcc main.c tty.o editor.o session.o
