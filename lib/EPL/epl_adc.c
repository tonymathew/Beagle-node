/** @file
 * Implementation of the A/D converter EPL module
 * @author: Brian Yang <asdyaya@gmail.com>
 */

#include <Nordic/reg24le1.h>
#include <EPL/epl_adc.h>

void epl_adc_init(char ref, char resol)
{
	hal_adc_set_reference(ref);
	hal_adc_set_input_mode(HAL_ADC_SINGLE);                             
	hal_adc_set_conversion_mode(HAL_ADC_SINGLE_STEP);
	hal_adc_set_resolution(resol);                          
	hal_adc_set_data_just(HAL_ADC_JUST_RIGHT); 
}

int epl_adc_read(char in_pin)
{
	int ret = 0;
	
	hal_adc_set_input_channel(in_pin);	/* set input pin */
	hal_adc_start();					/* Start ADconversion */                                                    
	while(hal_adc_busy());				/* Wait for data ready */

	ret = hal_adc_read_LSB();			/* read ADCDATAH/L register */
	ret += ((unsigned int)hal_adc_read_MSB()) << 8;
	
	return ret;
}
