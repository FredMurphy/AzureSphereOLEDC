#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#include <applibs/log.h>
#include <applibs/gpio.h>
#include "oledc_driver.h"
#include "fonts.h"
#include "pictures.h"

int ledFd = -1;

int gpio_init(void) {

	ledFd = GPIO_OpenAsOutput(9, GPIO_OutputMode_PushPull, GPIO_Value_High);
	if (ledFd < 0) {
		Log_Debug(
			"Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n",
			strerror(errno), errno);
		return -1;
	}

	return 0;
}

char* text1 = "Hello\0";
char* text2 = "this is the demo\0";
char* text3 = "for OLED C Click\0";

void shapes_demo(void);
void Delay_ms(long ms);


/*
Sample code for using the Click OLED C with the Avnet Azure Sphere Starter Kit
*/
int main(void)
{
	gpio_init();

	oledc_spiDriverInit((T_OLEDC_P)0, (T_OLEDC_P)0);
	oledc_init();
	oledc_fill_screen(0xFFFF);

	oledc_set_font(&guiFont_Tahoma_8_Regular[0], 0, _OLEDC_FO_HORIZONTAL);
	oledc_text(&text1[0], 15, 10);
	oledc_text(&text2[0], 5, 30);
	oledc_text(&text3[0], 5, 45);

	shapes_demo();

}

void shapes_demo()
{
	oledc_fill_screen(0xFFFF);
	Delay_ms(100);

	/* Rectangle demo*/
	oledc_rectangle(0, 0, 96, 96, 0xF000);
	Delay_ms(500);
	oledc_rectangle(5, 5, 91, 91, 0xFF00);
	Delay_ms(500);
	oledc_rectangle(10, 10, 86, 86, 0x00F0);
	Delay_ms(500);
	oledc_rectangle(15, 15, 81, 81, 0x0F0F);
	Delay_ms(500);
	oledc_rectangle(20, 20, 76, 76, 0xF000);
	Delay_ms(500);
	oledc_rectangle(25, 25, 71, 71, 0xFF00);
	Delay_ms(100);

	/* Line demo */
	oledc_rectangle(25, 25, 71, 27, 0);
	Delay_ms(100);
	oledc_rectangle(25, 71, 71, 73, 0);
	Delay_ms(100);
	oledc_rectangle(25, 25, 27, 71, 0);
	Delay_ms(100);
	oledc_rectangle(68, 25, 71, 71, 0);
	Delay_ms(900);


	/* Image demo */
	oledc_image(&me_logo_bmp[0], 0, 0);
	Delay_ms(900);
}

void Delay_ms(long ms) {
	struct timespec sleepTime = { 0, ms * 1000000 };
	nanosleep(&sleepTime, NULL);
}