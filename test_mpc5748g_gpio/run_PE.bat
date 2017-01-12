start cmd /k run_PE_server.bat
make
ping 127.0.0.1 -n 8 > nul
start cmd /k run_PE_manual.bat
