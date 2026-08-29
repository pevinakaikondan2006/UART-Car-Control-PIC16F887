 /*
 * Project : UART-Based Car Control System
 * MCU     : PIC16F887
 * Language: Embedded C
 * Tools   : MPLAB, Proteus
 *
 * Description:
 * Receives movement commands through UART and controls
 * motor direction using PIC16F887 GPIO outputs.
 * LCD displays the current vehicle status.
 */

#include <pic.h>

#define _XTAL_FREQ 4000000

__CONFIG(0x2CE4);

/* ---------- Utility Functions ---------- */

void delay(unsigned long int count)
{
    while (count--);
}

/* ---------- LCD Functions ---------- */

void lcd_enable(void)
{
    RE1 = 1;
    delay(10);
    RE1 = 0;
    delay(10);
}

void lcd_command(char command)
{
    RE0 = 0;
    PORTD = command;
    lcd_enable();
}

void lcd_data(char data)
{
    RE0 = 1;
    PORTD = data;
    lcd_enable();
}

void lcd_string(const char *text)
{
    while (*text)
    {
        lcd_data(*text++);
    }
}

void lcd_clear(void)
{
    lcd_command(0x01);
    delay(100);
}

/* ---------- Motor Control Functions ---------- */

void motor_stop(void)
{
    RC0 = 0;
    RC1 = 0;
    RC2 = 0;
    RC3 = 0;

    lcd_clear();
    lcd_command(0x80);
    lcd_string("STOP");
}

void motor_forward(void)
{
    RC0 = 1;
    RC1 = 0;
    RC2 = 1;
    RC3 = 0;

    lcd_clear();
    lcd_command(0x80);
    lcd_string("FORWARD");
}

void motor_reverse(void)
{
    RC0 = 0;
    RC1 = 1;
    RC2 = 0;
    RC3 = 1;

    lcd_clear();
    lcd_command(0x80);
    lcd_string("REVERSE");
}

void motor_right(void)
{
    RC0 = 0;
    RC1 = 1;
    RC2 = 1;
    RC3 = 0;

    lcd_clear();
    lcd_command(0x80);
    lcd_string("RIGHT");
}

void motor_left(void)
{
    RC0 = 1;
    RC1 = 0;
    RC2 = 0;
    RC3 = 1;

    lcd_clear();
    lcd_command(0x80);
    lcd_string("LEFT");
}

/* ---------- Main Program ---------- */

void main(void)
{
    char rx_data;

    /* Disable analog functions */
    ANSEL  = 0x00;
    ANSELH = 0x00;

    /* Configure I/O ports */
    TRISA = 0x3F;
    TRISC = 0x80;
    TRISD = 0x00;
    TRISE = 0x00;
    TRISB = 0x00;

    /* Clear output ports */
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    PORTD = 0x00;
    PORTE = 0x00;

    /* ---------- LCD Initialization ---------- */

    lcd_command(0x38);     // 8-bit, 2-line LCD
    lcd_command(0x0C);     // Display ON, cursor OFF
    lcd_command(0x01);     // Clear display
    delay(100);
    lcd_command(0x06);     // Increment cursor
    lcd_command(0x80);     // First line

    lcd_string("UART READY");

    /* ---------- UART Initialization ---------- */

    SPBRG = 25;

    TXSTA = 0x24;
    RCSTA = 0x90;

    delay(1000);

    lcd_clear();
    lcd_command(0x80);

    /* ---------- Main Control Loop ---------- */

    while (1)
    {
        /* Check whether UART data has been received */
        if (RCIF == 1)
        {
            rx_data = RCREG;

            /* Forward */
            if (rx_data == 'f' || rx_data == 'F')
            {
                motor_forward();
            }

            /* Reverse */
            else if (rx_data == 'R')
            {
                motor_reverse();
            }

            /* Right */
            else if (rx_data == 'r')
            {
                motor_right();
            }

            /* Left */
            else if (rx_data == 'l')
            {
                motor_left();
            }

            /* Stop */
            else if (rx_data == 's' || rx_data == 'S')
            {
                motor_stop();
            }
        }
    }
}