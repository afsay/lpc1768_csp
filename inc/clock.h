#include <stdbool.h>

#include "system_control_register.h"

void main_oscillator_range_select(OSCRANGE oscrange);

void main_oscillator_enable(bool enable);

_Bool is_main_oscillator_enabled(void);

_Bool is_main_oscillator_ready(void);