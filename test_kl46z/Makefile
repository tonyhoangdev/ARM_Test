## MinhHT3 - TonyHoang
## v1.0 - 20161212
## v2.0 - 20170113
## v3.0 - 20170223
## search file c
VPATH=$(SOURCEDIR)

## Define CSOURCES and ASMSOURCES
CSOURCES:=main.c
CSOURCES+=startup.c
CSOURCES+=system_MKL46Z4.c


ASMSOURCES:=startup_MKL46Z4.S

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
CC:=arm-none-eabi-gcc
AS:=arm-none-eabi-gcc
LD:=arm-none-eabi-gcc
RM:=rm -f
CCSIZE:=arm-none-eabi-size

## Toolchain C flags ##
CFLAGS:=-mcpu=cortex-m0plus -mthumb
CFLAGS+=-DCPU_MKL46Z256VLL4
CFLAGS+=-O1 -g3
CFLAGS+=-Wall -Wextra -Wstrict-prototypes -pedantic
CFLAGS+=-ffunction-sections -fdata-sections -fno-jump-tables


## Linker flags
LDFLAGS_FLASH:=-Wl,-Map=$(MAP_FLASH) -Wl,-gc-sections
LDFLAGS_FLASH+=-T "Project_Settings/Linker_Files/MKL46Z256xxx4_flash.ld" --entry=Reset_Handler
LDFLAGS_FLASH+=-nostartfiles -nodefaultlibs -nostdlib


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
	@echo -e '$(SEPARATOR)\nLinking to $(EXECUTABLE_FLASH)'
	@$(LD) -o $(EXECUTABLE_FLASH) $(COBJECTS) $(LDFLAGS_FLASH)
# Target used to print executables sizes
size: print $(EXECUTABLE_FLASH)
	@echo '$(SEPARATOR)'
	@echo 'Size of $(EXECUTABLE_FLASH)'
	@$(CCSIZE) $(EXECUTABLE_FLASH)
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
	$(RM) -rf $(OBJECTDIR) $(EXECUTABLE_FLASH) $(MAP_FLASH) $(MAP_RAM)

.PHONY: all print dir size clean
