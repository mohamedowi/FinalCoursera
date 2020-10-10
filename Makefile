#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Building for two platforms MSP432 AND HOST
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds <FILE>.o object file
#      build - Builds and links all source files
#      all - Same as build
#      clean - removes all generated files
# Platform Overrides:
#      CPU,CC,LD,LDFLAGS,CFLAGS,CPPFLAGs,OBJDUMP
#
#------------------------------------------------------------------------------
include sources.mk
#c1m2 output executable target 
TARGET = c1m2

# Platform Overrides

# IF Host then Specs Are:
ifeq ($(PLATFORM),HOST)
CC = gcc
LD = ld
SIZE = size
LDFLAGS = -Wl,-Map=$(TARGET).map
OBJDUMP = objdump
CPPFLAGS = -E
endif

# IF MSP432 then Specs Are:
ifeq ($(PLATFORM),MSP432)
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
CC = arm-none-eabi-gcc  
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall
CPPFLAGS = -std=c99
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size 
CPPFLAGS = -E
ASF = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
endif

# End of overriding
#Common or General Flags + if the PLATFORM is MSP432
CFLAGS = -Wall -Werror -g -O0 -std=c99 -D$(PLATFORM) $(ASF)

PREPROCESSOR = $(SOURCES:.c=.i)

ASSEMBLY = $(SOURCES:.c=.asm)

OBJS = $(SOURCES:.c=.o)

DEPS = $(SOURCES:.c=.d)

FILES = *.asm *.i *.o *.d


%.i : %.c
	$(CC) $(INCLUDES) $(CPPFLAGS) $< $(CFLAGS) -o $@	

%.asm : %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -o $@
  
%.o : %.c
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@
  
%.d : %.c
	$(CC) $(INCLUDES) -M $< $(CFLAGS) -o $@
  
$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@


.PHONY: build
build: $(TARGET).out  $(TARGET).asm

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(INCLUDES) $(OBJS) -c $(CFLAGS) -o $(TARGET).o


$(TARGET).out: $(OBJS) $(DEPS) 
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@ $(OBJS)
	$(SIZE) -Atd $(TARGET).out
	$(SIZE) $(TARGET).out
.PHONY: clean
clean:
	rm -f $(PREPROCESSOR) $(ASSEMBLY) $(OBJS) $(DEPS) $(TARGET).map $(TARGET).out $(FILES) $(TARGET).asm
