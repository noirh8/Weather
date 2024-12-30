################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Common.c \
../Core/Src/ControlApp.c \
../Core/Src/DateAndTime.c \
../Core/Src/FunctionPointer.c \
../Core/Src/JSONParseSimple.c \
../Core/Src/OpenWeatherData.c \
../Core/Src/STLogo.c \
../Core/Src/SkyWar.c \
../Core/Src/SkyWarGraphics.c \
../Core/Src/SoftwareTimers.c \
../Core/Src/WeatherApp.c \
../Core/Src/WeatherGraphics.c \
../Core/Src/calibrate.c \
../Core/Src/enemyPlane.c \
../Core/Src/font12.c \
../Core/Src/font16.c \
../Core/Src/font20.c \
../Core/Src/font24.c \
../Core/Src/font8.c \
../Core/Src/getDataJson.c \
../Core/Src/ili9341.c \
../Core/Src/json_parser.c \
../Core/Src/main.c \
../Core/Src/mainPlanes.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/touch.c 

C_DEPS += \
./Core/Src/Common.d \
./Core/Src/ControlApp.d \
./Core/Src/DateAndTime.d \
./Core/Src/FunctionPointer.d \
./Core/Src/JSONParseSimple.d \
./Core/Src/OpenWeatherData.d \
./Core/Src/STLogo.d \
./Core/Src/SkyWar.d \
./Core/Src/SkyWarGraphics.d \
./Core/Src/SoftwareTimers.d \
./Core/Src/WeatherApp.d \
./Core/Src/WeatherGraphics.d \
./Core/Src/calibrate.d \
./Core/Src/enemyPlane.d \
./Core/Src/font12.d \
./Core/Src/font16.d \
./Core/Src/font20.d \
./Core/Src/font24.d \
./Core/Src/font8.d \
./Core/Src/getDataJson.d \
./Core/Src/ili9341.d \
./Core/Src/json_parser.d \
./Core/Src/main.d \
./Core/Src/mainPlanes.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/touch.d 

OBJS += \
./Core/Src/Common.o \
./Core/Src/ControlApp.o \
./Core/Src/DateAndTime.o \
./Core/Src/FunctionPointer.o \
./Core/Src/JSONParseSimple.o \
./Core/Src/OpenWeatherData.o \
./Core/Src/STLogo.o \
./Core/Src/SkyWar.o \
./Core/Src/SkyWarGraphics.o \
./Core/Src/SoftwareTimers.o \
./Core/Src/WeatherApp.o \
./Core/Src/WeatherGraphics.o \
./Core/Src/calibrate.o \
./Core/Src/enemyPlane.o \
./Core/Src/font12.o \
./Core/Src/font16.o \
./Core/Src/font20.o \
./Core/Src/font24.o \
./Core/Src/font8.o \
./Core/Src/getDataJson.o \
./Core/Src/ili9341.o \
./Core/Src/json_parser.o \
./Core/Src/main.o \
./Core/Src/mainPlanes.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/touch.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -IC:/Users/LENOVO/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/LENOVO/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/LENOVO/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/LENOVO/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include -IC:/Users/hoang/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc -IC:/Users/hoang/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -IC:/Users/hoang/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include -IC:/Users/hoang/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include -I"C:/Users/MSI MODERN 14/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/MSI MODERN 14/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/MSI MODERN 14/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/MSI MODERN 14/STM32Cube/Repository/STM32Cube_FW_F4_V1.28.1/Drivers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/Common.cyclo ./Core/Src/Common.d ./Core/Src/Common.o ./Core/Src/Common.su ./Core/Src/ControlApp.cyclo ./Core/Src/ControlApp.d ./Core/Src/ControlApp.o ./Core/Src/ControlApp.su ./Core/Src/DateAndTime.cyclo ./Core/Src/DateAndTime.d ./Core/Src/DateAndTime.o ./Core/Src/DateAndTime.su ./Core/Src/FunctionPointer.cyclo ./Core/Src/FunctionPointer.d ./Core/Src/FunctionPointer.o ./Core/Src/FunctionPointer.su ./Core/Src/JSONParseSimple.cyclo ./Core/Src/JSONParseSimple.d ./Core/Src/JSONParseSimple.o ./Core/Src/JSONParseSimple.su ./Core/Src/OpenWeatherData.cyclo ./Core/Src/OpenWeatherData.d ./Core/Src/OpenWeatherData.o ./Core/Src/OpenWeatherData.su ./Core/Src/STLogo.cyclo ./Core/Src/STLogo.d ./Core/Src/STLogo.o ./Core/Src/STLogo.su ./Core/Src/SkyWar.cyclo ./Core/Src/SkyWar.d ./Core/Src/SkyWar.o ./Core/Src/SkyWar.su ./Core/Src/SkyWarGraphics.cyclo ./Core/Src/SkyWarGraphics.d ./Core/Src/SkyWarGraphics.o ./Core/Src/SkyWarGraphics.su ./Core/Src/SoftwareTimers.cyclo ./Core/Src/SoftwareTimers.d ./Core/Src/SoftwareTimers.o ./Core/Src/SoftwareTimers.su ./Core/Src/WeatherApp.cyclo ./Core/Src/WeatherApp.d ./Core/Src/WeatherApp.o ./Core/Src/WeatherApp.su ./Core/Src/WeatherGraphics.cyclo ./Core/Src/WeatherGraphics.d ./Core/Src/WeatherGraphics.o ./Core/Src/WeatherGraphics.su ./Core/Src/calibrate.cyclo ./Core/Src/calibrate.d ./Core/Src/calibrate.o ./Core/Src/calibrate.su ./Core/Src/enemyPlane.cyclo ./Core/Src/enemyPlane.d ./Core/Src/enemyPlane.o ./Core/Src/enemyPlane.su ./Core/Src/font12.cyclo ./Core/Src/font12.d ./Core/Src/font12.o ./Core/Src/font12.su ./Core/Src/font16.cyclo ./Core/Src/font16.d ./Core/Src/font16.o ./Core/Src/font16.su ./Core/Src/font20.cyclo ./Core/Src/font20.d ./Core/Src/font20.o ./Core/Src/font20.su ./Core/Src/font24.cyclo ./Core/Src/font24.d ./Core/Src/font24.o ./Core/Src/font24.su ./Core/Src/font8.cyclo ./Core/Src/font8.d ./Core/Src/font8.o ./Core/Src/font8.su ./Core/Src/getDataJson.cyclo ./Core/Src/getDataJson.d ./Core/Src/getDataJson.o ./Core/Src/getDataJson.su ./Core/Src/ili9341.cyclo ./Core/Src/ili9341.d ./Core/Src/ili9341.o ./Core/Src/ili9341.su ./Core/Src/json_parser.cyclo ./Core/Src/json_parser.d ./Core/Src/json_parser.o ./Core/Src/json_parser.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/mainPlanes.cyclo ./Core/Src/mainPlanes.d ./Core/Src/mainPlanes.o ./Core/Src/mainPlanes.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/touch.cyclo ./Core/Src/touch.d ./Core/Src/touch.o ./Core/Src/touch.su

.PHONY: clean-Core-2f-Src

