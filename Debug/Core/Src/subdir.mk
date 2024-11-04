################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Checksum.c \
../Core/Src/Measurements.c \
../Core/Src/RequestQueue.c \
../Core/Src/SettingsStore.c \
../Core/Src/exp_i2c_slave.c \
../Core/Src/i2c_queue.c \
../Core/Src/main.c \
../Core/Src/stm32f3xx_hal_msp.c \
../Core/Src/stm32f3xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f3xx.c 

OBJS += \
./Core/Src/Checksum.o \
./Core/Src/Measurements.o \
./Core/Src/RequestQueue.o \
./Core/Src/SettingsStore.o \
./Core/Src/exp_i2c_slave.o \
./Core/Src/i2c_queue.o \
./Core/Src/main.o \
./Core/Src/stm32f3xx_hal_msp.o \
./Core/Src/stm32f3xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f3xx.o 

C_DEPS += \
./Core/Src/Checksum.d \
./Core/Src/Measurements.d \
./Core/Src/RequestQueue.d \
./Core/Src/SettingsStore.d \
./Core/Src/exp_i2c_slave.d \
./Core/Src/i2c_queue.d \
./Core/Src/main.d \
./Core/Src/stm32f3xx_hal_msp.d \
./Core/Src/stm32f3xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f3xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F301x8 -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Checksum.cyclo ./Core/Src/Checksum.d ./Core/Src/Checksum.o ./Core/Src/Checksum.su ./Core/Src/Measurements.cyclo ./Core/Src/Measurements.d ./Core/Src/Measurements.o ./Core/Src/Measurements.su ./Core/Src/RequestQueue.cyclo ./Core/Src/RequestQueue.d ./Core/Src/RequestQueue.o ./Core/Src/RequestQueue.su ./Core/Src/SettingsStore.cyclo ./Core/Src/SettingsStore.d ./Core/Src/SettingsStore.o ./Core/Src/SettingsStore.su ./Core/Src/exp_i2c_slave.cyclo ./Core/Src/exp_i2c_slave.d ./Core/Src/exp_i2c_slave.o ./Core/Src/exp_i2c_slave.su ./Core/Src/i2c_queue.cyclo ./Core/Src/i2c_queue.d ./Core/Src/i2c_queue.o ./Core/Src/i2c_queue.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f3xx_hal_msp.cyclo ./Core/Src/stm32f3xx_hal_msp.d ./Core/Src/stm32f3xx_hal_msp.o ./Core/Src/stm32f3xx_hal_msp.su ./Core/Src/stm32f3xx_it.cyclo ./Core/Src/stm32f3xx_it.d ./Core/Src/stm32f3xx_it.o ./Core/Src/stm32f3xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f3xx.cyclo ./Core/Src/system_stm32f3xx.d ./Core/Src/system_stm32f3xx.o ./Core/Src/system_stm32f3xx.su

.PHONY: clean-Core-2f-Src

