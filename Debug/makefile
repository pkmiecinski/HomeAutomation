################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/PRojects/ccsv6/tools/compiler/msp430_4.3.3

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./helpers.obj" \
"./main_ap.obj" \
"./virtual_com_cmds.obj" \
"./Components/simpliciti/nwk_applications/nwk_freq.obj" \
"./Components/simpliciti/nwk_applications/nwk_ioctl.obj" \
"./Components/simpliciti/nwk_applications/nwk_join.obj" \
"./Components/simpliciti/nwk_applications/nwk_link.obj" \
"./Components/simpliciti/nwk_applications/nwk_mgmt.obj" \
"./Components/simpliciti/nwk_applications/nwk_ping.obj" \
"./Components/simpliciti/nwk_applications/nwk_security.obj" \
"./Components/simpliciti/nwk/nwk.obj" \
"./Components/simpliciti/nwk/nwk_QMgmt.obj" \
"./Components/simpliciti/nwk/nwk_api.obj" \
"./Components/simpliciti/nwk/nwk_frame.obj" \
"./Components/simpliciti/nwk/nwk_globals.obj" \
"./Components/mrfi/mrfi.obj" \
"./Components/bsp/bsp.obj" \
"../lnk_msp430f2274.cmd" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include Components/simpliciti/nwk_applications/subdir_vars.mk
-include Components/simpliciti/nwk/subdir_vars.mk
-include Components/mrfi/subdir_vars.mk
-include Components/bsp/subdir_vars.mk
-include subdir_rules.mk
-include Components/simpliciti/nwk_applications/subdir_rules.mk
-include Components/simpliciti/nwk/subdir_rules.mk
-include Components/mrfi/subdir_rules.mk
-include Components/bsp/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
TestSimpl.out \

EXE_OUTPUTS__QUOTED += \
"TestSimpl.out" \

BIN_OUTPUTS += \
TestSimpl.hex \

BIN_OUTPUTS__QUOTED += \
"TestSimpl.hex" \


# All Target
all: TestSimpl.out

# Tool invocations
TestSimpl.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"C:/PRojects/ccsv6/tools/compiler/msp430_4.3.3/bin/cl430" --cmd_file="C:\Users\POKM\workspace_v6_0\TestSimpl\smpl_config.dat" --cmd_file="C:\Users\POKM\workspace_v6_0\TestSimpl\smpl_nwk_config.dat"  -vmsp --abi=eabi --advice:power=all -g --define=__MSP430F2274__ --define=MRFI_CC2500 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal -z -m"TestSimpl.map" --heap_size=80 --stack_size=80 -i"C:/PRojects/ccsv6/ccs_base/msp430/include" -i"C:/PRojects/ccsv6/tools/compiler/msp430_4.3.3/lib" -i"C:/PRojects/ccsv6/tools/compiler/msp430_4.3.3/include" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="TestSimpl_linkInfo.xml" --rom_model -o "TestSimpl.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

TestSimpl.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP430 Hex Utility'
	"C:/PRojects/ccsv6/tools/compiler/msp430_4.3.3/bin/hex430" --memwidth=8 --romwidth=8 -o "TestSimpl.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "helpers.pp" "main_ap.pp" "virtual_com_cmds.pp" "Components\simpliciti\nwk_applications\nwk_freq.pp" "Components\simpliciti\nwk_applications\nwk_ioctl.pp" "Components\simpliciti\nwk_applications\nwk_join.pp" "Components\simpliciti\nwk_applications\nwk_link.pp" "Components\simpliciti\nwk_applications\nwk_mgmt.pp" "Components\simpliciti\nwk_applications\nwk_ping.pp" "Components\simpliciti\nwk_applications\nwk_security.pp" "Components\simpliciti\nwk\nwk.pp" "Components\simpliciti\nwk\nwk_QMgmt.pp" "Components\simpliciti\nwk\nwk_api.pp" "Components\simpliciti\nwk\nwk_frame.pp" "Components\simpliciti\nwk\nwk_globals.pp" "Components\mrfi\mrfi.pp" "Components\bsp\bsp.pp" 
	-$(RM) "helpers.obj" "main_ap.obj" "virtual_com_cmds.obj" "Components\simpliciti\nwk_applications\nwk_freq.obj" "Components\simpliciti\nwk_applications\nwk_ioctl.obj" "Components\simpliciti\nwk_applications\nwk_join.obj" "Components\simpliciti\nwk_applications\nwk_link.obj" "Components\simpliciti\nwk_applications\nwk_mgmt.obj" "Components\simpliciti\nwk_applications\nwk_ping.obj" "Components\simpliciti\nwk_applications\nwk_security.obj" "Components\simpliciti\nwk\nwk.obj" "Components\simpliciti\nwk\nwk_QMgmt.obj" "Components\simpliciti\nwk\nwk_api.obj" "Components\simpliciti\nwk\nwk_frame.obj" "Components\simpliciti\nwk\nwk_globals.obj" "Components\mrfi\mrfi.obj" "Components\bsp\bsp.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

