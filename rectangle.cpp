// 12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Windmill!");
	int i = 0;
	int j = 0;
	bool change=true;

	while (window.isOpen())
	{
		sf::RectangleShape shape;
		shape.setSize({ (90.f+3*j),(30.f+2*j) });//размер
		//shape.setRotation(i);//угол поворота
		shape.setPosition({ 400,400 });
		shape.setFillColor(sf::Color::Magenta);
		sf::CircleShape shape3(10.f+j );
		shape3.setFillColor(sf::Color::White);
		shape3.setPosition({ 390.f-j,390.f-j });


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (j < 80)
			{
				j++;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			j = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			change = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			change = false;
		}
		if (!change)
			shape.setRotation(i);//угол поворота
		else 
			shape.setRotation(0);//угол поворота
		window.draw(shape);
		window.draw(shape3);

		window.display();
		i++;
		
	}

	return 0;
}

