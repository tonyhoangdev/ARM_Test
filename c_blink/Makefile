## MinhHT3 - TonyHoang
## v1.0 - 20161212
## v2.0 - 20170113
## v3.0 - 20170223
## search file c
VPATH=$(SOURCEDIR)

## Define CSOURCES and ASMSOURCES
CSOURCES:=main.c
CSOURCES+=startup.c
CSOURCES+=system_S32K144.c

ASMSOURCES:=startup_S32K144.S

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
CFLAGS:=-mcpu=cortex-m4 -mthumb
CFLAGS+=-DCPU_S32K144HFT0VLLT
CFLAGS+=-O1 -g3 -Wall
CFLAGS+=-c -fmessage-length=0 -ffunction-sections -fdata-sections 
CFLAGS+=-nostartfiles -nodefaultlibs
#CFLAGS+=--sysroot="C:\GNU\arm-none-eabi-4_9\arm-none-eabi" -specs=nano.specs
#CFLAGS+=-mfloat-abi=hard -mfpu=fpv4-sp-d16

## Assembly flags
ASFLAGS:=-mcpu=cortex-m4 -mthumb
ASFLAGS+=-x assembler-with-cpp
ASFLAGS+=-O0 -g3
ASFLAGS+=-nostartfiles -nodefaultlibs
#ASFLAGS+=--sysroot="C:\GNU\arm-none-eabi-4_9\arm-none-eabi" -specs=nano.specs

## Linker flags
LDFLAGS_FLASH:=-mcpu=cortex-m4 -mthumb

LDFLAGS_FLASH+=-Wl,-Map=$(MAP_FLASH) -Xlinker --gc-sections
LDFLAGS_FLASH+=-T "Project_Settings/Linker_Files/S32K1xx_flash.ld" --entry=Reset_Handler
LDFLAGS_FLASH+=-nostartfiles -nodefaultlibs
#LDFLAGS_FLASH+=--sysroot="C:\GNU\arm-none-eabi-4_9\arm-none-eabi" -specs=nano.specs
#LDFLAGS_FLASH+=-mfloat-abi=hard -mfpu=fpv4-sp-d16

LDFLAGS_RAM:=-mcpu=cortex-m4 -mthumb
LDFLAGS_RAM+=-Wl,-Map=$(MAP_RAM) -Xlinker --gc-sections
LDFLAGS_RAM+=-T"Project_Settings/Linker_Files/S32K1xx_ram.ld" --entry=Reset_Handler
LDFLAGS_RAM+=-nostartfiles -nodefaultlibs
#LDFLAGS_RAM+=--sysroot="C:\GNU\arm-none-eabi-4_9\arm-none-eabi" -specs=nano.specs
#LDFLAGS_RAM+=-mfloat-abi=hard -mfpu=fpv4-sp-d16


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
	@echo 'Linking to $(EXECUTABLE_RAM)'
	@$(LD) -o $(EXECUTABLE_RAM) $(COBJECTS) $(LDFLAGS_RAM)
	@echo $(SEPARATOR)
	@echo 'Linking to $(EXECUTABLE_FLASH)'
	@$(LD) -o $(EXECUTABLE_FLASH) $(COBJECTS) $(LDFLAGS_FLASH)
# Target used to print executables sizes
size:
	@echo $(SEPARATOR)
	@echo 'Size of $(EXECUTABLE_FLASH)'
	@$(CCSIZE) $(EXECUTABLE_FLASH)
	@echo 'Size of $(EXECUTABLE_RAM)'
	@$(CCSIZE) $(EXECUTABLE_RAM)
# Target used to print compile informations
print:
	@echo $(SEPARATOR)
	@echo 'Compile C options:'
	@echo '    $(CFLAGS)'
	@echo 'Compile ASM options:'
	@echo '    $(ASFLAGS)'
	@echo 'Includes:'
	@echo '    $(INCLUDES)'
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
