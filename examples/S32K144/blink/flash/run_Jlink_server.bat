@echo off
rem dir /b "C:\Program Files (x86)\SEGGER" > temp
rem set /p path= < temp
rem del temp

rem set device=S32K142
rem set device=S32K144
rem set device=S32K146
rem set device=S32K148

set device=S32K144

"C:/Program Files (x86)/SEGGER/JLink_V614b/JLinkGDBServerCL.exe" -device %device% -if swd -speed 1000