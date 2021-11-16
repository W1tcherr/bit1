#include <iostream>
#include <bitset>

enum OBJECT_ATTRIBUTE : uint8_t
{
    DESTROYABLE = 1 << 0, // 0000 0001
    MOVABLE     = 1 << 1, // 0000 0010
    TRANSPARENT = 1 << 2, // 0000 0100
    IS_LIGHT    = 1 << 3, // 0000 1000
    HAS_SHADOWS = 1 << 4, // 0001 0000
    RESERVED_1  = 1 << 5, // 0010 0000
    RESERVED_2  = 1 << 6, // 0100 0000
    RESERVED_3  = 1 << 7  // 1000 0000
};

int main()
{
    uint8_t objectDescription = DESTROYABLE;
    objectDescription |= IS_LIGHT | MOVABLE; // присваивать обязательно через операцию или( |= ), что бы не затереть уже имеющиеся состояния.

    bool isDestroyable = objectDescription & DESTROYABLE; // проверка состояния у объекта
    bool isLight = objectDescription & IS_LIGHT;
    bool hasShadows = objectDescription & HAS_SHADOWS;
    std::cout << isDestroyable << std::endl;
    std::cout << isLight << std::endl;
    std::cout << hasShadows << std::endl;

    return 0;
}