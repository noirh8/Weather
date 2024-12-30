################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/icon/IconCloud.c \
../Core/Src/icon/Temp.c \
../Core/Src/icon/Temp2.c \
../Core/Src/icon/TempMinor.c \
../Core/Src/icon/TempMinor2.c \
../Core/Src/icon/Wind.c \
../Core/Src/icon/Wind2.c \
../Core/Src/icon/iconApp.c \
../Core/Src/icon/iconBack.c \
../Core/Src/icon/iconCloudMinor.c \
../Core/Src/icon/iconFreezing.c \
../Core/Src/icon/iconFreezingMinor.c \
../Core/Src/icon/iconFreezingRain.c \
../Core/Src/icon/iconFreezingRainMinor.c \
../Core/Src/icon/iconHome.c \
../Core/Src/icon/iconMenu.c \
../Core/Src/icon/iconRain.c \
../Core/Src/icon/iconRainMinor.c \
../Core/Src/icon/iconRefresh.c \
../Core/Src/icon/iconSun.c \
../Core/Src/icon/iconSunMinor.c \
../Core/Src/icon/iconThunder.c \
../Core/Src/icon/iconThunderMinor.c \
../Core/Src/icon/imgMorning.c 

C_DEPS += \
./Core/Src/icon/IconCloud.d \
./Core/Src/icon/Temp.d \
./Core/Src/icon/Temp2.d \
./Core/Src/icon/TempMinor.d \
./Core/Src/icon/TempMinor2.d \
./Core/Src/icon/Wind.d \
./Core/Src/icon/Wind2.d \
./Core/Src/icon/iconApp.d \
./Core/Src/icon/iconBack.d \
./Core/Src/icon/iconCloudMinor.d \
./Core/Src/icon/iconFreezing.d \
./Core/Src/icon/iconFreezingMinor.d \
./Core/Src/icon/iconFreezingRain.d \
./Core/Src/icon/iconFreezingRainMinor.d \
./Core/Src/icon/iconHome.d \
./Core/Src/icon/iconMenu.d \
./Core/Src/icon/iconRain.d \
./Core/Src/icon/iconRainMinor.d \
./Core/Src/icon/iconRefresh.d \
./Core/Src/icon/iconSun.d \
./Core/Src/icon/iconSunMinor.d \
./Core/Src/icon/iconThunder.d \
./Core/Src/icon/iconThunderMinor.d \
./Core/Src/icon/imgMorning.d 

OBJS += \
./Core/Src/icon/IconCloud.o \
./Core/Src/icon/Temp.o \
./Core/Src/icon/Temp2.o \
./Core/Src/icon/TempMinor.o \
./Core/Src/icon/TempMinor2.o \
./Core/Src/icon/Wind.o \
./Core/Src/icon/Wind2.o \
./Core/Src/icon/iconApp.o \
./Core/Src/icon/iconBack.o \
./Core/Src/icon/iconCloudMinor.o \
./Core/Src/icon/iconFreezing.o \
./Core/Src/icon/iconFreezingMinor.o \
./Core/Src/icon/iconFreezingRain.o \
./Core/Src/icon/iconFreezingRainMinor.o \
./Core/Src/icon/iconHome.o \
./Core/Src/icon/iconMenu.o \
./Core/Src/icon/iconRain.o \
./Core/Src/icon/iconRainMinor.o \
./Core/Src/icon/iconRefresh.o \
./Core/Src/icon/iconSun.o \
./Core/Src/icon/iconSunMinor.o \
./Core/Src/icon/iconThunder.o \
./Core/Src/icon/iconThunderMinor.o \
./Core/Src/icon/imgMorning.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/icon/%.o Core/Src/icon/%.su Core/Src/icon/%.cyclo: ../Core/Src/icon/%.c Core/Src/icon/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -IC:/Users/LENOVO/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/LENOVO/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/LENOVO/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/LENOVO/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include -IC:/Users/hoang/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/hoang/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/hoang/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/hoang/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include -I"C:/Users/MSI MODERN 14/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/MSI MODERN 14/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/MSI MODERN 14/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/MSI MODERN 14/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-icon

