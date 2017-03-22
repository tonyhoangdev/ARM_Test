dir /b "C:\Program Files (x86)\SEGGER" > temp
set /p path= < temp
del temp
"C:/Program Files (x86)/SEGGER/JLink_V614b/JLinkGDBServerCL.exe" -device S32K148 -if swd -speed 1000