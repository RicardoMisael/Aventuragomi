#include "Room.h"
#include "Item.h"
#include "Enemy.h"
#include "Game.h"
#include "Player.h"

int main() {
    std::string playerName;
    std::cout << "Bienvenido a la aventura Gomi.\n";
    std::cout << "Buena suerte en tu aventura!\n";
    std::cout << "Por favor, ingresa tu nombre: ";

    std::cin >> playerName;

    int initialHealth = 100;
    int initialLives = 3;

    Player player(playerName, 100, 3);

    Game adventure;

    Room* currentRoom = adventure.createRoom("Inicio", "El comienzo de tu aventura.");
    currentRoom->addItem(Item("Llave", "Abre un calabozo", Item::ItemType::KEY));

    currentRoom = adventure.createRoom("Sala de estar", "Una habitacion dañada oscura y con mucha humedad que ascoooo.");
    currentRoom->addEnemy(Enemy("zombie", 20, 5, 8));

    currentRoom = adventure.createRoom("Cocina", "Un lugar donde se preparan deliciosas comidas.");
    currentRoom->addEnemy(Enemy("arana", 30, 8, 10));

    currentRoom = adventure.createRoom("Habitacion principal", "El corazon de la casa, con una cama grande y comoda.");
    currentRoom->addItem(Item("Llave dorada", "Abre una puerta especial", Item::ItemType::KEY));
    currentRoom->addEnemy(Enemy("Fantasma", 25, 6, 10));

    currentRoom = adventure.createRoom("Sotano", "Un lugar oscuro y misterioso.");
    currentRoom->addEnemy(Enemy("Esqueleto", 35, 7, 10));

    currentRoom = adventure.createRoom("Sala de armas", "Llena de armas antiguas y herrumbrosas.");
    currentRoom->addEnemy(Enemy("Orco", 40, 9, 10));

    currentRoom = adventure.createRoom("Campo de tiro", "Donde se practica la punteria con arcos y flechas.");
    currentRoom->addItem(Item("Arco y flechas", "Un arma a distancia", Item::ItemType::WEAPON));

    currentRoom = adventure.createRoom("Calabozo", "Un lugar aterrador con celdas vacias.");
    currentRoom->addEnemy(Enemy("Jefe final", 100, 15, 20));

    std::cout << "Bienvenido, " << player.getName() << ", a la Aventura de Gomi!\n";

    while (true) {
        currentRoom->describeRoomState();

        if (currentRoom->isFinalRoom()) {
            std::cout << "Has llegado a la habitacion final! ¡Has escapado de la mansion!\n";
            std::cout << "Fin de la historia!\n";
            break;
        }

        std::cout <<
            "¿Que deseas hacer?\n"
            " 1. Explorar\n"
            "2. Recoger items\n"
            "3. Enfrentar enemigos\n"
            "4. Cambiar de habitacion\n"
            "5. Salir :\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Explorando...\n";
            currentRoom->describeRoomState();
            break;

        case 2:
            std::cout << "Recogiendo ítems...\n";
            if (!currentRoom->getItems().empty()) {
                std::cout << "Elige un ítem a recoger:\n";
                int index = 1;
                for (const auto& item : currentRoom->getItems()) {
                    std::cout << index << ". " << item.getName() << " - " << item.getDescription() << "\n";
                    index++;
                }
                int itemChoice;
                std::cin >> itemChoice;

                if (itemChoice >= 1 && itemChoice <= currentRoom->getItems().size()) {
                    player.pickUpItem(currentRoom->getItems()[itemChoice - 1]);
                    std::cout << "Has recogido " << currentRoom->getItems()[itemChoice - 1].getName() << "!\n";
                    currentRoom->removeItem(currentRoom->getItems()[itemChoice - 1].getName());
                }
                else {
                    std::cout << "Selección de item no válida.\n";
                }
            }
            else {
                std::cout << "No hay items en esta habitación.\n";
            }
            break;

        case 3:
            std::cout << "Enfrentando enemigos...\n";
            if (!currentRoom->getEnemies().empty()) {
                std::cout << "Elige un enemigo a atacar:\n";
                int index = 1;
                for (const auto& enemy : currentRoom->getEnemies()) {
                    std::cout << index << ". " << enemy.getName() << " (Salud: " << enemy.getHealth() << ")\n";
                    index++;
                }
                int enemyChoice;
                std::cin >> enemyChoice;

                if (enemyChoice >= 1 && enemyChoice <= currentRoom->getEnemies().size()) {
                    player.attack(currentRoom->getEnemies()[enemyChoice - 1]);

                    for (auto& enemy : currentRoom->getEnemies()) {
                        enemy.attack(player);
                    }
                }
                else {
                    std::cout << "Selección de enemigo no válida.\n";
                }
            }
            else {
                std::cout << "No hay enemigos en esta habitación.\n";
            }
            break;

        case 4:
            std::cout << "Cambiando de habitación...\n";
            currentRoom = adventure.changeRoom(currentRoom);
            break;
        case 5:
            std::cout << "Saliendo del juego. ¡Hasta luego!\n";
            return 0;
        default:
            std::cout << "Opcion no valida.\n";
        }
    }

    return 0;
}