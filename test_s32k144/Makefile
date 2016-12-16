## MinhHT3
## 20161212
## search file c
VPATH=$(SOURCEDIR)

## Define CSOURCES
CSOURCES:=
CSOURCES+=startup.c
CSOURCES+=system_S32K144.c

CSOURCES+=main.c

## Define ASMSOURCES
ASMSOURCES:=startup_S32K144.S

## Define SOURCEDIR
BASEDIR:=./
SOURCEDIR:=include/
SOURCEDIR+=Project_Settings/Startup_Code/
SOURCEDIR+=src/

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
EXECUTABLE_FLASH=app_flash.elf

## Linker flags
LDFLAGS_FLASH:=-Wl,-Map=$(MAP_FLASH)
LDFLAGS_FLASH+=-nostartfiles -nodefaultlibs -nostdlib -T "$(BASEDIR)\Project_Settings\Linker_Files\S32K1xx_flash.ld" --entry=Reset_Handler -Wl,-gc-sections
#LDFLAGS_FLASH+=-lgcc -lm -lc -lrdimon --specs=rdimon.specs

## Internal variables
OBJECTS=$(CSOURCES:%.c=%.o)
OBJECTS+=$(ASMSOURCES:%.$(ASM_EXT)=%.o)
COBJECTS=$(addprefix $(OBJECTDIR),$(OBJECTS))
INCLUDES=$(addprefix -I,$(SOURCEDIR))

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
	rm -rf $(OBJECTDIR)

clean_all:
	rm -rf $(OBJECTDIR) $(EXECUTABLE_FLASH) $(MAP_FLASH)

run:
	@echo 'Run...'
	@./$(EXECUTABLE_FLASH)

.PHONY: all print dir size run clean clean_all
