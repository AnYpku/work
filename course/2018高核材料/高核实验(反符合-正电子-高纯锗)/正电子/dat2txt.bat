@echo OFF

md dat
md txt

set "str=.dat"

set "path=%~dp0"

setlocal enabledelayedexpansion
for /r %%i in (*.dat) do (set "var=%%i" && set "old=!var:%path%=!!" && convert "!old!")
for /r %%i in (*.txt) do (set "var=%%i" && set "old=!var:%path%=!!" && set "new=!old:%str%=!" && ren "!old!" "!new!")

for /r %%i in (*.dat) do (@move "%%i" .\dat)
for /r %%i in (*.txt) do (@move "%%i" .\txt)