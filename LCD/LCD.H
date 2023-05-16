//. For example, the memory address for bit 7 (corresponding to the RS pin) is 0x40004200, 
//which is the base address plus an offset of 0x200 (since each bit in the register occupies 4 bytes or 32 bits).
#define LCD_RS (*((volatile unsigned long *)0x40004200))    //PA.7 for register select pin
#define LCD_EN  (*((volatile unsigned long *)0x40004100))   //PA.6 for enable pin
#define LCD_RW  (*((volatile unsigned long *)0x40004080))   //PA.5 for rw pin
#define clear_display     (0x01 << 3)   // Assuming Port D is used for control signals
#define returnHome        (0x02 << 3)   // Assuming Port D is used for control signals
#define moveCursorRight   (0x06 << 3)   // Assuming Port D is used for control signals
#define moveCursorLeft    (0x08 << 3)   // Assuming Port D is used for control signals
#define Shift_Cursor_Left (0x10 << 3)   // Assuming Port D is used for control signals
#define shiftDisplayRight (0x1C << 3)   // Assuming Port D is used for control signals
#define shiftDisplayLeft  (0x18 << 3)   // Assuming Port D is used for control signals
#define cursorBlink       (0x0F << 3)   // Assuming Port D is used for control signals
#define cursorOff         (0x0C << 3)   // Assuming Port D is used for control signals
#define cursorOn          (0x0E << 3)   // Assuming Port D is used for control signals
#define Function_set_4bit (0x28 << 3)   // Assuming Port D is used for control signals
#define Function_set_8bit (0x38 << 3)   // Assuming Port D is used for control signals
#define Entry_mode        (0x06 << 3)   // Assuming Port D is used for control signals
#define Function_8_bit    (0x32 << 3)   // Assuming Port D is used for control signals
#define Set5x7FontSize    (0x20 << 3)   // Assuming Port D is used for control signals
#define FirstRow          (0x80 << 3)   // Assuming Port D is used for control signals
#define SecondRow         (0xC0 << 3)   // Assuming Port D is used for control signalsvoid LCD_INIT(void);
void LCD_CMD(unsigned long cmd);
void LCD_WRITE (char data);
void SysTick_Wait_Timer(int delay);
void LCD_String(char *str);
void delay_milli(int i);
void delay_micro(int i);
