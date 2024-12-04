# SFML and Visual Studio
- First, you must download the SFML SDK from the [download page](https://www.sfml-dev.org/download.php).
![image](https://github.com/user-attachments/assets/13abfba7-11ea-4c75-b7ad-1b21904a2074)
![image](https://github.com/user-attachments/assets/a263ee7a-65e9-4674-8646-0b6292e9c733)

#include <SFML/Graphics.hpp>
```cpp
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
```
