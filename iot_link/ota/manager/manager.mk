################################################################################
# this is used for compile the pcp modules
################################################################################
MANAGER_MODULE_SRC  = ${wildcard $(iot_link_root)/ota/manager/*.c} 
C_SOURCES += $(MANAGER_MODULE_SRC)	
		
MANAGER_MODULE_INC = -I $(iot_link_root)/ota/manager
C_INCLUDES += $(MANAGER_MODULE_INC)

C_DEFS += -D CONFIG_MANAGER_ENABLE=1