DEPS = gpio-toggle.h
OBJ = gpio-toggle.o

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

gpio-toggle: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lgpiod

install: gpio-toggle
	mkdir -p $(WORKDIR)
	cp gpio-toggle $(WORKDIR)/

clean:
	rm -f *.o
	rm -f gpio-toggle
