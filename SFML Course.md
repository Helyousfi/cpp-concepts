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

## Bringing the window to life
- If you try to execute the code above with nothing in place of the "...", you will hardly see something. First, because the program ends immediately. Second, because there's no event handling -- so even if you added an endless loop to this code, you would see a dead window, unable to be moved, resized, or closed.
```cpp
#include <SFML/Window.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
```
## Playing with the window
- Of course, SFML allows you to play with your windows a bit. Basic window operations such as changing the size, position, title or icon are supported, but unlike dedicated GUI libraries (Qt, wxWidgets), SFML doesn't provide advanced features. SFML windows are only meant to provide an environment for OpenGL or SFML drawing.
```cpp
// change the position of the window (relatively to the desktop)
window.setPosition(sf::Vector2i(10, 50));

// change the size of the window
window.setSize(sf::Vector2u(640, 480));

// change the title of the window
window.setTitle("SFML window");

// get the size of the window
sf::Vector2u size = window.getSize();
unsigned int width = size.x;
unsigned int height = size.y;

// check whether the window has the focus
bool focus = window.hasFocus();

...
```
Refer to https://www.sfml-dev.org/documentation/2.6.1/classsf_1_1Window.php for more details!
## Controlling the framerate
Sometimes, when your application runs fast, you may notice visual artifacts such as tearing. The reason is that your application's refresh rate is not synchronized with the vertical frequency of the monitor, and as a result, the bottom of the previous frame is mixed with the top of the next one.
The solution to this problem is to activate vertical synchronization. It is automatically handled by the graphics card, and can easily be switched on and off with the setVerticalSyncEnabled function:
```cpp
window.setVerticalSyncEnabled(true); // call it once, after creating the window
```
After this call, your application will run at the same frequency as the monitor's refresh rate.
In other situations, you may also want your application to run at a given framerate, instead of the monitor's frequency. This can be done by calling setFramerateLimit: 
```cpp
window.setFramerateLimit(60); // call it once, after creating the window
```
# Events
Before dealing with events, it is important to understand what the sf::Event type is, and how to correctly use it. sf::Event is a union, which means that only one of its members is valid at a time (remember your C++ lesson: all the members of a union share the same memory space). The valid member is the one that matches the event type, for example event.key for a KeyPressed event. Trying to read any other member will result in an undefined behavior (most likely: random or invalid values). It is important to never try to use an event member that doesn't match its type.

sf::Event instances are filled by the pollEvent (or waitEvent) function of the sf::Window class. Only these two functions can produce valid events, any attempt to use an sf::Event which was not returned by successful call to pollEvent (or waitEvent) will result in the same undefined behavior that was mentioned above.

To be clear, here is what a typical event loop looks like:
```cpp
sf::Event event;

// while there are pending events...
while (window.pollEvent(event))
{
    // check the type of the event...
    switch (event.type)
    {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;

        // key pressed
        case sf::Event::KeyPressed:
            ...
            break;

        // we don't process other types of events
        default:
            break;
    }
}
```
## The Closed event
The sf::Event::Closed event is triggered when the user wants to close the window, through any of the possible methods the window manager provides ("close" button, keyboard shortcut, etc.). This event only represents a close request, the window is not yet closed when the event is received.

Typical code will just call window.close() in reaction to this event, to actually close the window. However, you may also want to do something else first, like saving the current application state or asking the user what to do. If you don't do anything, the window remains open.

There's no member associated with this event in the sf::Event union.
```cpp
if (event.type == sf::Event::Closed)
    window.close();
```
## The Resized event
```cpp
if (event.type == sf::Event::Resized)
{
    std::cout << "new width: " << event.size.width << std::endl;
    std::cout << "new height: " << event.size.height << std::endl;
}
```
## The LostFocus and GainedFocus events
The sf::Event::LostFocus and sf::Event::GainedFocus events are triggered when the window loses/gains focus, which happens when the user switches the currently active window. When the window is out of focus, it doesn't receive keyboard events.

This event can be used e.g. if you want to pause your game when the window is inactive.

There's no member associated with these events in the sf::Event union.
```cpp
if (event.type == sf::Event::LostFocus)
    myGame.pause();

if (event.type == sf::Event::GainedFocus)
    myGame.resume();
```
