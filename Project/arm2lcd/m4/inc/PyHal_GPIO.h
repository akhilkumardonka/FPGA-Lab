#ifndef PYHAL_GPIO_H_
#define PYHAL_GPIO_H_

#define FGPIO_DIRECTION_REG (0x40024008)
#define FGPIO_OUTPUT_REG (0x40024004)
#define FGPIO_INPUT_REG (0x40024000)
#define GPIO_OUTPUT_MODE (1)
#define GPIO_INPUT_MODE (0)

int PyHal_GPIO_Get(uint8_t gpionum);
int PyHal_GPIO_Set(uint8_t gpionum, uint8_t gpioval);
void PyHal_GPIO_SetDir(uint8_t gpionum,uint8_t iomode);
int PyHal_GPIO_GetDir(uint8_t gpionum);

#endif /* PYHAL_GPIO_H_ */