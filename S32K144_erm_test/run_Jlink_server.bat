dir /b "C:\Program Files (x86)\SEGGER" > temp
set /p path= < temp
del temp
"C:/Program Files (x86)/SEGGER/%path%/JLinkGDBServerCL.exe" -device S32K144 -if swd -speed 1000