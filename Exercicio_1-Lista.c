#define motor (1 << PD7)  // Definindo motor na PD7
#define sinal (1 << PD6) // Definindo sinal na PD6
#define botaoligar (1 << PD5)   // Botão ligar na PD5
#define botaodesligar (1 << PD4) // Botão desligar na PD4
#define sensor (1 << PD3)     // Sensor na PD3

int main() {
    // Definindo DDRD como saida ou entrada
    DDRD |= motor | sinal; // PD7 e PD6 como saida

    // pull-up nos botões
    PORTD |= botaoligar | botaodesligar;

    while (1) {
        if (PIND & sensor != 0) {  // Monte de peças detectado
            PORTD &= ~motor;  // Para o motor
            PORTD |= sinal;  // Liga o sinal
        }
        if ((!(PIND & botaoligar) == 0) && (!(PIND & sensor) == 0)) {  // Verifica se o botão ligar foi pressionado e não tem um monte de peças
              PORTD |= motor;  // Liga o motor
              PORTD &= ~sinal; // Desliga o sinal
        }
        if (!(PIND & botaodesligar) == 0) {  // Verifica se o botão desligar foi pressionado
            PORTD &= ~motor;  // Desliga o motor
        }
    }
}
