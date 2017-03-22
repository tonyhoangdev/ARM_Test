dir /b "C:\Program Files (x86)\SEGGER" > temp
set /p path= < temp
del temp
"C:/Program Files (x86)/SEGGER/%path%/JLinkGDBServerCL.exe" -device MKL46Z256xxx4 -if swd -speed 1000