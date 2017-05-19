# compiler
CC     = cc
CFLAGS = -Tamd64-coff -Go -Ze -Os

# resource compiler
RC = porc64

# linker
LFLAGS = -libpath:"C:\\Program Files\\PellesC\\Lib\\Win64\\" -subsystem:windows -machine:X64 user32.lib shell32.lib src\\main.res#

.PHONY: clean

all: clean trey

trey: res
	powershell "[long]((get-date).touniversaltime()-[datetime]'1970-01-01').totalmilliseconds" > now.ts
	set /p TS= < now.ts
	rm now.ts
	$(CC) $(CFLAGS) src/*.c $(LFLAGS) -Fedist/trey-$(TS).exe
	mv src/*.obj obj/

res:
	$(RC) src/main.rc

clean:
	del /Q dist\* obj\* src\main.res