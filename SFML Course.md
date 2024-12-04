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
# System module
## Handling time
A sf::Time value can be constructed from different source units: seconds, milliseconds and microseconds.
```cpp
sf::Time t1 = sf::microseconds(10000);
sf::Time t2 = sf::milliseconds(10);
sf::Time t3 = sf::seconds(0.01f);
```
Measuring time :
```cpp
sf::Clock clock; // starts the clock
...
sf::Time elapsed1 = clock.getElapsedTime();
std::cout << elapsed1.asSeconds() << std::endl;
clock.restart();
...
sf::Time elapsed2 = clock.getElapsedTime();
std::cout << elapsed2.asSeconds() << std::endl;
```
# Window module
Windows in SFML are defined by the sf::Window class. A window can be created and opened directly upon construction:
```cpp
#include <SFML/Window.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "My window");

    ...

    return 0;
}
```
- The first argument, the video mode, defines the size of the window (the inner size, without the title bar and borders). Here, we create a window with a size of 800x600 pixels.
- The second argument is simply the title of the window.
- This constructor accepts a third optional argument: a style, which allows you to choose which decorations and features you want.
![image](https://github.com/user-attachments/assets/7e3fffeb-4908-486e-803f-ffe8381c5b0b)

