################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/TouchGFX_DataTransfer.c \
../Src/ili9341.c \
../Src/tm1630.c \
../Src/xpt2046.c 

C_DEPS += \
./Src/TouchGFX_DataTransfer.d \
./Src/ili9341.d \
./Src/tm1630.d \
./Src/xpt2046.d 

OBJS += \
./Src/TouchGFX_DataTransfer.o \
./Src/ili9341.o \
./Src/tm1630.o \
./Src/xpt2046.o 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -c -I../../Core/Inc -I../../TouchGFX/App -I../../TouchGFX/target/generated -I../../TouchGFX/target -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I"C:/Users/denjo/eeic/bdm-80/bdm-80-io/STM32CubeIDE/Include" -O2 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/TouchGFX_DataTransfer.d ./Src/TouchGFX_DataTransfer.o ./Src/ili9341.d ./Src/ili9341.o ./Src/tm1630.d ./Src/tm1630.o ./Src/xpt2046.d ./Src/xpt2046.o

.PHONY: clean-Src

