################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Commands/ReMeasure.c \
../Core/Src/Commands/SetDur.c \
../Core/Src/Commands/SetScale.c 

OBJS += \
./Core/Src/Commands/ReMeasure.o \
./Core/Src/Commands/SetDur.o \
./Core/Src/Commands/SetScale.o 

C_DEPS += \
./Core/Src/Commands/ReMeasure.d \
./Core/Src/Commands/SetDur.d \
./Core/Src/Commands/SetScale.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Commands/%.o Core/Src/Commands/%.su Core/Src/Commands/%.cyclo: ../Core/Src/Commands/%.c Core/Src/Commands/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F301x8 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Commands

clean-Core-2f-Src-2f-Commands:
	-$(RM) ./Core/Src/Commands/ReMeasure.cyclo ./Core/Src/Commands/ReMeasure.d ./Core/Src/Commands/ReMeasure.o ./Core/Src/Commands/ReMeasure.su ./Core/Src/Commands/SetDur.cyclo ./Core/Src/Commands/SetDur.d ./Core/Src/Commands/SetDur.o ./Core/Src/Commands/SetDur.su ./Core/Src/Commands/SetScale.cyclo ./Core/Src/Commands/SetScale.d ./Core/Src/Commands/SetScale.o ./Core/Src/Commands/SetScale.su

.PHONY: clean-Core-2f-Src-2f-Commands

