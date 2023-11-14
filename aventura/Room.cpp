
#include "Room.h"
#include "Item.h"  // Add this line to include the Item header file
#include "Enemy.h" // Add this line to include the Enemy header file

Room::Room(const std::string& name, const std::string& description)
    : name(name), description(description) {}

const std::string& Room::getName() const {
    return name;
}

const std::string& Room::getDescription() const {
    return description;
}

void Room::addItem(const Item& item) {
    items.push_back(item);
}

void Room::removeItem(const std::string& itemName) {
    items.erase(std::remove_if(items.begin(), items.end(),
        [&](const Item& item) { return item.getName() == itemName; }),
        items.end());
}

const std::vector<Item>& Room::getItems() const {
    return items;
}

void Room::addEnemy(const Enemy& enemy) {
    enemies.push_back(enemy);
}

const std::vector<Enemy>& Room::getEnemies() const {
    return enemies;
}

void Room::describeRoomState() const {
    std::cout << "Estás en la habitación: " << name << "\n";
    std::cout << "Descripción: " << description << "\n";

    if (!items.empty()) {
        std::cout << "Puedes ver los siguientes ítems en la habitación:\n";
        for (const auto& item : items) {
            std::cout << "- " << item.getName() << ": " << item.getDescription() << "\n";
        }
    }

    if (!enemies.empty()) {
        std::cout << "¡Cuidado! Hay enemigos en la habitación:\n";
        for (const auto& enemy : enemies) {
            std::cout << "- " << enemy.getName() << " (Salud: " << enemy.getHealth() << ")\n";
        }
    }

    std::cout << "-----------------------------\n";
}

bool Room::isFinalRoom() const {
    // Choose either "Calabozo" or "Sala de tortura" based on your game logic
    return name == "Sala de tortura";
}
