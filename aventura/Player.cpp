#include "Enemy.h"
#include "Player.h"
#include "Item.h"  // Asegúrate de incluir el archivo de encabezado de Item

Player::Player(const std::string& playerName, int initialHealth, int initialLives)
    : name(playerName), health(initialHealth), lives(initialLives) {
}

const std::string& Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getLives() const {
    return lives;
}

void Player::pickUpItem(const Item& item) {
    // Implementa la lógica para manejar el ítem recogido
    // Por ejemplo, puedes agregar el ítem al inventario del jugador.
    // También puedes realizar otras acciones relacionadas con la recogida del ítem.
    std::cout << "¡Has recogido el ítem: " << item.getName() << "!" << std::endl;
}

void Player::attack(const Enemy& enemy) {
    // Implementa la lógica para el ataque del jugador al enemigo
    // Puedes restar la salud del enemigo, manejar consecuencias, etc.
    std::cout << "Atacaste al enemigo: " << enemy.getName() << "!" << std::endl;
}
