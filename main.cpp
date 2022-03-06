#include "mbed.h"
#include <cstdio>


// I2C Interfaces

//I2C i2c(D14, D15);
I2C i2c(PB_14, PB_13);
char testArray[3];
// I2C slave address
//const char compasSlaveAddr = 0x30;
const int RWcompasSlaveAddr = 0x60;

int main()
{
    i2c.frequency(400000);
    for (int i = 0; i<256;i++) {
        //int rwbitVersion = i << 1;
        if (i2c.read(i, testArray,1) == 0){
            printf("0x%02x ACK\r\n",i);
        }
        else{
            printf("No Slave found with address 0x%x\n", i);
        }
    }

}
