start cmd /k run_make.bat
start cmd /k run_PE_server.bat
ping 127.0.0.1 -n 5 > nul

start cmd /k run_PE_manual.bat
