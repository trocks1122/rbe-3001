################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
lab.lss \

FLASH_IMAGE += \
lab.hex \

EEPROM_IMAGE += \
lab.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: lab.elf secondary-outputs

# Tool invocations
lab.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lab.map -L"R:\RBE 3001\lab1\RBELib\Release" -mmcu=atmega644p -o "lab.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lab.lss: lab.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lab.elf  >"lab.lss"
	@echo 'Finished building: $@'
	@echo ' '

lab.hex: lab.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex lab.elf  "lab.hex"
	@echo 'Finished building: $@'
	@echo ' '

lab.eep: lab.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex lab.elf  "lab.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lab.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega644p lab.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) lab.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
