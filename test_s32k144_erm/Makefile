## MinhHT3 - TonyHoang
## v1.0 - 20161212
## v2.0 - 20170113
## search file c
VPATH=$(SOURCEDIRALL)

## Define CSOURCES
CSOURCES:=
CSOURCES+=startup.c
CSOURCES+=system_S32K144.c
# CSOURCES+=erm_driver.c
# CSOURCES+=erm_hal.c

#CSOURCES+=FSL_ERM_DRV_UT_TS001.c
#CSOURCES+=FSL_ERM_HAL_UT_TS001.c
#CSOURCES+=erm_test.c
CSOURCES+=main.c

## Define ASMSOURCES
ASMSOURCES:=startup_S32K144.S

## Define SOURCEDIR
BASEDIR:=./
SOURCEDIR:=include/
SOURCEDIR+=Project_Settings/Startup_Code/

SOURCEDIR+=platform/drivers/inc/
SOURCEDIR+=platform/drivers/src/erm/
SOURCEDIR+=platform/hal/inc/
SOURCEDIR+=platform/hal/src/erm/

LIBDIR:=
LIBDIR+=

SOURCEDIR_NAME:=src/


## Location of objects
OBJECTDIR:=obj/

## Toolchain EXECUTABLE_FLASHs ##
CC:=arm-none-eabi-gcc
AS:=arm-none-eabi-gcc
LD:=arm-none-eabi-gcc
RM:=rm -f
CCSIZE:=arm-none-eabi-size

## Toolchain flags ##
CFLAGS:=-mcpu=cortex-m4 -mthumb
#CFLAGS+=-mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS+=-DCPU_S32K144HFT0VLLT
CFLAGS+=-O1 -g3 -Wall
CFLAGS+=-c -fmessage-length=0 -ffunction-sections -fdata-sections -fsigned-char 
#CFLAGS+=--sysroot="C:\GNU\arm-none-eabi-4_9\arm-none-eabi" -specs=nano.specs
CFLAGS+=-nostartfiles -nodefaultlibs

ASFLAGS:=-mcpu=cortex-m4 -mthumb
ASFLAGS+=-x assembler-with-cpp
ASFLAGS+=-O0 -g3
#ASFLAGS+=--sysroot="C:\GNU\arm-none-eabi-4_9\arm-none-eabi" -specs=nano.specs
ASFLAGS+=-nostartfiles -nodefaultlibs

# Assenbler file extension
ASM_EXT:=S
# Map file names
MAP_FLASH:=app_flash.map
MAP_RAM:=app_ram.map
## Execute file ##
EXECUTABLE_FLASH:=app_flash.elf
EXECUTABLE_RAM:=app_ram.elf

## Linker flags
LDFLAGS_FLASH:=-mcpu=cortex-m4 -mthumb
#LDFLAGS_FLASH+=-mfloat-abi=hard -mfpu=fpv4-sp-d16
LDFLAGS_FLASH+=-Wl,-Map=$(MAP_FLASH) -Xlinker --gc-sections
LDFLAGS_FLASH+=-T "Project_Settings/Linker_Files/S32K1xx_flash.ld" --entry=Reset_Handler
#LDFLAGS_FLASH+=--sysroot="C:\GNU\arm-none-eabi-4_9\arm-none-eabi" -specs=nano.specs
LDFLAGS_FLASH+=-nostartfiles -nodefaultlibs

LDFLAGS_RAM:=-mcpu=cortex-m4 -mthumb
#LDFLAGS_RAM+=-mfloat-abi=hard -mfpu=fpv4-sp-d16
LDFLAGS_RAM+=-Wl,-Map=$(MAP_RAM) -Xlinker --gc-sections
LDFLAGS_RAM+=-T"Project_Settings/Linker_Files/S32K1xx_ram.ld" --entry=Reset_Handler
#LDFLAGS_RAM+=--sysroot="C:\GNU\arm-none-eabi-4_9\arm-none-eabi" -specs=nano.specs
LDFLAGS_RAM+=-nostartfiles -nodefaultlibs

## Internal variables
OBJECTS:=$(CSOURCES:%.c=%.o)
OBJECTS+=$(ASMSOURCES:%.$(ASM_EXT)=%.o)
COBJECTS:=$(addprefix $(OBJECTDIR),$(OBJECTS))
SOURCEDIRALL:=$(SOURCEDIR_NAME)
SOURCEDIRALL+=$(addprefix $(BASEDIR),$(SOURCEDIR))
SOURCEDIRALL+=$(LIBDIR)

INCLUDES:=$(addprefix -I,$(SOURCEDIRALL))

## Targets
all: print $(EXECUTABLE_FLASH) $(EXECUTABLE_RAM) size

$(EXECUTABLE_FLASH): dir $(COBJECTS)
	@echo 'Linking to $(EXECUTABLE_FLASH)'
	@$(LD) -o $(EXECUTABLE_FLASH) $(COBJECTS) $(LDFLAGS_FLASH)

# $<: dependency (%.c)
# $@: target (%.o)
$(OBJECTDIR)%.o: %.c
	@echo 'Compiling $@'
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJECTDIR)%.o: %.S
	@echo 'Compiling $@'
	@$(AS) $(ASFLAGS) $(INCLUDES) -c $< -o $@

$(EXECUTABLE_RAM): $(COBJECTS)
	@echo 'Linking to $(EXECUTABLE_RAM)'
	@$(LD) -o $(EXECUTABLE_RAM) $(COBJECTS) $(LDFLAGS_RAM)
size:
	@echo 'size of $(EXECUTABLE_FLASH)'
	@$(CCSIZE) $(EXECUTABLE_FLASH)
	@echo 'size of $(EXECUTABLE_RAM)'
	@$(CCSIZE) $(EXECUTABLE_RAM)

print:
	@echo 'Compile options: $(CFLAGS) $(INCLUDES)'

dir:
	mkdir -p $(OBJECTDIR)

clean:
	$(RM) -rf $(OBJECTDIR)

clean_all:
	$(RM) -rf $(OBJECTDIR) $(EXECUTABLE_FLASH) $(MAP_FLASH) $(EXECUTABLE_RAM) $(MAP_RAM)

run:
	@echo 'Run...'
	@./$(EXECUTABLE_FLASH)

.PHONY: all print dir size run clean clean_all
