.PHONY: all clean

APP=lab2ganN3145
CFLAGS=-Wall -Wextra -Werror -g

all: $(APP)

$(APP): $(APP).c
	gcc -o $(APP) $(CFLAGS) $(APP).c

clean:
	rm $(APP)

