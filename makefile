all: first_pic.c
	gcc first_pic.c -o picture

run: all
	./picture
	convert picture.ppm picture.png

clean:
	rm -f *~
	rm -f picture
	rm -f picture.ppm
	rm -f picture.png