clean-Core-2f-Src-2f-icon:
	-$(RM) ./Core/Src/icon/IconCloud.cyclo ./Core/Src/icon/IconCloud.d ./Core/Src/icon/IconCloud.o ./Core/Src/icon/IconCloud.su ./Core/Src/icon/Temp.cyclo ./Core/Src/icon/Temp.d ./Core/Src/icon/Temp.o ./Core/Src/icon/Temp.su ./Core/Src/icon/Temp2.cyclo ./Core/Src/icon/Temp2.d ./Core/Src/icon/Temp2.o ./Core/Src/icon/Temp2.su ./Core/Src/icon/TempMinor.cyclo ./Core/Src/icon/TempMinor.d ./Core/Src/icon/TempMinor.o ./Core/Src/icon/TempMinor.su ./Core/Src/icon/TempMinor2.cyclo ./Core/Src/icon/TempMinor2.d ./Core/Src/icon/TempMinor2.o ./Core/Src/icon/TempMinor2.su ./Core/Src/icon/Wind.cyclo ./Core/Src/icon/Wind.d ./Core/Src/icon/Wind.o ./Core/Src/icon/Wind.su ./Core/Src/icon/Wind2.cyclo ./Core/Src/icon/Wind2.d ./Core/Src/icon/Wind2.o ./Core/Src/icon/Wind2.su ./Core/Src/icon/iconApp.cyclo ./Core/Src/icon/iconApp.d ./Core/Src/icon/iconApp.o ./Core/Src/icon/iconApp.su ./Core/Src/icon/iconBack.cyclo ./Core/Src/icon/iconBack.d ./Core/Src/icon/iconBack.o ./Core/Src/icon/iconBack.su ./Core/Src/icon/iconCloudMinor.cyclo ./Core/Src/icon/iconCloudMinor.d ./Core/Src/icon/iconCloudMinor.o ./Core/Src/icon/iconCloudMinor.su ./Core/Src/icon/iconFreezing.cyclo ./Core/Src/icon/iconFreezing.d ./Core/Src/icon/iconFreezing.o ./Core/Src/icon/iconFreezing.su ./Core/Src/icon/iconFreezingMinor.cyclo ./Core/Src/icon/iconFreezingMinor.d ./Core/Src/icon/iconFreezingMinor.o ./Core/Src/icon/iconFreezingMinor.su ./Core/Src/icon/iconFreezingRain.cyclo ./Core/Src/icon/iconFreezingRain.d ./Core/Src/icon/iconFreezingRain.o ./Core/Src/icon/iconFreezingRain.su ./Core/Src/icon/iconFreezingRainMinor.cyclo ./Core/Src/icon/iconFreezingRainMinor.d ./Core/Src/icon/iconFreezingRainMinor.o ./Core/Src/icon/iconFreezingRainMinor.su ./Core/Src/icon/iconHome.cyclo ./Core/Src/icon/iconHome.d ./Core/Src/icon/iconHome.o ./Core/Src/icon/iconHome.su ./Core/Src/icon/iconMenu.cyclo ./Core/Src/icon/iconMenu.d ./Core/Src/icon/iconMenu.o ./Core/Src/icon/iconMenu.su ./Core/Src/icon/iconRain.cyclo ./Core/Src/icon/iconRain.d ./Core/Src/icon/iconRain.o ./Core/Src/icon/iconRain.su ./Core/Src/icon/iconRainMinor.cyclo ./Core/Src/icon/iconRainMinor.d ./Core/Src/icon/iconRainMinor.o ./Core/Src/icon/iconRainMinor.su ./Core/Src/icon/iconRefresh.cyclo ./Core/Src/icon/iconRefresh.d ./Core/Src/icon/iconRefresh.o ./Core/Src/icon/iconRefresh.su ./Core/Src/icon/iconSun.cyclo ./Core/Src/icon/iconSun.d ./Core/Src/icon/iconSun.o ./Core/Src/icon/iconSun.su ./Core/Src/icon/iconSunMinor.cyclo ./Core/Src/icon/iconSunMinor.d ./Core/Src/icon/iconSunMinor.o ./Core/Src/icon/iconSunMinor.su ./Core/Src/icon/iconThunder.cyclo ./Core/Src/icon/iconThunder.d ./Core/Src/icon/iconThunder.o ./Core/Src/icon/iconThunder.su ./Core/Src/icon/iconThunderMinor.cyclo ./Core/Src/icon/iconThunderMinor.d ./Core/Src/icon/iconThunderMinor.o ./Core/Src/icon/iconThunderMinor.su ./Core/Src/icon/imgMorning.cyclo ./Core/Src/icon/imgMorning.d ./Core/Src/icon/imgMorning.o ./Core/Src/icon/imgMorning.su

.PHONY: clean-Core-2f-Src-2f-icon

