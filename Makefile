# assmumes linux install
.c.o:
	cc -c $<

dng: dng.o
	cc $< -o $@ -lm 

install: dng
	sudo systemctl stop $< || true
	sudo cp $< /usr/local/bin
	sudo cp $<.service /etc/systemd/system
	sudo systemctl enable $< 
	sudo systemctl start $<
	systemctl status $<

clean:
	rm *.o dng
