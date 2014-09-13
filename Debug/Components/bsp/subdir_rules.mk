################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
Components/bsp/bsp.obj: C:/Texas\ Instruments/SimpliciTI-CCS-1.1.1/Components/bsp/bsp.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/PRojects/ccsv6/tools/compiler/msp430_4.3.3/bin/cl430" --cmd_file="C:\Users\POKM\workspace_v6_0\HomeAutomation\smpl_config.dat" --cmd_file="C:\Users\POKM\workspace_v6_0\HomeAutomation\smpl_nwk_config.dat"  -vmsp --abi=eabi --include_path="C:/Texas Instruments/SimpliciTI-CCS-1.1.1/Components/bsp" --include_path="C:/Texas Instruments/SimpliciTI-CCS-1.1.1/Components/bsp/boards/EZ430RF" --include_path="C:/Texas Instruments/SimpliciTI-CCS-1.1.1/Components/bsp/drivers" --include_path="C:/Texas Instruments/SimpliciTI-CCS-1.1.1/Components/mrfi" --include_path="C:/Texas Instruments/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk" --include_path="C:/Texas Instruments/SimpliciTI-CCS-1.1.1/Components/simpliciti/nwk_applications" --include_path="C:/PRojects/ccsv6/ccs_base/msp430/include" --include_path="C:/PRojects/ccsv6/tools/compiler/msp430_4.3.3/include" --advice:power=all -g --define=__MSP430F2274__ --define=MRFI_CC2500 --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="Components/bsp/bsp.pp" --obj_directory="Components/bsp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


