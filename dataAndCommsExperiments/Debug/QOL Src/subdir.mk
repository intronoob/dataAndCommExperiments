################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/STM32STUFF/STM32\ custom\ libraries/QOL\ stuff/Src/qol.c 

OBJS += \
./QOL\ Src/qol.o 

C_DEPS += \
./QOL\ Src/qol.d 


# Each subdirectory must supply rules for building sources it contributes
QOL\ Src/qol.o: E:/STM32STUFF/STM32\ custom\ libraries/QOL\ stuff/Src/qol.c QOL\ Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I"E:/STM32STUFF/STM32 custom libraries/QOL stuff/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"QOL Src/qol.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-QOL-20-Src

clean-QOL-20-Src:
	-$(RM) ./QOL\ Src/qol.cyclo ./QOL\ Src/qol.d ./QOL\ Src/qol.o ./QOL\ Src/qol.su

.PHONY: clean-QOL-20-Src

