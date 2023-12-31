#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(800, 600), "Space");
    window.setFramerateLimit(60);


    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Blue);
    circle.setPosition(400, 300);

    float velocityX = 0.0f;
    float accelerationX = 0.1f;
    float friction = 0.02f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {

            if (velocityX > 0.0f) {
                velocityX -= friction;
            }
            else {

                velocityX -= accelerationX;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

            if (velocityX < 0.0f) {
                velocityX += friction;
            }
            else {

                velocityX += accelerationX;
            }
        }
        else {

            if (velocityX > 0.0f) {
                velocityX -= friction;
            }
            else if (velocityX < 0.0f) {
                velocityX += friction;
            }
        }

        circle.move(velocityX, 0);


        sf::Vector2f circlePosition = circle.getPosition();
        if (circlePosition.x < 0) {
            circle.setPosition(0, circlePosition.y);
            velocityX = 0;  
        }
        else if (circlePosition.x > window.getSize().x - circle.getRadius() * 2) {
            circle.setPosition(window.getSize().x - circle.getRadius() * 2, circlePosition.y);
            velocityX = 0;  
        }

        window.clear();

        window.draw(circle);

        window.display();
    }

    return 0;
}
