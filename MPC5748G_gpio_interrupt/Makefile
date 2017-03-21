## MinhHT3 - TonyHoang
## v1.0 - 20161212
## v2.0 - 20170113
## v3.0 - 20170223
## search file c
VPATH=$(SOURCEDIR)

## Define CSOURCES and ASMSOURCES
CSOURCES:=main.c
CSOURCES+=flashrchw.c
CSOURCES+=intc_SW_mode_isr_vectors_MPC5748G.c
CSOURCES+=MPC57xx__Interrupt_Init.c
CSOURCES+=Vector.c

ASMSOURCES:=startup.S
ASMSOURCES+=intc_sw_handlers.S

## Define SOURCEDIR_LIB
BASEDIR:=./
SOURCEDIR_LIB:=include/
SOURCEDIR_LIB+=Project_Settings/Startup_Code/

## Location of objects
OBJECTDIR_NAME:=obj
SOURCEDIR_NAME:=src

# Assenbler file extension
ASM_EXT:=S

# Map file names
MAP_FLASH:=app_flash.map
MAP_RAM:=app_ram.map

## Execute file ##
EXECUTABLE_FLASH:=app_flash.elf
EXECUTABLE_RAM:=app_ram.elf

## Toolchain executables ##
CC:=powerpc-eabivle-gcc
AS:=powerpc-eabivle-gcc
LD:=powerpc-eabivle-gcc
RM:=rm -f
CCSIZE:=powerpc-eabivle-size.exe

## Toolchain C flags ##
CFLAGS:=-mcpu=e200z4
CFLAGS+=-mhard-float -mbig -mvle -mregnames
CFLAGS+=-DSTART_FROM_FLASH -DMPC574xG -DTURN_ON_CPU0
# CFLAGS+=-DTURN_ON_CPU1 
# CFLAGS+=-DTURN_ON_CPU2 
# CFLAGS+=-DDEBUG_SECONDARY_CORES
CFLAGS+=-O1 -g3 -Wall
CFLAGS+=-c -fmessage-length=0 -ffunction-sections -fdata-sections -fsigned-char 
#CFLAGS+=--sysroot="C:\GNU\powerpc-eabivle-4_9\powerpc-eabivle\newlib" -specs=nano.specs
CFLAGS+=-nostartfiles -nodefaultlibs

## Assembly flags
ASFLAGS:=-mcpu=e200z4 
ASFLAGS+=-DSTART_FROM_FLASH -DMPC574xG -DDISABLE_SWT0 -DI_CACHE -DD_CACHE 
# ASFLAGS+=-DHW_INIT
ASFLAGS+=-x assembler-with-cpp
ASFLAGS+=-O0 -g3 -mbig -mvle -mregnames
#ASFLAGS+=--sysroot="C:\GNU\powerpc-eabivle-4_9\powerpc-eabivle\newlib" -specs=nano.specs
ASFLAGS+=-nostartfiles -nodefaultlibs

## Linker flags
LDFLAGS_FLASH:=-mcpu=e200z4
LDFLAGS_FLASH+=-mhard-float
LDFLAGS_FLASH+=-Wl,-Map=$(MAP_FLASH) -Xlinker --gc-sections
LDFLAGS_FLASH+=-T "Project_Settings/Linker_Files/57xx_flash.ld" -T "Project_Settings/Linker_Files/libs.ld"
#LDFLAGS_FLASH+=--sysroot="C:\GNU\powerpc-eabivle-4_9\powerpc-eabivle\newlib" -specs=nano.specs
LDFLAGS_FLASH+=-nostartfiles -nodefaultlibs

LDFLAGS_RAM:=-mcpu=e200z4
LDFLAGS_RAM+=-mhard-float
LDFLAGS_RAM+=-Wl,-Map=$(MAP_RAM) -Xlinker --gc-sections
LDFLAGS_RAM+=-T"Project_Settings/Linker_Files/57xx_ram.ld"
#LDFLAGS_RAM+=--sysroot="C:\GNU\powerpc-eabivle-4_9\powerpc-eabivle\newlib" -specs=nano.specs
LDFLAGS_RAM+=-nostartfiles -nodefaultlibs


## Internal variables
OBJECTS=$(CSOURCES:%.c=%.o)
OBJECTS+=$(ASMSOURCES:%.$(ASM_EXT)=%.o)
OBJECTDIR=$(OBJECTDIR_NAME)/
COBJECTS:=$(addprefix $(OBJECTDIR),$(OBJECTS))

SOURCEDIR=$(SOURCEDIR_NAME)/
SOURCEDIR+=$(addprefix $(BASEDIR),$(SOURCEDIR_LIB))

INCLUDES:=$(addprefix -I,$(SOURCEDIR))

SEPARATOR=========================================

## Targets
all: print dir $(EXECUTABLE_FLASH) size build_complete

# Target used to compile C source files
# $<: dependency (%.c)
# $@: target (%.o)
$(OBJECTDIR)%.o: %.c
	@echo -e '$(SEPARATOR)\nCompiling $@'
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
# Target used to compile assembler files
$(OBJECTDIR)%.o: %.S
	@echo -e '$(SEPARATOR)\nCompiling $@'
	@$(AS) $(ASFLAGS) $(INCLUDES) -c $< -o $@
# Target used to link compiled sources
$(EXECUTABLE_FLASH): $(COBJECTS)
	@echo -e '$(SEPARATOR)\nLinking to $(EXECUTABLE_RAM)'
	@$(LD) -o $(EXECUTABLE_RAM) $(COBJECTS) $(LDFLAGS_RAM)
	@echo -e '$(SEPARATOR)\nLinking to $(EXECUTABLE_FLASH)'
	@$(LD) -o $(EXECUTABLE_FLASH) $(COBJECTS) $(LDFLAGS_FLASH)
# Target used to print executables sizes
size: print $(EXECUTABLE_FLASH)
	@echo '$(SEPARATOR)'
	@echo 'Size of $(EXECUTABLE_FLASH)'
	@$(CCSIZE) $(EXECUTABLE_FLASH)
	@echo 'Size of $(EXECUTABLE_RAM)'
	@$(CCSIZE) $(EXECUTABLE_RAM)
# Target used to print compile informations
print:
	@echo $(SEPARATOR)
	@echo -e '_____Compile C options_____:\n    $(CFLAGS)\n'
	@echo -e '_____Compile ASM options_____:\n    $(ASFLAGS)\n'
	@echo -e '_____LDFLAGS_FLASH options_____:\n    $(LDFLAGS_FLASH)\n'
	@echo -e '_____LDFLAGS_RAM options_____:\n    $(LDFLAGS_RAM)\n'
	@echo -e '_____Includes_____:\n    $(INCLUDES)\n'
build_complete: size
	@echo $(SEPARATOR)
	@echo 'Build completed!'
#Target used to create folder used to store temporary objects
dir:
	@mkdir -p $(OBJECTDIR)
#Target used to remove files and folders
clean:
	@echo $(SEPARATOR)
	$(RM) -rf $(OBJECTDIR) $(EXECUTABLE_FLASH) $(EXECUTABLE_RAM) $(MAP_FLASH) $(MAP_RAM)

.PHONY: all print dir size clean
