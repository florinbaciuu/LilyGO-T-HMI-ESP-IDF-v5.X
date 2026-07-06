#pragma once
#ifndef COMMAND_LINE_INTERFACE_H_
#define COMMAND_LINE_INTERFACE_H_

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcpp"
#warning "Acest cod este scris de Florin Aurel Baciu"
#pragma GCC diagnostic pop

#include "config.h"

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "esp_system.h"
#include "esp_log.h"
#include "esp_console.h"
#include "linenoise/linenoise.h"
#include "argtable3/argtable3.h"
#include "driver/usb_serial_jtag.h"
#include "driver/usb_serial_jtag_vfs.h"

//=======================================================

#define MY_ESP_CONSOLE_CONFIG_DEFAULT() \
    {.max_cmdline_length = 256, .max_cmdline_args = 32, .heap_alloc_caps = MALLOC_CAP_DEFAULT, .hint_color = 39, .hint_bold = 0}

//=======================================================

extern char prompt[CONSOLE_PROMPT_MAX_LEN];

//=======================================================

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

//--------------------------------------------------------

// INITIALIZATION FUNCTIONS
void  initialize_console_peripheral(void);
void  initialize_console_library(const char* history_path);
char* setup_prompt(const char* prompt_str);

//--------------------------------------------------------

// register all commands
void cli_register_all_commands(void);
void cli_set_history_path(const char* path);
void start_cli_task();

//--------------------------------------------------------

#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */
#endif /* #ifndef COMMAND_LINE_INTERFACE_H_ */