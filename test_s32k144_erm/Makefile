## MinhHT3
## 20161212
## search file c
VPATH=$(SOURCEDIRALL)

## Define CSOURCES
CSOURCES:=
CSOURCES+=startup.c
CSOURCES+=system_S32K144.c
CSOURCES+=erm_driver.c
CSOURCES+=erm_hal.c

CSOURCES+=FSL_ERM_DRV_UT_TS001.c
CSOURCES+=FSL_ERM_HAL_UT_TS001.c
CSOURCES+=erm_test.c
CSOURCES+=main.c

## Define ASMSOURCES
ASMSOURCES:=startup_S32K144.S

## Define SOURCEDIR
BASEDIR:=../../../../04_Projects/ASDK-S32_SDK/sdk_codebase/
SOURCEDIR:=platform/devices/S32K144/include/
SOURCEDIR+=platform/devices/S32K144/startup/
SOURCEDIR+=platform/devices/S32K144/startup/gcc/
SOURCEDIR+=platform/devices/
SOURCEDIR+=platform/devices/common/

SOURCEDIR+=platform/drivers/inc/
SOURCEDIR+=platform/drivers/src/erm/
SOURCEDIR+=platform/hal/inc/
SOURCEDIR+=platform/hal/src/erm/

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
CFLAGS+=-Wall -Wextra -Wstrict-prototypes -pedantic
CFLAGS+=-O1
CFLAGS+=-funsigned-char -funsigned-bitfields  -fshort-enums
CFLAGS+=-ffunction-sections -fdata-sections -fno-jump-tables
CFLAGS+=-std=gnu99# -save-temps=obj
CFLAGS+=-g
CFLAGS+=-DCPU_S32K144HFT0VLLT

# Assenbler file extension
ASM_EXT:=S
# Map file names
MAP_FLASH:=app_flash.map
## Execute file ##
EXECUTABLE_FLASH:=app_flash.elf

## Linker flags
LDFLAGS_FLASH:=-Wl,-Map=$(MAP_FLASH)
LDFLAGS_FLASH+=-nostartfiles -nodefaultlibs -nostdlib -T "$(BASEDIR)/platform/devices/S32K144/linker/gcc/S32K144_64_flash.ld" --entry=Reset_Handler -Wl,-gc-sections
#LDFLAGS_FLASH+=-lgcc -lm -lc -lrdimon --specs=rdimon.specs

## Internal variables
OBJECTS:=$(CSOURCES:%.c=%.o)
OBJECTS+=$(ASMSOURCES:%.$(ASM_EXT)=%.o)
COBJECTS:=$(addprefix $(OBJECTDIR),$(OBJECTS))
SOURCEDIRALL:=$(SOURCEDIR_NAME)
SOURCEDIRALL+=$(addprefix $(BASEDIR),$(SOURCEDIR))

INCLUDES:=$(addprefix -I,$(SOURCEDIRALL))

## Targets
all: print $(EXECUTABLE_FLASH) size

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

size:
	@$(CCSIZE) $(EXECUTABLE_FLASH)

print:
	@echo 'Compile options: $(CFLAGS) $(INCLUDES)'

dir:
	mkdir -p $(OBJECTDIR)

clean:
	$(RM) -rf $(OBJECTDIR)

clean_all:
	$(RM) -rf $(OBJECTDIR) $(EXECUTABLE_FLASH) $(MAP_FLASH)

run:
	@echo 'Run...'
	@./$(EXECUTABLE_FLASH)

.PHONY: all print dir size run clean clean_all
