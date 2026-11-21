#include <iostream>
#include <string>

const char* MakeDisplayName(const std::string& name)
{
    std::string displayName = "Player_" + name;

    return displayName.c_str();
}

int main()
{
    const char* player1 = MakeDisplayName("Enoch");
    const char* player2 = MakeDisplayName("Minji");

    std::cout << player1 << '\n';
    std::cout << player2 << '\n';

    return 0;
}