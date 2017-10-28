#include "SFML/OpenGL.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "common/vector/Vector.h"
#include "common/physics/Strandbeest.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pierogi2D");
    common::physics::Strandbeest s;
    s.addJoint(common::vector::Vector2f(300.f, 300.f));
    s.addJoint(common::vector::Vector2f(500.f, 300.f));
    s.addJoint(common::vector::Vector2f(600.f, 500.f));
    s.addJoint(common::vector::Vector2f(200.f, 500.f));
    s.connect(0, 1);
    s.connect(1, 2);
    s.connect(2, 3);
    s.connect(3, 0);
    s.connect(0, 2);
    s.getLeg(0)->setEquilibriumLength(100.f);
    s.getFirstJoint(*s.getLeg(1))->setMass(10000.f);
    sf::Clock timer;
    sf::Clock renderTimer;
    while (window.isOpen())
    {
        float dt = timer.getElapsedTime().asSeconds();
        timer.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        s.updateBufferStep(dt);   
        s.updatePostBufferStep(dt);   
        s.updateVertexArray();
        if (renderTimer.getElapsedTime().asSeconds() > (1.f/30.f))
        {
            renderTimer.restart();

            window.clear(sf::Color::Black);
            window.draw(s);
            window.display();
        }
        
    }
    return 0;
}