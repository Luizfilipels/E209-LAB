#define motor1 (1<<PD0)  // Motor1 na PD0
#define motor2 (1<<PD1)  // Motor2 na PD1
#define motor3 (1<<PD2)  // Motor3 na PD2
#define botaoA (1<<PD3)  // BotaoA na PD3
#define botaoB (1<<PD4)  // BotaoB na PD4
#define botaoC (1<<PD5)  // BotaoC na PD5

int main(void) {
    // Definir saida
    DDRD |= motor1 | motor2 | motor3;
    // Definir pull-up
    PORTD |= botaoA | botaoB | botaoC;

    int totalp = 0;

    while (1) {
        if (!(PIND & botaoA)) {
            totalp += 30;
            PORTD |= motor1;
        }
        if (!(PIND & botaoB)) {
            totalp += 50;
            PORTD |= motor2;
        }
        if (!(PIND & botaoC)) {
            totalp += 70;
            PORTD |= motor3;
        }
        if (totalp > 90) {
            if(PIND & motor1 != 0){
              PORTD &= ~motor1;
              totalp -= 30;
            }
            if (totalp > 90 && (PIND & motor2 != 0)) {
                PORTD &= ~motor2;
                totalp -= 50;
            }
        }
    }
}
