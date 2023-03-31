
This is minimalized test code to show eeprom reading/writing.   

- This sets up a default value of 255 in the eeprom when eeprom is reset.   
- This value is then read from the eeprom and used to display green on the top row with red=0, green=user_config, blue=0   
- If you power cycle the board, the top row stays green as its reading 255 from the eeprom   
- When you press Fn1+Y it sets the user_config value to 0 effectively shutting off the top row LEDs. This new value is also saved to the eeprom.   
- If you power cycle the board now, the top row remains off.   
- reset the eeprom to get green back.   
 
