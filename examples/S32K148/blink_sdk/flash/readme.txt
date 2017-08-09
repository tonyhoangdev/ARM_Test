Copy to flash folder example folder

1. JLINK
In the run_Jlink_server.bat file
Changes device to create server gdb
set device=S32K142
set device=S32K144
set device=S32K146
set device=S32K148

In the runJlink.txt file
Changes monitor device to create client gdb
monitor device = S32K142
monitor device = S32K144
monitor device = S32K146
monitor device = S32K148

2. PE
In the run_PE_server.bat file
Changes to create server gdb
set device=NXP_S32K1xx_S32K142F256M15
set device=NXP_S32K1xx_S32K144F512M15
set device=NXP_S32K1xx_S32K144F512M150N77P
set device=NXP_S32K1xx_S32K146F1M0M11
set device=NXP_S32K1xx_S32K148F2M0M11

