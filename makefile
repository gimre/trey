# compiler
CC     = cc
CFLAGS = -Tamd64-coff -Go -Ze -Os

# resource compiler
RC = porc64

# signing
SIGN     = "C:\Program Files (x86)\Microsoft SDKs\Windows\v7.1\Bin\signtool.exe"
SIGNARGS = sign /f cert\\trey.pfx /p !TREY_CERT_PASSWORD! /t http://timestamp.verisign.com/scripts/timstamp.dll /v

# linker
LFLAGS = -libpath:"C:\\Program Files\\PellesC\\Lib\\Win64\\" -subsystem:windows -machine:X64 user32.lib shell32.lib src\\main.res#

.PHONY: clean res sign

all: clean trey

clean:
	del /Q dist\* obj\* src\main.res

res:
	$(RC) src/main.rc

trey: res
	powershell "[long]((get-date).touniversaltime()-[datetime]'1970-01-01').totalmilliseconds" > now.ts
	cmd /v /c "set /p TS= < now.ts && $(CC) $(CFLAGS) src/*.c $(LFLAGS) -Fedist/trey-!TS!.exe && $(SIGN) $(SIGNARGS) dist\\trey-!TS!.exe || rem"
	cmd /c "del now.ts"
	cmd /c "move src\main.obj  obj"
	cmd /c "move src\utils.obj obj"

