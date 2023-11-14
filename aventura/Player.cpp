#include "Enemy.h"
#include "Player.h"
#include "Item.h"  // Aseg�rate de incluir el archivo de encabezado de Item

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
    // Implementa la l�gica para manejar el �tem recogido
    // Por ejemplo, puedes agregar el �tem al inventario del jugador.
    // Tambi�n puedes realizar otras acciones relacionadas con la recogida del �tem.
    std::cout << "�Has recogido el �tem: " << item.getName() << "!" << std::endl;
}

void Player::attack(const Enemy& enemy) {
    // Implementa la l�gica para el ataque del jugador al enemigo
    // Puedes restar la salud del enemigo, manejar consecuencias, etc.
    std::cout << "Atacaste al enemigo: " << enemy.getName() << "!" << std::endl;
}
