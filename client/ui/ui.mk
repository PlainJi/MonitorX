UI_DIR_NAME ?= ui
#override CFLAGS := -I$(LVGL_DIR) $(CFLAGS)
CSRCS += $(wildcard $(LVGL_DIR)/$(UI_DIR_NAME)/*.c)
