# Led Driver

**Control para un conjunto de 16 leds controlados a través de un registro.**

---
## Requisitos

Los requisitos que debe cumplir este driver son los siguientes:

    1. El driver controlará el encendido/apagado de un conjunto de 16 leds
    2. El driver debe encender/apagar individualmente cada led, sin afectar el estado de los restantes
    3. El driver debe encender/apagar todos los leds
    4. El usuario del driver puede solicitar el estado (encendido/apagado) de cada led individualmente
    5. Al momento del encendido del sistema, por defecto, los leds deberán estar apagados
    6. El driver debe estar mapeado en una posición de memoria de 16 bits (en una posición determinada)
    7. Un “1” en la posición correspondiente a un led indica encendido, “0” apagado
    8. El bit menos significativo corresponde al led no1, el bit mas significativo al led no 16

---
## API

Las funciones disponibles para llevar a cabo las acciones son:

### · Create
Inicializa el registro de control de los leds

`ledDriver_create(uint16_t* ledsRegister)`

### · Led On
Enciende un led determinado

`ledDriver_led_on(uint16_t* ledsRegister, uint8_t ledNumber)`

### · Led Off
Apaga un led determinado

`ledDriver_led_off(uint16_t* ledsRegister, uint8_t ledNumber)`

### · All Leds On
Enciende todos los leds

`ledDriver_all_leds_on(uint16_t* ledsRegister)`

### · All Leds Off
Apaga todos los leds

`ledDriver_all_leds_off(uint16_t* ledsRegister)`

### · Get Led State
Devuelve el estado de un led determinado

`ledDriver_get_led_state(uint16_t ledsRegister, uint8_t ledNumber)`

---
## Testing
Se utiliza ceedling para los tests de las funcionalidades del driver. Simplemente correr:

`ceedling test:all`