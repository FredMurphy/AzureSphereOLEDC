# Sample code for using Click OLED-C boards with Avnet Azure Sphere Starter Kit
This is just intended as a way to get up and running quickly. It is an adaption of code supplied by MikroElektronica which can be found at https://github.com/MikroElektronika/OLED_C_click.git

The HAL implementation isn't quite a direct mapping of theirs. For instance the configuration is not paramaterized in the same way. The T-HAL_P parameters in _hal_gpioMap_ and _hal_spiMap_ are ignored.

