## MinhHT3 - TonyHoang
## v1.0 - 20161212
## v2.0 - 20170112
## search file c
VPATH=$(SOURCEDIRALL)

## Define CSOURCES
CSOURCES:=
CSOURCES+=flashrchw.c
CSOURCES+=intc_SW_mode_isr_vectors_MPC5748G.c
CSOURCES+=MPC57xx__Interrupt_Init.c
CSOURCES+=Vector.c
CSOURCES+=main.c
## Define ASMSOURCES
ASMSOURCES:=startup.S
ASMSOURCES+=intc_sw_handlers.S

## Define SOURCEDIR
BASEDIR:=./
SOURCEDIR:=include/
SOURCEDIR+=Project_Settings/Startup_Code/
LIBDIR:=
LIBDIR+=

SOURCEDIR_NAME:=src/

## Location of objects
OBJECTDIR:=obj/

## Toolchain EXECUTABLE_FLASHs ##
CC:=powerpc-eabivle-gcc
AS:=powerpc-eabivle-gcc
LD:=powerpc-eabivle-gcc
RM:=rm -f
CCSIZE:=powerpc-eabivle-size.exe

## Toolchain flags ##
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

ASFLAGS:=-mcpu=e200z4 
ASFLAGS+=-DSTART_FROM_FLASH -DMPC574xG -DDISABLE_SWT0 -DI_CACHE -DD_CACHE 
# ASFLAGS+=-DHW_INIT
ASFLAGS+=-x assembler-with-cpp
ASFLAGS+=-O0 -g3 -mbig -mvle -mregnames
#ASFLAGS+=--sysroot="C:\GNU\powerpc-eabivle-4_9\powerpc-eabivle\newlib" -specs=nano.specs
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
