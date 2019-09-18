################################################################################
# this is used for compile the wakaama
################################################################################
WAKAAMA_DIR = $(iot_link_root)/network/lwm2m/lwm2m_imp/wakaama
WAKAAMA_BASE_DIR = $(WAKAAMA_DIR)/wakaama-master

WAKAAMA_COAP_SRC = \
        ${wildcard $(WAKAAMA_BASE_DIR)/core/er-coap-13/er-coap-13.c}
        C_SOURCES += $(WAKAAMA_COAP_SRC)

WAKAMA_LWM2MSRC = \
        ${wildcard $(WAKAAMA_BASE_DIR)/core/*.c} \
        ${wildcard $(WAKAAMA_BASE_DIR)/examples/shared/*.c}
        C_SOURCES += $(WAKAMA_LWM2MSRC)
        
WAKAAMA_COAP_INC = \
        -I $(WAKAAMA_BASE_DIR)/core/er-coap-13
        C_INCLUDES += $(WAKAAMA_COAP_INC)
WAKAMA_LWM2MINC = \
        -I $(WAKAAMA_BASE_DIR)/core \
        -I $(WAKAAMA_BASE_DIR)/examples/shared
        C_INCLUDES += $(WAKAMA_LWM2MINC)        
       
C_DEFS += -D LWM2M_LITTLE_ENDIAN -D LWM2M_CLIENT_MODE -D LWM2M_WITH_LOGS
