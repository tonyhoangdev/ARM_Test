## MinhHT3 - TonyHoang
## v1.0 - 20161212
## v2.0 - 20170113
## v3.0 - 20170223
## search file c
VPATH=$(SOURCEDIR)

## Define CSOURCES and ASMSOURCES
CSOURCES:=
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
	@echo $(SEPARATOR)
	@echo 'Compiling $@'
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
# Target used to compile assembler files
$(OBJECTDIR)%.o: %.S
	@echo $(SEPARATOR)
	@echo 'Compiling $@'
	@$(AS) $(ASFLAGS) $(INCLUDES) -c $< -o $@
# Target used to link compiled sources
$(EXECUTABLE_FLASH): $(COBJECTS)
	@echo $(SEPARATOR)
	@echo 'Linking to $(EXECUTABLE_FLASH)'
	@$(LD) -o $(EXECUTABLE_FLASH) $(COBJECTS) $(LDFLAGS_FLASH)
# Target used to print executables sizes
size:
	@echo $(SEPARATOR)
	@echo 'Size of $(EXECUTABLE_FLASH)'
	@$(CCSIZE) $(EXECUTABLE_FLASH)
# Target used to print compile informations
print:
	@echo $(SEPARATOR)
	@echo 'Includes:'
	@echo '    $(INCLUDES)'
	@echo ''
	@echo 'Compile C options:'
	@echo '    $(CFLAGS)'
	@echo ''
	@echo 'Compile ASM options:'
	@echo '    $(ASFLAGS)'
	@echo ''
	@echo 'LDFLAGS_FLASH options:'
	@echo '    $(LDFLAGS_FLASH)'
	@echo ''
	@echo 'LDFLAGS_RAM options:'
	@echo '    $(LDFLAGS_RAM)'
build_complete:
	@echo $(SEPARATOR)
	@echo 'Build completed!'
#Target used to create folder used to store temprary objects
dir:
	@mkdir -p $(OBJECTDIR)
#Target used to remove files and folders
clean:
	@echo $(SEPARATOR)
	$(RM) -rf $(OBJECTDIR) $(EXECUTABLE_FLASH) $(EXECUTABLE_RAM) $(MAP_FLASH) $(MAP_RAM)

.PHONY: all print dir size clean
