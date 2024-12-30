################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Game/Smoke.c \
../Core/Src/Game/appGame.c \
../Core/Src/Game/plane1.c \
../Core/Src/Game/plane2.c \
../Core/Src/Game/plane3.c \
../Core/Src/Game/plane4.c \
../Core/Src/Game/plane5.c \
../Core/Src/Game/plane6.c 

C_DEPS += \
./Core/Src/Game/Smoke.d \
./Core/Src/Game/appGame.d \
./Core/Src/Game/plane1.d \
./Core/Src/Game/plane2.d \
./Core/Src/Game/plane3.d \
./Core/Src/Game/plane4.d \
./Core/Src/Game/plane5.d \
./Core/Src/Game/plane6.d 

OBJS += \
./Core/Src/Game/Smoke.o \
./Core/Src/Game/appGame.o \
./Core/Src/Game/plane1.o \
./Core/Src/Game/plane2.o \
./Core/Src/Game/plane3.o \
./Core/Src/Game/plane4.o \
./Core/Src/Game/plane5.o \
./Core/Src/Game/plane6.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Game/%.o Core/Src/Game/%.su Core/Src/Game/%.cyclo: ../Core/Src/Game/%.c Core/Src/Game/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -IC:/Users/LENOVO/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/LENOVO/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/LENOVO/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/LENOVO/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include -IC:/Users/hoang/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/hoang/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/hoang/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/hoang/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include -I"C:/Users/MSI MODERN 14/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/MSI MODERN 14/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/MSI MODERN 14/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/MSI MODERN 14/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Game

clean-Core-2f-Src-2f-Game:
	-$(RM) ./Core/Src/Game/Smoke.cyclo ./Core/Src/Game/Smoke.d ./Core/Src/Game/Smoke.o ./Core/Src/Game/Smoke.su ./Core/Src/Game/appGame.cyclo ./Core/Src/Game/appGame.d ./Core/Src/Game/appGame.o ./Core/Src/Game/appGame.su ./Core/Src/Game/plane1.cyclo ./Core/Src/Game/plane1.d ./Core/Src/Game/plane1.o ./Core/Src/Game/plane1.su ./Core/Src/Game/plane2.cyclo ./Core/Src/Game/plane2.d ./Core/Src/Game/plane2.o ./Core/Src/Game/plane2.su ./Core/Src/Game/plane3.cyclo ./Core/Src/Game/plane3.d ./Core/Src/Game/plane3.o ./Core/Src/Game/plane3.su ./Core/Src/Game/plane4.cyclo ./Core/Src/Game/plane4.d ./Core/Src/Game/plane4.o ./Core/Src/Game/plane4.su ./Core/Src/Game/plane5.cyclo ./Core/Src/Game/plane5.d ./Core/Src/Game/plane5.o ./Core/Src/Game/plane5.su ./Core/Src/Game/plane6.cyclo ./Core/Src/Game/plane6.d ./Core/Src/Game/plane6.o ./Core/Src/Game/plane6.su

.PHONY: clean-Core-2f-Src-2f-Game

