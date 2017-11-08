/** 
 * @file airpic-statusled.h
 * @brief  Status LED manager.
 * This library uses a common-cathode RGB LED to show system status. It is assumed 
 * that the relative brightness of each color is normalized by resistors. For the LED
 * used in testing, a good balance was found with a 200 Ohm resistor connecting to red, 
 * a 100 Ohm resistor connecting to green, and a 1000 Ohm resistor connecting to blue.
 * <p>
 * The LED is attached as follows:
 * <p><ul>
 * <li> Red is attached to RB15 (pin 26 of the PIC24FJ64GA002)
 * <li> Blue is attached to RB14 (pin 25 of the PIC24FJ64GA002)
 * <li> Green is attached to RB13 (pin 24 of the PIC24FJ64GA002)
 * </ul><p>
 * @author Evan Perry Grove
 * @date   November 7, 2017, 4:10 PM
 */

#ifndef AIRPIC_STATUSLED_H
#define	AIRPIC_STATUSLED_H

/** @brief Turn off status LED. */
#define STATUSLED_OFF           0x0001

/** @brief Status LED stays on, no blinking. */
#define STATUSLED_SOLID         0x0002

/** @brief Status LED stays on for a moment, then is off for a second. */
#define STATUSLED_SHORTBLINK    0x0000

/** @brief Status LED stays on for a second, then is off for a moment. */
#define STATUSLED_LONGBLINK     0x0003

/** @brief Status LED will be red. */
#define STATUSLED_RED           0x8000

/** @brief Status LED will be green. */
#define STATUSLED_GREEN         0x2000

/** @brief Status LED will be blue. */
#define STATUSLED_BLUE          0x4000

/** @brief Status LED will be orange. */
#define STATUSLED_ORANGE        0xA000

/** @brief Status LED will be teal. */
#define STATUSLED_TEAL          0x6000

/** @brief Status LED will be magenta. */
#define STATUSLED_MAGENTA       0xC000

#ifdef	__cplusplus
extern "C" {
#endif
    
    /**
     * Configure Timer2 to be used for the status LED. Immediately after 
     * /c enable_statusLED() is run, it will default to blue color and short
     * blinking pattern.
     */
    void enable_statusLED(void);
    
    /**
     * 
     * @param stat A value describing the color and blink pattern of the LED. 
     * Use the /c STATUSLED_ macros included in /c airpic-status.h combined 
     * together with bitwise OR.
     */
    void led_setStatus(unsigned int stat);

#ifdef	__cplusplus
}
#endif

#endif	/* AIRPIC_STATUSLED_H */
