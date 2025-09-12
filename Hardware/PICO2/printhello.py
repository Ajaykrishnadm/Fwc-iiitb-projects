from machine import Pin
from time import sleep_ms

# Assign your pins (update if wiring is different)
RS = Pin(0, Pin.OUT)
EN = Pin(1, Pin.OUT)
D4 = Pin(2, Pin.OUT)
D5 = Pin(3, Pin.OUT)
D6 = Pin(4, Pin.OUT)
D7 = Pin(5, Pin.OUT)

# Helper functions
def pulse_enable():
    EN.value(0)
    sleep_ms(1)
    EN.value(1)
    sleep_ms(1)
    EN.value(0)
    sleep_ms(1)

def send_nibble(data):
    D4.value((data >> 0) & 1)
    D5.value((data >> 1) & 1)
    D6.value((data >> 2) & 1)
    D7.value((data >> 3) & 1)
    pulse_enable()

def send_byte(data, rs):
    RS.value(rs)
    send_nibble(data >> 4)   # High nibble
    send_nibble(data & 0x0F) # Low nibble
    sleep_ms(2)

def lcd_cmd(cmd):
    send_byte(cmd, 0)

def lcd_data(data):
    send_byte(data, 1)

def lcd_init():
    sleep_ms(20)
    lcd_cmd(0x33)  # Initialize
    lcd_cmd(0x32)  # Set to 4-bit mode
    lcd_cmd(0x28)  # 2 line, 5x7 matrix
    lcd_cmd(0x0C)  # Display ON, Cursor OFF
    lcd_cmd(0x06)  # Entry mode
    lcd_cmd(0x01)  # Clear display
    sleep_ms(5)

def lcd_print(msg):
    for ch in msg:
        lcd_data(ord(ch))

# --- Main program ---
lcd_init()
lcd_print("HELLO")
