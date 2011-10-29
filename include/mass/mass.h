#ifndef _MASS_H_
#define _MASS_H_

#define DEBUG

#define RESULT_EXIST        0
#define RESULT_NOT_EXIST    1

#define EXECUTE_SUCCESS 0
#define EXECUTE_FAILED  1

#define RF_PLOAD_LEN 32
#define	RF_BUF_LEN RF_PLOAD_LEN
#define RF_BUF_STORE_DATA_START 5

#define ST_ADDR_HIGH 	2
#define ST_ADDR_LOW	 	3
#define ST_LEN			4
#define ST_VAL			5

#define BITMAP_LEN 30
/* Return the byte index of segment number in the bitmap */
#define BM_BYTE(segment_number) (segment_number / 8)
/* Return the bit index of segment number in the bitmap */
#define BM_BIT(segment_number) (segment_number % 8)

/* RF buffer */
struct radio_buffer {
	volatile unsigned char ready;
	unsigned char buffer[RF_BUF_LEN];
};

void get_data();
void set_data();
void get_ram();
void ret_char();
void ret_int();
void ret_long();
void ret_ptr();
void put_addr();
void ret_func();
void set_rfaddr();
void ret_bitmap();
void set_bitmap();
#endif
