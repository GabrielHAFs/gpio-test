#include <stdio.h>
#include <unistd.h>
#include <gpiod.h>
#include <string.h>

int main(int argc, char *argv[])
{
	const char *chipname = "gpiochip0";
	struct gpiod_chip *chip;
	struct gpiod_line *lineLED;
	struct gpiod_line *lineButton;
	int i = 0;
	bool toggle = 0;	

	// Open GPIO chiṕ
	chip = gpiod_chip_open_by_name(chipname);

	// Open GPIO lines
	lineLED = gpiod_chip_get_line(chip, 22);
	lineButton = gpiod_chip_get_line(chip, 23);

	// I/O definition
	gpiod_line_request_output(lineLED, "test", 0);
	gpiod_line_request_input(lineButton, "test");


	// Blink LEDs and stop if the button is pŕessed
	while (true)
	{
		toggle = !toggle;
		gpiod_line_set_value(lineLED,toggle);
		if (gpiod_line_get_value(lineButton) == 0) {
			break;
		}
	}
	
	return 0;
}