@echo off

rem set device=NXP_S32K1xx_S32K142F256M15
rem set device=NXP_S32K1xx_S32K144F512M15
rem set device=NXP_S32K1xx_S32K144F512M150N77P
rem set device=NXP_S32K1xx_S32K146F1M0M11
rem set device=NXP_S32K1xx_S32K148F2M0M11

set device=NXP_S32K1xx_S32K142F256M15

"c:/NXP/S32DS_ARM_v2.0/eclipse/plugins/com.pemicro.debug.gdbjtag.pne_3.0.6.201706261721/win32/pegdbserver_console.exe" -device=%device% -startserver -singlesession -serverport=7224 -gdbmiport=6224 -speed=5000