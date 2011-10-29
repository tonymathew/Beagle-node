/* @file 
 * LE1 A/D converter driver
 *
 * @author Brian Yang <asdyaya@gmail.com>
 * 2009/02/19
 */

#ifndef EPL_ADC_H_
#define EPL_ADC_H_

#include <HAL/hal_adc.h>

/* ADCCON1 register */
#define	EPL_ADC_REF_INT		0x00
#define	EPL_ADC_REF_VDD		0x01
#define	EPL_ADC_REF_AIN3	0x02
#define	EPL_ADC_REF_AIN9	0x03
  
/* ADCCON3 register */
#define	EPL_ADC_RESOL_6		0x00
#define	EPL_ADC_RESOL_8		0x01
#define	EPL_ADC_RESOL_10	0x02
#define	EPL_ADC_RESOL_12	0x03

/* pins connected to the accelerometer */
#define	X_AXIS		0
#define	Y_AXIS		1
#define Z_AXIS		2

/** initialize A/D converter
 * @param ref internal or external reference voltage
 * @param resol A/D converter resolution 
 */
void epl_adc_init(char ref, char resol);

/** read the current data stored in A/D converter
 * @param in_pin select input channel
 * @return the data in ADC
 */
int epl_adc_read(char in_pin);

#endif /*EPL_ADC_H_*/
