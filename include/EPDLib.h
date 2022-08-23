#include "driver/spi_master.h"

struct EPDLibCFG{
    uint8_t scrHeight;
    uint8_t scrLenght;
    bool partialRefresh;
    uint8_t freqUpdate;
    uint8_t csGPIO; 
    uint8_t rstGPIO;
    uint8_t dcGPIO;
    uint8_t busyGPIO;
};

class EPDLib
{
    public:
        EPDLib(spi_device_handle_t *spi, EPDLibCFG *config);
        ~EPDLib();

        void init();
        void updateBuffer(uint8_t* buffer);
        void refreshScreen(uint8_t xInit, uint8_t xEnd, uint8_t yInit, uint8_t yEnd);
        void refreshScreen();
        void cleanScreen();
        void refreshType(bool partialRefresh);
        void sleep();
        
        
    private:
        EPDLibCFG config;
        
        bool validateConfig();
        void resetDev();
        bool sendData();
        bool recvData();
        void setLUT();
};