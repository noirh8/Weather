

#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#include "main.h"
#include "stm32f4xx_hal_conf.h"

typedef enum _Common_FlagState_e
{
    FLAG_RESET = 0,
    FLAG_SET = 1
}Common_FlagState_e;

void UnixTimeToHours(char *UinxTimestamp, char *OutputTime);
void UnixTimeToDate(char *UinxTimestamp, uint8_t *Day, uint8_t *DayWeek, uint8_t *Month, uint8_t *Year);
void Common_ArrayClean(char *Buffer, uint16_t BufferSize);

#endif /* INC_COMMON_H_ */
